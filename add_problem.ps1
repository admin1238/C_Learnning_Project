$num = Read-Host "请输入题目编号（数字即可，例如 11）"
$name = Read-Host "请输入题目名称（例如 判断素数）"

if (-not ($num -match '^\d+$')) {
    Write-Error "编号必须为数字！"
    exit 1
}

$numInt = [int]$num
$fullNum = $numInt.ToString().PadLeft(3, '0')

$srcDir = "src"
$cPath = Join-Path $srcDir "problem_$fullNum.c"
$hPath = "include\problems.h"
$mainPath = "main.c"

if (-not (Test-Path -Path $srcDir -PathType Container)) {
    New-Item -Path $srcDir -ItemType Directory | Out-Null
}

# 1. 生成 src/problem_xxx.c 源文件
$cContent = @"
#include <stdio.h>
#include "problems.h"

void problem_$fullNum(void)
{
    printf("===== 第${numInt}题：$name =====\n");
    // 在这里编写你的题目代码
}
"@

$functionPattern = "void\s+problem_$fullNum\s*\(\s*void\s*\)"

if (Test-Path -Path $cPath) {
    $existingSource = Get-Content -Path $cPath -Raw -Encoding UTF8
    if ($existingSource -match $functionPattern) {
        Write-Host "源文件已存在，跳过生成：$cPath" -ForegroundColor Yellow
    } else {
        Add-Content -Path $cPath -Value "`n$cContent" -Encoding UTF8
        Write-Host "源文件已存在但缺少函数，已补充：problem_$fullNum"
    }
} else {
    Set-Content -Path $cPath -Value $cContent -Encoding UTF8
    Write-Host "已生成源文件：$cPath"
}

# 2. 头文件、菜单、switch 自动区域按题号排序写回
function Find-MarkerIndex {
    param(
        [string[]]$Content,
        [string]$Marker
    )

    for ($i = 0; $i -lt $Content.Count; $i++) {
        if ($Content[$i].Contains($Marker)) {
            return $i
        }
    }

    Write-Error "找不到自动插入标记：$Marker"
    exit 1
}

function Write-Lines {
    param(
        [string]$Path,
        [string[]]$Lines
    )

    Set-Content -Path $Path -Value $Lines -Encoding UTF8
}

function Update-DeclareBlock {
    param(
        [string]$Path,
        [int]$NewNumber
    )

    $marker = "// === AUTO_INSERT_DECLARE ==="
    $content = @(Get-Content -Path $Path -Encoding UTF8)
    $markerIndex = Find-MarkerIndex -Content $content -Marker $marker
    $start = $markerIndex + 1
    $end = $start
    $numbers = @()
    $allNumbers = @()

    foreach ($line in $content) {
        if ($line -match '^\s*void\s+problem_(\d{3})\s*\(\s*void\s*\)\s*;\s*$') {
            $allNumbers += [int]$Matches[1]
        }
    }

    while ($end -lt $content.Count) {
        if ($content[$end] -match '^\s*void\s+problem_(\d{3})\s*\(\s*void\s*\)\s*;\s*$') {
            $numbers += [int]$Matches[1]
            $end++
            continue
        }

        break
    }

    if ($allNumbers -notcontains $NewNumber) {
        $numbers += $NewNumber
    }

    $newContent = @()
    for ($i = 0; $i -le $markerIndex; $i++) {
        $newContent += $content[$i]
    }

    foreach ($number in ($numbers | Sort-Object -Unique)) {
        $newContent += ('void problem_{0:D3}(void);' -f $number)
    }

    for ($i = $end; $i -lt $content.Count; $i++) {
        $newContent += $content[$i]
    }

    Write-Lines -Path $Path -Lines $newContent
    Write-Host "头文件声明已按题号排序"
}

function Update-MenuBlock {
    param(
        [string]$Path,
        [int]$NewNumber,
        [string]$NewName
    )

    $marker = "// === AUTO_INSERT_MENU ==="
    $content = @(Get-Content -Path $Path -Encoding UTF8)
    $markerIndex = Find-MarkerIndex -Content $content -Marker $marker
    $start = $markerIndex + 1
    $end = $start
    $items = @{}
    $allNumbers = @()

    foreach ($line in $content) {
        if ($line -match '^\s*printf\("\s*(\d+)\.\s*运行第\d+题\s*(.*?)\\n"\);\s*$') {
            $allNumbers += [int]$Matches[1]
        }
    }

    while ($end -lt $content.Count) {
        if ($content[$end] -match '^\s*printf\("\s*(\d+)\.\s*运行第\d+题\s*(.*?)\\n"\);\s*$') {
            $items[[int]$Matches[1]] = $Matches[2].Trim()
            $end++
            continue
        }

        break
    }

    if ($allNumbers -notcontains $NewNumber) {
        $items[$NewNumber] = $NewName
    }

    $newContent = @()
    for ($i = 0; $i -le $markerIndex; $i++) {
        $newContent += $content[$i]
    }

    foreach ($number in ($items.Keys | Sort-Object)) {
        $newContent += ('        printf("{0}. 运行第{0}题 {1}\n");' -f $number, $items[$number])
    }

    for ($i = $end; $i -lt $content.Count; $i++) {
        $newContent += $content[$i]
    }

    Write-Lines -Path $Path -Lines $newContent
    Write-Host "菜单项已按题号排序"
}

function Update-CaseBlock {
    param(
        [string]$Path,
        [int]$NewNumber
    )

    $marker = "// === AUTO_INSERT_CASE ==="
    $content = @(Get-Content -Path $Path -Encoding UTF8)
    $markerIndex = Find-MarkerIndex -Content $content -Marker $marker
    $start = $markerIndex + 1
    $end = $start
    $numbers = @()
    $allNumbers = @()

    foreach ($line in $content) {
        if ($line -match '^\s*case\s+(\d+)\s*:\s*$') {
            $allNumbers += [int]$Matches[1]
        }
    }

    while ($end -lt $content.Count) {
        $caseMatch = [regex]::Match($content[$end], '^\s*case\s+(\d+)\s*:\s*$')
        if (
            $caseMatch.Success -and
            ($end + 2) -lt $content.Count -and
            $content[$end + 1] -match '^\s*problem_\d{3}\s*\(\s*\)\s*;\s*$' -and
            $content[$end + 2] -match '^\s*break\s*;\s*$'
        ) {
            $numbers += [int]$caseMatch.Groups[1].Value
            $end += 3
            continue
        }

        break
    }

    if ($allNumbers -notcontains $NewNumber) {
        $numbers += $NewNumber
    }

    $newContent = @()
    for ($i = 0; $i -le $markerIndex; $i++) {
        $newContent += $content[$i]
    }

    foreach ($number in ($numbers | Sort-Object -Unique)) {
        $newContent += ('            case {0}:' -f $number)
        $newContent += ('                problem_{0:D3}();' -f $number)
        $newContent += '                break;'
    }

    for ($i = $end; $i -lt $content.Count; $i++) {
        $newContent += $content[$i]
    }

    Write-Lines -Path $Path -Lines $newContent
    Write-Host "switch case 已按题号排序"
}

Update-DeclareBlock -Path $hPath -NewNumber $numInt
Update-MenuBlock -Path $mainPath -NewNumber $numInt -NewName $name
Update-CaseBlock -Path $mainPath -NewNumber $numInt

Write-Host "`n全部操作完成！直接点 Build 编译即可使用。"
Read-Host "按回车退出"
