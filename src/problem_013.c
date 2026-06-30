#include <stdio.h>
#include "problems.h"

//打印出所有的"水仙花数"
//所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。

void problem_013(void)
{
    printf("===== 第13题：输出水仙花数 =====\n");
    int i,j,k,num;
    for (num = 100 ; num < 1000; num++){
        i = (num / 100 ) ; // 百位
        j = (num / 10) % 10 ; // 十位
        k = num % 10;         // 个位
        
        //计算立方和
        int sum = i*i*i + j*j*j + k*k*k;

        if (num == sum ){
            printf("%d",num);
        }
    }

}
