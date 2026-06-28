#include<stdio.h>
#include"problems.h"

// 打印乘法口诀 正序版

void problem_008 (void){
    int i,j,result;
    for (i =1;i<=9;i++){
        for (j=1;j<=i;j++){
            result=i*j;
            printf("%d * %d = %d ",i,j,result);
        }
        printf("\n");
    }
}