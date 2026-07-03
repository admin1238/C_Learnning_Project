#include <stdio.h>
#include "problems.h"

void problem_018(void)
{
    printf("===== 第18题：求 s=a+aa+aaa+aaaa+aa...a 的值，其中 a 是一个数字，例如 2+22+222+2222+22222 (此时共有5个数相加) =====\n");
    // 在这里编写你的题目代码
    int i,n ;
    long long term=0,sum=0;
    printf("请输入相加的数字如 s=3+33,这里i=3\n");
    scanf("%d",&i);
    printf("请输入相加的个数:\n");
    scanf("%d",&n);
    for (int b = 1; i <= n; i++) {
        term = term * 10 + i;  // 核心递推：前一项 * 10 + a
        sum += term;           // 累加到总和

        printf("第%d项 = %lld, 当前总和 = %lld\n", i, term, sum);
    }

    printf("\n最终结果 s = %lld\n", sum);
}

