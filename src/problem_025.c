#include <stdio.h>
#include "problems.h"

void problem_025(void)
{
    printf("===== 第25题：求 1 + 2! + 3! + ... + 20! 的和。 =====\n");
    // 在这里编写你的题目代码
    int n ;
    long long sum = 0;      // ✅ 防溢出
    long long fact = 1;     // ✅ 用来存放当前的 i!
    printf("请输入项数\n");
    scanf("%d",&n);
    for (int i = 1 ;i <= n; i++){

        //for ( int j = 1 ; j <=i ; j++ ){
        //        a *= j ;
        //}
        //sum += a ;
        //a = 1 ;冗余
        fact *= i;
        sum += fact ;
    }
    //printf("和为 %d\n",sum);
    printf(" 1! + 2! + ... + %d! 的和 为 : %lld \n",n,sum);
}
