/*
第4关：出队统计

任务描述
本关任务：编写一个代码程序解决出队统计问题。

相关知识
有N个人按照顺时针围成一圈，编号1到N。他们从1开始按顺时针报数，每报到M的人出列，并从下一个开始报数，报到M的人再出列，直到全部出列，请问你能给出这N个人的出队顺序吗？

输入描述
入只有一行，包括两个整数N,M（1≤N,M≤1000）

输出描述
输出一行N个数，代表出队序列，每两个数之间用一个空格隔开。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决解决出队统计问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：7 3；
预期输出：3 6 2 7 5 1 4
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned short N=0,M=0;
    scanf("%hu%hu",&N,&M);
    unsigned short A[N];
    //for(short i=0; i<N; i++)
    for(unsigned short i=0; i<N; i++)
        A[i]=i+1;
    //short flag=N,count=0;
    unsigned short flag=N,count=0;
    for(unsigned short *p=A; flag>0; p++)
    {
        if(p>=A+N)
            p=A;
        if(*p)
            count++;
        if(count==M)
            printf("%hu ",*p),*p=0,flag--,count=0;
    }
    return 0;
}
