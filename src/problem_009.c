#include<stdio.h>
#include"problems.h"

//输出国际象棋棋盘

void problem_009 (void){
    int i,j;
    for ( i = 0;i < 8; i++ ){
        for ( j =0; j < 8; j++){
            if( (i + j) % 2 == 0){
                // 偶数格：打印黑色方块（ASCILL码219） 黑色背景（40m） + 白色前景（37m），打印两个空格占位
                printf("\033[47m  \033[0m");
                 // 47m 是白色背景，\033[0m 是重置，防止影响后面  
            }
            else {
                //白色背景（47m）
                 printf("\033[40m  \033[0m");
                // 40m 是黑色背景
            }
        }
        printf("\n");
    }
}