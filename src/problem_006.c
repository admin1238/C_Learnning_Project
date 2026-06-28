#include <stdio.h>
#include "problems.h"

void problem_006 (void){
    int n=8;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            if (i == 0 || i == n || j == 0){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n"); //每行结束换行
    }
}