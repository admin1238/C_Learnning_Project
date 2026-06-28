#include<stdio.h>
#include"problems.h"

//输入某年某月某日，判断这一天是这一年的第几天？
int isLeapYear (int year){
    if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
        return 1;
    }
    return 0;
}

void problem_004 (void){
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