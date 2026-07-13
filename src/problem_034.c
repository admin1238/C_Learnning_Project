#include <stdio.h>
#include "problems.h"

void problem_034(void)
{
    printf("===== 第34题：练习函数调用 =====\n");
    // 在这里编写你的题目代码
     int year,month,day;
    int totalDays;
    int dayInMonth[] ={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("请输入具体年月日,请用空格分离\n");
    scanf("%d%d%d",&year,&month,&day);
    if ( isLeapYear(year)){
        dayInMonth[1]=29; //闰年有29天
    }

    for ( int i=0 ;i< month -1 ;i++ ){
        totalDays += dayInMonth[i];
    }
    totalDays +=day;
    printf("%d年%d月%d日是该年的第%d天\n",year,month,day,totalDays);
}
