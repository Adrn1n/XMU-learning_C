/*
整数转罗马数字
描述

罗马数字共有 13 个符号，由 7 个不同的单字符以及额外的 6 个不同的双字符组成，每个符号对应一个具体的数值，如下：

符号    数值
 M --> 1000
 D -->  500
 C -->  100
 L -->   50
 X -->   10
 V -->    5
 I -->    1
CM -->  900
CD -->  400
XC -->   90
XL -->   40
IX -->    9
IV -->    4

罗马数字的规则是：对于罗马数字从左到右的每一位，选择尽可能大的符号值。

例如 6 有几种拆分：5+1，4+1+1，1+1+1+1+1+1，则选择第一种，对应符号为 VI。

输入一个整数 n，如果该整数 n 满足：1 <= n <= 3999，将该整数转换为罗马数字输出，否则输出error。


输入
一个整数 n


输出
一个字符串，如果 n 满足要求，输出对应的罗马数字，否则输出error。


输入样例 1

-1
输出样例 1

error
输入样例 2

99
输出样例 2

XCIX
输入样例 3

123
输出样例 3

CXXIII
来源

sway
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    scanf("%d",&n);
    if((n>=1)&&(n<=3999))
    {
        char S[4001]= {0},*p=S;
        int tmp=0;
        if(n>=1000)
        {
            tmp=n/1000;
            for(int i=0; i<tmp; i++, p++)
                *p='M';
            n-=tmp*1000;
        }
        if(n>=900)
        {
            tmp=n/900;
            for(int i=0; i<tmp; i++, p++)
                *p='C',*(++p)='M';
            n-=tmp*900;
        }
        if(n>=500)
        {
            tmp=n/500;
            for(int i=0; i<tmp; i++, p++)
                *p='D';
            n-=tmp*500;
        }
        if(n>=400)
        {
            tmp=n/400;
            for(int i=0; i<tmp; i++, p++)
                *p='C',*(++p)='D';
            n-=tmp*400;
        }
        if(n>=100)
        {
            tmp=n/100;
            for(int i=0; i<tmp; i++, p++)
                *p='C';
            n-=tmp*100;
        }
        if(n>=90)
        {
            tmp=n/90;
            for(int i=0; i<tmp; i++, p++)
                *p='X',*(++p)='C';
            n-=tmp*90;
        }
        if(n>=50)
        {
            tmp=n/50;
            for(int i=0; i<tmp; i++, p++)
                *p='L';
            n-=tmp*50;
        }
        if(n>=40)
        {
            tmp=n/40;
            for(int i=0; i<tmp; i++, p++)
                *p='X',*(++p)='L';
            n-=tmp*40;
        }
        if(n>=10)
        {
            tmp=n/10;
            for(int i=0; i<tmp; i++, p++)
                *p='X';
            n-=tmp*10;
        }
        if(n>=9)
        {
            tmp=n/9;
            for(int i=0; i<tmp; i++, p++)
                *p='I',*(++p)='X';
            n-=tmp*9;
        }
        if(n>=5)
        {
            tmp=n/5;
            for(int i=0; i<tmp; i++, p++)
                *p='V';
            n-=tmp*5;
        }
        if(n>=4)
        {
            tmp=n/4;
            for(int i=0; i<tmp; i++, p++)
                *p='I',*(++p)='V';
            n-=tmp*4;
        }
        if(n>=1)
        {
            tmp=n/1;
            for(int i=0; i<tmp; i++, p++)
                *p='I';
            n-=tmp*1;
        }
        printf("%s",S);
    }
    else
        printf("error\n");
    return 0;
}
