#include <stdio.h>
#include "problems.h"

int count = 0; //全局变量

void reversePrint(int n){
    char ch ; // 用来存放当前读取的字符
    //递归出口(基本情况)
    if ( n == 0) {
        return ;
    }

    //读取当前字符 （注意 %c 前面的空格，用来跳过上次遗留的换行符）
    scanf (" %c",&ch); 
    reversePrint(n-1);
    //等递归全部回来后，再打印这个当前这个字符，此时后面的字符已经被打印了，所以ch自然而然的排在了后面
    count++;
    printf("第 %d次打印: %c\n",count,ch);
}
void problem_027(void)
{
    printf("===== 第27题：利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。 =====\n");
    // 在这里编写你的题目代码
    //：利用“系统栈”的后进先出（LIFO）特性，让递归函数的“回溯”阶段帮我们完成逆序输出。
    int n ;
    printf("请输入字符个数 n \n");
    scanf("%d",&n);
    printf("请输入 %d 个字符\n",n);
    reversePrint(n);
    printf("\n");
}
