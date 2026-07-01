#include <stdio.h>
#include "problems.h"

void problem_015(void)
{
    printf("===== 第15题：学习成绩分层展示 =====\n");
    // 在这里编写你的题目代码
    int score;
    char grade;
    printf("请输入分数:");
    scanf("%d",&score);
    grade =(score > 90)? 'A':((score > 60 || score < 89 )? 'B' : 'C');
    printf("等级为:%c \n",grade);
}
