#include <stdio.h>
#include "problems.h"
#include <math.h>
#define A 2.0f // X半对角线长
#define B 2.0f // y半对角线长
#define STEP 0.1f  // 坐标步长
#define EPS 1e-6  // 精度

//菱形标准方程：
void problem_023(void)
{
    printf("===== 第23题：打印菱形图案 =====\n");
    // 在这里编写你的题目代码
    // 计算整个循环点数 
    int total_x =(int) 2*A / STEP ;
    int total_y = (int) 2*B / STEP;
    // 外层：纵向循环，整数j从0到y_total
    for ( int j = 0; j <= total_y; j++){
        // 从 B线性递减到 -B
        float y = B - j * STEP;

        //内层：纵向循环，整数i从0到x_total
        for ( int i = 0 ; i <= total_x ; i++){
            // 从A线性递减到 -A 
            float x = A - i * STEP ;
              if (fabs(x)/A + fabs(y)/B <= 1.0f + EPS) {
                    printf("*");
                } else {
                    printf(" ");
                } 
        }
        printf("\n");
    }
}
