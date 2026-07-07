#include <stdio.h>
#include "problems.h"

// 有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。
//问第三个人，又说比第2人大两岁。问第2个人，说比第一个人大两岁。最后问第一个人，他说是10岁。
//请问第五个人多大？
int age ( int n){
    int c ;
    if ( n == 1){
       return 10;
    }
    else c = age (n -1) + 2 ;

}
void problem_028(void)
{
    printf("===== 第28题：递归实例 =====\n");
    // 在这里编写你的题目代码
    int n ,result = 0;
    printf ("请输入多少个人\n");
    scanf("%d",&n);
    result=age (n);
    printf("第%d个人是%d岁\n",n,result);
}
