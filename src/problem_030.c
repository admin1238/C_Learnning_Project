#include <stdio.h>
#include "problems.h"

void problem_030(void)
{
    printf("===== 第30题：一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。 =====\n");
    // 在这里编写你的题目代码
    char str [5];
    printf("请输入5位数:");
    scanf("%s",str);
    if (str[4]==str[0]&&str[3]==str[1]){
        printf("这是一个回文数\n");
    }
    else {
        printf("这不是一个回文数\n");
    }
}
