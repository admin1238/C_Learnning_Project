#include <stdio.h>
#include "problems.h"

void problem_017(void)
{
    printf("===== 第17题:输入一行字符,分别统计出其中英文字母,空格,数字和其它字符的个数。 =====\n");
    // 在这里编写你的题目代码
    char arr[100];
    int letter = 0, space = 0, digit = 0, other = 0;

    printf("请输入一行字符：\n");
    // ✅ 第一步：先吃掉缓冲区里遗留的第一个字符（即上次按回车留下的 \n）
    // 如果存在，getchar() 会立刻拿走它；如果不存在，程序才会停下来等你按一个键（但在你的场景下必定存在）
    getchar(); 
    fgets(arr, sizeof(arr), stdin);  // 读取一行，包括换行符

     // 统计逻辑（注意 fgets 会把换行符也存进数组，所以要排除 \n）
    for (int j = 0; arr[j] != '\0' && arr[j] != '\n'; j++) {
        if ((arr[j] >= 'a' && arr[j] <= 'z') || (arr[j] >= 'A' && arr[j] <= 'Z'))
            letter++;
        else if (arr[j] == ' ')
            space++;
        else if (arr[j] >= '0' && arr[j] <= '9')
            digit++;
        else
            other++;
    }

    printf("英文字母:%d\n空格:%d\n数字:%d\n其它:%d\n", letter, space, digit, other);
}

