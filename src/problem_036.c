#include <stdio.h>
#include "problems.h"

void problem_036(void)
{
    printf("===== 第36题：求100之内的素数。 =====\n");
    // 在这里编写你的题目代码
    int n =100 ;
    int i,j;
    int k = 0;
    int arr[100];
    for ( i = 2 ; i <= n ; i++ ){
        int is_Prime = 1;
        for (j = 2 ; j * j <= i ; j++){
        /*
         * 尝试寻找 i 的因数。
         * 只需要检查到平方根 i。
         */
            if ( i % j == 0 ){
                is_Prime = 0;
                break;
            }
        }
          /*
         *如果循环不是因为找到因数而结束
         *说明i是素数
         */
            if ( is_Prime ){
                arr [k++] = i ;
            }
    }
    for ( i =0 ; i < k  ; i++ ){
        printf("%d ",arr [i]);
    }
    printf("\n");
} 
