#include<stdio.h>
#include"problems.h"
// 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？

void problem_003 (void){
        int target = 168 ;
        for ( int i =1 ; i*i < target ; i++){
            if( target % i == 0){
                int j = target / i ;
                        
                if (( i + j ) % 2 == 0){
                    int m = ( i + j ) / 2 ;
                    int n = ( i - j ) / 2 ;
                    int x = m * m -268 ;
                    printf("该数为:%d\n", x);
                }
            }
        }
}