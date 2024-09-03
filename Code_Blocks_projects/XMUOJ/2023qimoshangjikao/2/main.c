/*
最小数
描述

对给定的若干个0 ~ 9数字，进行排列使得到的正整数尽可能小（0不能做首位数字）。


输入
第一行给出数字个数n（1 <= n <= 100）；第二行给出0 ~ 9范围内的n个数字（至少含1个非0数字），中间用一个空格分隔。


输出
可构成的最小正整数。


输入样例 1

10
2 4 0 5 0 3 0 2 1 0
输出样例 1

1000022345
来源

sway
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned n=0,A[100]= {0};
    scanf("%u",&n);
    for(unsigned *p=A; p<A+n; p++)
        scanf("%u",p);
    for(unsigned *p=A+1; p<A+n; p++)
        if((*p<*A)&&(*p))
        {
            *A+=*p;
            *p=*A-*p;
            *A-=*p;
        }
    for(unsigned *p=A+1; p<A+n; p++)
        for(unsigned *q=p+1; q<A+n; q++)
            if(*q<*p)
            {
                *p+=*q;
                *q=*p-*q;
                *p-=*q;
            }
    for(unsigned *p=A; p<A+n; p++)
        printf("%u",*p);
    printf("\n");
    return 0;
}
