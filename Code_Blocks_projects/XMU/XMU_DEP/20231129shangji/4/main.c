/*
第4关：进制转换进阶版

任务描述
本关任务：编写一个代码程序解决进制转换进阶版问题。

相关知识
给若干个十进制，要求把每个数转成M（2≤M≤16）进制，用递归实现，和一般进制表示法相同，A代表10，B代表11，C代表12，D代表13，E代表14，F代表15。

注意：

你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码；
可以增加自定义函数。
//固定头部开始
#include <stdio.h>
#include <string.h>
char ch[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//固定头部结束
//你的代码开始
int convert(int n, int m, char result[])
{
}
//你的代码结束
//固定尾部开始
int main()
{
    int n, m, T;
    char result[1024];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(result, 0, 1024);
        convert(n, m, result);
        printf("%s\n", result);
    }
    return 0;
}
//固定尾部结束
输入描述
第一行输入一个整数T，表示需要转换的个数。接下来T行每行两个十进制数n和m，表示要把n转成m进制。(0<n<2^31, 2≤m≤16)

输出描述
对每个数输出一行，表示转换结果。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决进制转换进阶版问题。

不一定要在convert函数中递归，可以使用convert函数调用自己定义的递归函数，然后与convert函数一起提交。

测试用例
平台会对你编写的代码进行测试：

测试输入：
3
157 2
157 8
157 16
预期输出：
10011101
235
9D
*/

//固定头部开始
#include <stdio.h>
#include <string.h>
char ch[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
//固定头部结束
//你的代码开始
int convert(int n, int m, char result[])
{
    /*
    int a=0,t=0;
    for(int i=1; ; i*=m)
    {
        if((n/i)<m)
        {
            a=i;
            break;
        }
    }
    */
    /*
    if(!a)
        result[0]='0';
        */
        /*
    for(int i=a; i>0; i/=m)
    {
        result[t]=ch[n/i];
        n=n-(n/i)*i,t++;
    }
    */
    if(n<m)
    {
        result[0]=ch[n];
        return 0;
    }
    else
    {
        int i=convert(n/m,m,result);
        i++,result[i]=ch[n%m];
        return i;
    }
}
//你的代码结束
//固定尾部开始
int main()
{
    int n, m, T;
    char result[1024];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(result, 0, 1024);
        convert(n, m, result);
        printf("%s\n", result);
    }
    return 0;
}
//固定尾部结束
