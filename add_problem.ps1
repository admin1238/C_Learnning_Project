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

# 2. 头文件自动插入函数声明（防重复）
$declareMark = "// === AUTO_INSERT_DECLARE ==="
$declareLine = "void problem_$fullNum(void);"

$content = Get-Content -Path $hPath -Encoding UTF8
$declareExists = $content -match [regex]::Escape($declareLine)

if ($declareExists) {
    Write-Host "声明已存在，跳过插入" -ForegroundColor Yellow
} else {
    $newContent = foreach ($line in $content) {
        $line
        if ($line.Contains($declareMark)) {
            $declareLine
        }
    }

    Set-Content -Path $hPath -Value $newContent -Encoding UTF8
    Write-Host "头文件已插入声明：$declareLine"
}

# 3. 菜单自动新增选项（防重复）
$menuMark = "// === AUTO_INSERT_MENU ==="
$menuLine = "        printf(`"$numInt. 运行第${numInt}题：$name\n`");"

$content = Get-Content -Path $mainPath -Encoding UTF8
$menuExists = $content -match "printf\(\s*`"$numInt\."

if ($menuExists) {
    Write-Host "菜单项已存在，跳过插入" -ForegroundColor Yellow
} else {
    $newContent = foreach ($line in $content) {
        $line
        if ($line.Contains($menuMark)) {
            $menuLine
        }
    }

    Set-Content -Path $mainPath -Value $newContent -Encoding UTF8
    Write-Host "菜单已新增第 $numInt 题选项"
}

# 4. switch 自动新增 case 分支（防重复）
$caseMark = "// === AUTO_INSERT_CASE ==="
$caseLines = @"
            case ${numInt}:
                problem_$fullNum();
                break;
"@

$content = Get-Content -Path $mainPath -Encoding UTF8
$caseExists = $content -match "case\s+$numInt\s*:"

if ($caseExists) {
    Write-Host "Case 分支已存在，跳过插入" -ForegroundColor Yellow
} else {
    $newContent = foreach ($line in $content) {
        $line
        if ($line.Contains($caseMark)) {
            $caseLines
        }
    }

    Set-Content -Path $mainPath -Value $newContent -Encoding UTF8
    Write-Host "switch 已新增 case 分支"
}

Write-Host "`n全部操作完成！直接点 Build 编译即可使用。"
Read-Host "按回车退出"
