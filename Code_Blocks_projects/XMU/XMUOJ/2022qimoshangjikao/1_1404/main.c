/*
分解质因数
描述

一个大于1的整数可以分解为几个素数相乘的结果，编程将正整数n分解质因数，以相乘的形式输出。如n无法分解，输出n=n即可。


输入
大于1的正整数n


输出
n=x*x*…..，因子按从小到大排列


输入样例 1

120
输出样例 1

120=2*2*2*3*5
输入样例 2

11
输出样例 2

11=11
来源
sway

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    scanf("%d",&a);
    unsigned short flag=0;
    int i=2;
    while(i<=a)
    {
        if(!(a%i))
        {
            if(!flag)
                printf("%d=%d",a,i),flag=1;
            else
                printf("*%d",i);
            a=a/i;
        }
        else
            i++;
    }
    printf("\n");
    return 0;
}
