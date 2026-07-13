#include <stdio.h>
#include "problems.h"

void problem_033(void)
{
    printf("===== 第33题：判断一个数字是否为质数 =====\n");
    // 在这里编写你的题目代码
    int n ;
    printf("请输入一个数字\n");
    scanf("%d",&n);
    int is_prime = 1; // 标记位：1=是质数，0=不是质数，默认假设为质数
    if ( n <= 1){
        printf("%d不是质数\n",n);
        return ;
    }
    if ( n % 2 == 0){
        printf("%d不是质数\n",n);
    }
    for ( int i =3 ; i*i <= n ;i+2){
        if ( n % i ==0){
            is_prime = 0;
            break;
        }
    }
    if ( is_prime ){
        printf("%d是质数\n",n);
    }
    else {
        printf("%d不是质数\n",n);
    }
}
