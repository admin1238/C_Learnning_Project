#include <stdio.h>
#include "problems.h"
#include <string.h>

void problem_032(void)
{
    printf("===== 第32题：删除一个字符串中的指定字母，如：字符串 aca，删除其中的 a 字母。 =====\n");
    // 在这里编写你的题目代码
    char str [100];
    char target;
    printf("请输入一个字符\n");
    scanf("%s",str);
    printf("请输入要删除的字母\n");
    scanf(" %c",&target);
    int len = strlen(str);
    for ( int i = 0 ; i < len ; i++ ){
        if (target == str [i]){
            for ( int j = i ; j < len ; j++){
                str[j] = str [j+1];
            }
            len--;
            i--;//因为新的字符移到了i 位置，下一轮还是要检查它
        }
    }
    printf("删除后的字符串为：%s\n", str);
}
