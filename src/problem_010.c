#include<stdio.h>
#include "problems.h"

void problem010 (void){
    int i , j ;
    for (i = 0; i < 12 ; i++){
        for (j = 0;j < i ; j++){
            printf("%c %c",219,219);
        }
        printf("\n");
    }
}