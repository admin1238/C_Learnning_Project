#include <stdio.h>
#include "problems.h"

void problem_024(void)
{
    printf("===== 第24题：有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...求出这个数列的前20项之和。 =====\n");
    // 在这里编写你的题目代码
    int n , t; 
    float sum = 0 ;
    float i = 1 ,j = 2;
    printf("请输入n的值\n");
    scanf("%d",&n);
    for ( int k = 1;k <= n;k++){
        sum += j/i;
        t = j ;
        j = i + j ;
        i = t ;
    }
    printf("%9.6f\n",sum); // 以固定 6 位小数输出浮点数，整个数字（含小数点、正负号）总共占 9 个字符宽度，不足则左侧补空格、整体右对齐。
}
