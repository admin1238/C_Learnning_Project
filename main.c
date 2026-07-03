#include <stdio.h>
#include <stdlib.h>
#include "include/problems.h"

//打印菜单函数
void print_menu(void){
        printf("\n============C语言100题============\n");
        printf("1. 运行第1题 4个数字排列不相同且无重复的三位数\n");
        printf("2. 运行第2题 不同阶段下的奖金数\n");
        printf("3. 运行第3题 求平方数\n");
        printf("4. 运行第4题 求输入某年某月某日，判断这一天是这一年的第几天？\n");
        printf("5. 运行第5题 求输入数？\n");
        printf("6. 运行第6题 用*输出字母C的图案\n");
        printf("7. 运行第7题 输出心形图案\n");
        printf("8. 运行第8题 输出乘法口诀表\n");
        printf("9. 运行第9题 输出国际象棋棋盘\n");
        printf("10. 运行第10题 输出 😊 楼梯\n");
        // === AUTO_INSERT_MENU ===   ← 加这一行，作为菜单插入位置
        printf("11. 运行第11题 兔子生崽问题(古典问题)\n");
        printf("12. 运行第12题 判断101-200之间的素数\n");
        printf("13. 运行第13题 输出水仙花数\n");
        printf("14. 运行第14题 将一个正整数分解质因数\n");
        printf("15. 运行第15题 学习成绩分层展示\n");
        printf("16. 运行第16题 求最大公倍数和最大公因数\n");
        printf("17. 运行第17题 输入一行字符,分别统计出其中英文字母,空格,数字和其它字符的个数。\n");
        printf("18. 运行第18题 求 s=a+aa+aaa+aaaa+aa...a 的值，其中 a 是一个数字，例如 2+22+222+2222+22222 (此时共有5个数相加)\n");
        printf("19. 运行第19题 一个数如果恰好等于它的因子之和，这个数就称为完数，例如 6=1＋2＋3 ，请编程找出 1000 以内的所有完数\n");
        printf("20. 运行第20题 小球自由下落\n");

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
            case 9:
                problem_009();
                break;
            case 10:
                problem_010();
                break;
            // === AUTO_INSERT_CASE ===   ← 加这一行，作为case插入位置
            case 11:
                problem_011();
                break;
            case 12:
                problem_012();
                break;
            case 13:
                problem_013();
                break;
            case 14:
                problem_014();
                break;
            case 15:
                problem_015();
                break;
            case 16:
                problem_016();
                break;
            case 17:
                problem_017();
                break;
            case 18:
                problem_018();
                break;
            case 19:
                problem_019();
                break;
            case 20:
                problem_020();
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
