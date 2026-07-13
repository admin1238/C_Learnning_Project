#include <stdio.h>
#include "problems.h"
#define N  3 // 不同阶矩阵
void problem_038(void)
{
    printf("===== 第38题：求一个3*3矩阵对角线元素之和 =====\n");
    // 在这里编写你的题目代码
    int i,j;
    int a[N][N];
    int sum =0 ;
    for (i=0 ; i < N ; i++){
        for (j = 0; j < N; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 0; i < N; i++){
        sum += a[i][i];
    }
    printf("对角线之和为: %d\n",sum);
}
