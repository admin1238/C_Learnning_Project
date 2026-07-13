#include <stdio.h>
#include "problems.h"

void problem_031(void)
{
    printf("===== 第31题：请输入星期几的第一个字母来判断一下是星期几，如果第一个字母一样，则继续判断第二个字母。 =====\n");
    // 在这里编写你的题目代码
    char c,d ;
    printf("请输入星期几的第一个字母\n");
    scanf("%c",&c);
    getchar();//scanf("%c",&j);的问题，第二次是读入的一个换行符，而不是输入的字符，因此需要加一个getchar() 吃掉换行符
    switch (c)
    {
    case 'm':
        printf("周一\n");
        break;
    case 'w':
        printf("周三\n");
        break;
    case 'f':
        printf("周五\n");
        break;
    case 't':
        printf("请输入下一个字母\n");
        scanf("%c",&d);
        if (d == 'u'){
            printf("周二\n");
        }
        if (d == 'h'){
            printf("周四\n");
        }
        break;
    case 's':
    printf("请输入下一个字母\n");
    scanf("%c",&d);
    if ( d == 'a'){
        printf("周六\n");
    }
    if ( d == 'u'){
        printf("周日\n");
    }    
        break;
    //输入字母不在范围内
    default:
    printf("输入字母不符合星期的首字母，请重新输入\n");
        break;
    }
}
