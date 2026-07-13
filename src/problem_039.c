#include <stdio.h>
#include "problems.h"

void problem_039(void)
{
    printf("===== 第39题：有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中。 =====\n");
    // 在这里编写你的题目代码
    int a ;
    int arr [5] = {5,3,2,1,4};
    int n = sizeof (arr) / sizeof (arr [0]);
    bubble_sort (arr , n);
    printf("排好序的数组为:");
    for (int i =0 ;i < n ; i++){
        printf("%d",arr[i]);
    }
    printf("请输入一个数");
    scanf ("%d",&a);
    if ( arr[n-1]< a) {
        arr[n] = a ; 
    }
    else {
        for ( int i = 0; i < n; i++){
            if ( arr[i] > a){
                int temp1 = arr [i];
                arr [i] = a ;
                
                for (int  j = i+1; j < n+1; j++)
                {
                    int temp2 = arr [j];
                    arr[j] = temp1;
                    temp1 = temp2 ;
                }
            break; //找到就停
            }
        }
    }
    for (int i = 0; i < n+1; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}
