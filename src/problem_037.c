#include <stdio.h>
#include "problems.h"
// 冒泡排序 + 快速排序+选择排序
void bubble_sort(int arr[],int n){
    int temp ;
    
    for (int i = 0 ; i < n - 1;i++){

        for (int j = 0 ; j <= n-1-i ; j++){
            if(arr [j] >arr [j+1]){
                temp = arr [j] ;
                arr [j] = arr [j+1];
                arr [j+1]= temp ;
            }
        }
    }
}
void selection_sort (int arr[],int n){
    int minIndex ;
    int temp ;

    for (int i = 0; i < n-1; i++)
    {
         minIndex = i ;

        for (int j = i+1; j < n ; j++)
        {
            if ( arr[minIndex] > arr[j])
            {
                minIndex = j ;
            }
        }
        if ( minIndex != i ){
            temp = arr[minIndex];
            arr [minIndex] = arr[i];
            arr [i] = temp ;
        }
        
    } 
}
int partition (int arr [],int low , int high){
    int pivot =arr [high] ;
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if ( arr[j] <= pivot){

            i++;
            int temp = arr [i] ;
            arr [i] = arr [j] ;
            arr [j] = temp ;
        }
    }
    int temp =arr [i+1];
    arr [i+1] = pivot;
    pivot = temp ;

    return i+1 ;
}
void quick_sort (int arr [],int low , int high)
{
    if (low < high){
        int pivotIndex =  partition (arr,low,high);
        quick_sort (arr,low,pivotIndex-1);
        quick_sort(arr,pivotIndex+1,high);
    }
}
void problem_037(void)
{
    printf("===== 第37题：对10个数进行排序。 =====\n");
    // 在这里编写你的题目代码
    int arr1 [] = { 5,3,6,8,11,15,2,4,7,10 };
    int arr2 [] = { 5,3,6,8,11,15,2,4,7,10 };
    int arr3 [] = { 5,3,6,8,11,15,2,4,7,10 };
    int n = sizeof (arr1) / sizeof (arr1[0]) ;

    bubble_sort( arr1 , n);
    printf("冒泡排序结果：");
    for (int i =0;i<n;i++){
        printf("%d",arr1[i]);
    }

    selection_sort (arr2 , n);
    printf("选择排序结果：");
    for (int i =0;i<n;i++){
        printf("%d",arr2[i]);
    }

    quick_sort(arr3 ,0,n-1);
    printf("快速排序结果：");
    for (int i =0;i<n;i++){
        printf("%d",arr2[i]);
    }
}

