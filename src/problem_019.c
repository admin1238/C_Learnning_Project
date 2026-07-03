#include <stdio.h>
#include <string.h> // 用来计算字符串的长度
#include "problems.h"

void problem_019(void)
{
    printf("===== 第19题：一个数如果恰好等于它的因子之和，这个数就称为完数，例如 6=1＋2＋3 ，请编程找出 1000 以内的所有完数 =====\n");
    // 在这里编写你的题目代码
 int i, j, sum;
    
    for (i = 1; i <= 1000; i++) {
        sum = 0;
        char buffer[256] = "";   // 用来存放 "1 + 2 + 3" 这样的字符串

        // 唯一的循环：找因子，求和，同时拼接字符串
        for (j = 1; j < i; j++) {
            if (i % j == 0) {
                sum += j;
                
                // 核心技巧：把因子拼进字符串
                if (strlen(buffer) == 0) {
                    sprintf(buffer, "%d", j);   // 第一个因子直接写
                } else {
                    sprintf(buffer + strlen(buffer), " + %d", j); // 后面的加个 " + " 再写
                }
            }
        }

        // 循环结束后，sum 和 buffer 都已经准备好了
        if (sum == i && i != 1) {  // 1不是完全数，顺手排除
            printf("%d=%s\n", i, buffer);
        }
    }
}
