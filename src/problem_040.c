#include <stdio.h>
#include "problems.h"

void problem_040(void)
{
    printf("===== 第40题：将一个数组逆序输出。 =====\n");
    // 在这里编写你的题目代码
    int *a ,*b;
    int arr[5]={1,2,3,4,5};
    printf("数组如下:\n");
    for (int i = 0 ;i < 5 ;i++){
        printf("%d",arr[i]);
    }
    a = &arr[0];
    b = &arr[4];

    while ( a < b ){
        int temp = *a ;
        *a = *b ;
        *b = temp;
        a++;
        b--;
    }
    printf("逆序后的数组:\n");

    for (int i = 0 ;i < 5 ;i++){
        printf("%d",arr[i]);
    }
}
