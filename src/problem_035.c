#include <stdio.h>
#include "problems.h"
#include <string.h>
//函数017有同款问题，main函数 中 执行此问题时首先要输入数字表示题号然后按回车键，此时
//main函数中的scanf函数读取了数字，但是\n还残留在缓冲区内，fgets 读到\n后并将其存入数组，去掉换行符后 len =0 ,循环不执行 ，并且输出反转后的字符串（空串）
void problem_035(void)
{
    printf("===== 第35题：字符串反转，如将字符串 neighbour 反转为 roubhgien 。 =====\n");
    // 在这里编写你的题目代码
    char str [100];

     //  清空输入缓冲区（吃掉前面遗留的所有残留字符，直到遇到换行）
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { 
    // 这里只是不停地吃字符，不做任何事
    }
    
    printf("请输入一个字符或者字符串:");
    //scanf(" %s",str); // 这里不能包含空格，如果要有空格请用 fgets
    fgets(str, sizeof(str), stdin);
    //剔除末尾的换行符
    int len = strlen(str);
    if (len > 0 && str [len -1] == '\n'){
        str [len -1] ='\0';
        len-- ;
    }
    for ( int i = 0 , j = len-1 ; j > i;i++ ,j--){
        char temp = str [i];
        str [i] = str [j];
        str [j] = temp ;
    }
    printf("反转后的字符串为 %s\n",str);
}
