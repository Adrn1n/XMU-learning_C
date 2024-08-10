/*
汉字逆序
描述

汉字不同于普通字符， 每个汉字均由 2 个字符组成， 例如： “中”字， 就是由字符： ’\326’和’\320’组成的。 编写程序从键盘读入一个全部由汉字构成的句子，输出逆序后的结果。句子不包含其它符号， 且句子最长不超多 20 个汉字。


输入
不含空格和其它字符的汉字句子，句长不超过20个字。


输出
逆序后的结果。


输入样例 1

我爱厦门大学
输出样例 1

学大门厦爱我
来源

sway
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char A[41]= {0};
    scanf("%s",A);
    unsigned len=strlen(A);
    for(char *p=A; p<A+len/2; p+=2)
    {
        char tmp[2]= {0};
        strncpy(tmp,p,2);
        strncpy(p,A+len-(p-A)-2,2);
        strncpy(A+len-(p-A)-2,tmp,2);
    }
    printf("%s\n",A);
    return 0;
}
