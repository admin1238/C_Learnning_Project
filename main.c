#include <stdio.h>
#include <stdlib.h>
#include "include/problems.h"

//打印菜单函数
void print_menu(void){
        printf("\n============C语言100题============\n");
        printf("1.运行第一题 4个数字排列不相同且无重复的三位数\n");
        printf("2.运行第二题 不同阶段下的奖金数\n");
        printf("3.运行第三题 求平方数\n");
        printf("4.运行第四题 求输入某年某月某日，判断这一天是这一年的第几天？\n");
        printf("5.运行第五题 求输入数？\n");
        printf("6.运行第六题 用*输出字母C的图案\n");
        printf("7.运行第七题 输出心形图案\n");
        printf("8.运行第八题 输出乘法口诀表\n");
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
            case 2:
                problem_002();
                break;
            case 3:
                problem_003();
                break;
            case 4:
                problem_004();
                break;
            case 5:
                problem_005();
                break;
            case 6:
                problem_006();
                break;
            case 7:
                problem_007();
                break;
            case 8:
                problem_008();
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