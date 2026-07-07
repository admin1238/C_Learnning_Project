#include <stdio.h>
#include "problems.h"
long long  factorial (int n ) {
    long long  result = 0 ;
    if ( n == 0 || n == 1){
        result = 1 ;
    }
    else result = n * factorial(n -1);
}

void problem_026(void)
{
    printf("===== 第26题：利用递归方法求 5! =====\n");
    // 在这里编写你的题目代码
    int n ;
    printf("请输入n的值\n");
    scanf("%d",&n);
    printf("%d!的值为:%d \n",n,factorial (n));
}
