#include <stdio.h>
#include <stdbool.h>
#include "problems.h"

bool isPrime(int n){
    if ( n <= 1){
        return false ;
    }
    else if ( n == 2){
        return true;
    }
    else if ( n % 2 == 0){
        return false;
    }
    for ( int i =3 ; i*i <= n; i+=2 ){
        if ( n % i == 0){
            return false;
        } 
        // return true ; 这里是错误的，不能再犯
    }
     return true ;
}
void problem_012(void)
{
    printf("===== 第12题：判断101-200之间的素数 =====\n");
    int j,count=0;
    for ( j =101;j <= 200;j++){
        if (isPrime( j )){
            printf("%d\n",j);
            count++;
        }
    }
    printf("一共有 %d个素数\n",count);
}
