/*
Excel表的列名称
描述

给定一个正整数，返回它在 Excel 表中相对应的列名称（注：Excel列编号规则是仅用大写字母编号）。

例如，

1->A

2->B

3->C

...

26->Z

27->AA

28->AB

...

702->ZZ

703->AAA

704->AAB

...


输入
一个整数，表示列号，不超过int范围。


输出
一个字符串，表示列名称。


输入样例 1

1
输出样例 1

A
输入样例 2

28
输出样例 2

AB
输入样例 3

1000
输出样例 3

ALL
来源
sway

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    scanf("%d",&a);
    char A[8]= {0},*p=A+7;
    do
    {
        *(--p)=(a-1)%26+'A';
        a=(a-(*p-'A'+1))/26;
    }
    while(a>0);
    printf("%s\n",p);
    return 0;
}
