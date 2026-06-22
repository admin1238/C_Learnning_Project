//题目 有 1、2、3、4 四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少
#include<stdio.h>
#include "problems.h"

void problem_001 (void){
    int used[5]={0,0,0,0,0};//下标1-4对应数字1-4 0=未用，1=启用
    int count=0;            //统计组成了多少个三位数

    for(int i=1;i<=4;i++){
        if( used[i] == 0){
            used[i] = 1; //这里used[i]==1是错误的，这个只是一个判断值，对程序运行并没有任何的作用

            for (int j = 1; j <= 4; j++){
                if (used[j] == 0){
                    used[j] = 1;

                    for (int k = 1; k <= 4; k++ ){
                        if (used [k] == 0){
                            count++;
                            printf("%d%d%d\n",i,j,k);
                        }
                    }
                    used[j] =0;
                }
            }
             used[i] =0;
        }
    }
    printf("一共有 %d 个三位数\n",count);
}


