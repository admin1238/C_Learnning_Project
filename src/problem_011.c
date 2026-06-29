#include<stdio.h>
#include "problems.h"

// 有一对兔子，从出生后第3个月起每个月都生一对兔子，
// 小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，
// 问每个月的兔子总数为多少？（输出前40个月即可）
// 

void problem_011 (void){
    int i ,month;
    long long f1 = 1,f2 = 1, f3 ;
    // f1 代表上上月的兔子总数，f2 代表上月的兔子总数 ，f3代表这个月的兔子数

    printf("请输入月份: ");
    scanf("%d", &month);
    if ( month == 1 || month == 2){
        printf("第%d个月的兔子总数为1对兔子",month);
    }
    for (i = 3;i <= month;i++){
        f3 = f1 + f2 ; // 本月 = 上上月的兔子总数（新生兔） + 上月的兔子总数
        f1 = f2 ;      // 偏移，上上月往前移
        f2 = f3 ;       // 上月往前移
        printf("第%d个月的兔子总数为%d对兔子\n",i,f3);
    }
}