#include<stdio.h>
#include"problems.h"

//输入三个整数 x、y、z，请把这三个数由小到大输出。
//不把数据当独立变量，而是放入“数组”容器

void problem_005 (void){
    int a[3],temp,i,j;
    int n=3;
    printf("请依次输入3个数\n");
    for (i=0;i<=2;i++){
        scanf("%d",&a[i]);
    }

    //冒泡排序思维，升序排法
    for (i=0;i<=n-1;i++){
        for(j=0;j<n-i;j++){
            if (a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("%d %d %d",a[0],a[1],a[2]);
}