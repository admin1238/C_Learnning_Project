#include <stdio.h>
#include "problems.h"

//两个乒乓球队进行比赛，各出三人，甲队为 a、b、c 三人，乙队为 x、y、z 三人。
//抽签决定比赛名单，有人向队员打听比赛的名单：a 说他不和 x 比，c 说他不和 x、z 比，
//请编写代码找出三队赛手的名单。

void problem_022(void)
{
    printf("===== 第22题：乒乓球队进行比赛求赛手名单 =====\n");
    // 在这里编写你的题目代码
    char a ,b ,c ; //代表甲队 a的对手  b的对手 ， c的对手   
    char opponent[3]={'x','y','z'}; //对手列表

    for (int i =0;i<3;i++){
        a=opponent[i];

        for(int j = 0;j < 3; j++){
           b =opponent[j] ;

            for (int k = 0;k<3;k++){
                c = opponent[k];
                if (a == b || a == c || b == c ){
                    continue ;
                }

                if ( a !='x' && c !='x' && c !='z'){
                    printf("a的对手是%c\n",a);
                    printf("b的对手是%c\n",b);
                    printf("c的对手是%c\n",c);
                }
            }
        }
    }
}   

        

