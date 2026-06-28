#include<stdio.h>
#include<math.h>
#include "problems.h"

void problem_007 (void){
    float x,y;

    //外层循环 Y轴 步长0.1 共30行
    for (y = 1.5f ;y > -1.5f ; y-=0.1f){

        //内层循环 X轴 步长0.05 共 80列
        for (x = -2.0f; x < 2.0f; x+=0.05f){

            //心形线的标准方程
            float f =x * x + y * y - 1;

            //判断 点是否在心形内部 （ <=0 表示在图形内部或者边界上）
             if (f * f * f - x * x * y * y * y <= 0.0f) {
                printf("*");
            } 
            else {
                printf(" "); // 打印空格占位
            }
        }
        printf("\n"); // 打印空格占位 
    }
}