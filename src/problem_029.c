#include <stdio.h>
#include "problems.h"

void problem_029(void)
{
    printf("===== 第29题：输入一个整数，要求：一、求它是几位数，二、逆序打印出各位数 =====\n");
    // 在这里编写你的题目代码
    int n ,digit,temp =0;
    int count = 0;
    printf("请输入一个整数\n");
    scanf("%d",&n);
    if (n < 0){
        printf("该数为负数，逆序为：-");
        temp = -n ;
    }
    else {
        temp = n ;
    }
    printf ("逆序打印出各位数如下：\n");
    do {
        digit = temp % 10 ;
        printf("%d",digit);
        temp = temp / 10 ;
        count++;
    }
    while (temp > 0);
    printf("\n共有%d位数\n",count);
}
