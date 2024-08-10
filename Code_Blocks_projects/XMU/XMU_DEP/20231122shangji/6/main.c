/*
第6关：卡片游戏

任务描述
本关任务：编写一个代码程序解决卡片游戏问题。

相关知识
这一天，小明他们玩了一个游戏。

每个人手中有n张卡片，每一张卡片上有一个整数，接着裁判给出一个整数k，然后每一个人需要选择两张卡片使得两张卡片上的数字之和为k，如果可以出卡片，那么打出这两张卡片。如果不行，那么就该下家出卡片。谁先出完卡片谁就是赢家。

现在轮到小明出卡片了，不过由于卡片较多且卡片上数据较大，小明尽可能要在最短时间内决定能不能出卡片，因为其他玩家已经在嚷嚷“快点啊，我等得花儿都谢了！”

输入描述
第一行输入两个整数n、k，
2≤n≤1000,0<K≤2,000,000,000。

第二行输入n个整数ai (0<ai≤1,000,000,000)，代表n张卡片上的数。

输出描述
为了简单起见，（因为两张卡片数字之和为k的组合可能有多种）如果可以出卡片，则输出“Yes”；如果不能出卡片，则输出“No”（无引号）

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决卡片游戏问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
5 10
4 5 6 2 1
预期输出：Yes
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
void big_add(char A[],char B[],char C[],unsigned int a,unsigned int b)
{
    int k=(a>b)?1:0;
    unsigned int m=k?b:a;
    unsigned int n=k?a:b;
    for(int i=0; i<m; i++)
    {
        C[n-i]+=A[a-1-i]+B[b-1-i]-'0';
        if(C[n-i]>'9')
        {
            C[n-i]-=10;
            C[n-i-1]++;
        }
    }
    for(int i=m; i<n; i++)
    {
        if(k)
        {
            C[n-i]+=A[a-1-i];
            if(C[n-i]>'9')
            {
                C[n-i]-=10;
                C[n-i-1]++;
            }
        }
        else
        {
            C[n-i]+=B[b-1-i];
            if(C[n-i]>'9')
            {
                C[n-i]-=10;
                C[n-i-1]++;
            }
        }
    }
    if(!(C[0]))
    {
        for(int i=0; i<n; i++)
            C[i]=C[i+1];
        C[n]=0;
    }
    else
        C[0]+='0';
}

int main()
{
    unsigned int N=0;
    scanf("%u",&N);
    getchar();
    char A[N][11],B[11]= {0};
    for(int i=0; i<N*11; i++)
        A[0][i]=0;
    scanf("%s",B);
    getchar();
    for(int i=0; i<N; i++)
    {
        scanf("%s",A[i]);
        getchar();
    }
    int k=0;
    for(int i=0; i<N-1; i++)
    {
        if(k)
            break;
        for(int j=i+1; j<N; j++)
        {
            char C[11]= {0};
            unsigned int a=strlen(A[i]),b=strlen(A[j]);
            big_add(A[i],A[j],C,a,b);
            if(!(strcmp(B,C)))
                k=1;
            if(k)
                break;
        }
    }
    */

int main()
{
    unsigned int N=0,k=0;
    scanf("%u%u",&N,&k);
    unsigned int A[N];
    for(int i=0; i<N; i++)
        scanf("%u",&A[i]);
    int t=0;
    for(unsigned int i=0; i<N-1; i++)
    {
        for(unsigned int j=i+1; j<N; j++)
        {
            if(A[i]+A[j]==k)
                t=1;
            if(t)
                break;
        }
        if(t)
            break;
    }
    if(t)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
