#include<stdio.h>
#include <stdlib.h>
#include "include/problems.h"

//打印菜单函数
void print_menu(void){
        printf("\n============C语言100题============\n");
        printf("1.运行第一题 4个数字排列不相同且无重复的三位数\n");

        printf("0.退出程序\n");
        printf("\n=================================\n");
}

int main(){
    int select; //定义一个变量存储用户输入的数字

    while(1){
        print_menu();
        printf("请输入对应题号：");
        scanf("%d",&select);

        //根据输入匹配题目
        switch(select) {
            case 1:
                problem_001();
                break;

            case 0:
                printf("程序即将退出，再见\n");
                return 0;//结束main，退出整个程序
            default:
            //输入数字不在范围内
            printf("输入错误！暂无该题号,请重新输入：\n");
            break;
        }
        //每道题运行完毕后停断一下查看结果
        printf("按回车键返回菜单...");
        getchar();//吸收回车
        getchar();//吸收按键
        system("cls"); //windows清屏
    }
}