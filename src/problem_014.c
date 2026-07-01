#include <stdio.h>
#include "problems.h"

void problem_014(void)
{
    printf("===== 第14题：将一个正整数分解质因数 =====\n");
    // 在这里编写你的题目代码
    int i, n ;
    printf("请输入一个正整数\n");
    scanf("%d",&n);
    for (i = 2;i <= n;i++ ){
        while (n % i == 0){
            printf("%d",i);
            n = n / i ;
            if (n !=1){
                printf("*");
            }
        }
    }
    printf("\n");
}
