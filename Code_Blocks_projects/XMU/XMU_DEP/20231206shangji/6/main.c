/*
第6关：组合

任务描述
本关任务：编写一个代码程序解决组合问题。

#include <stdio.h>
void zhs(int cur, int pre, int n, int m, int a[])
{
}
//固定代码开始
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[11];
    zhs(0, 1, n, m, a);
    return 0;
}
//固定代码结束
相关知识
给1到N，N个数，要你从中选取M个出来，请输出每一种的选取情况（根据序列字典序输出，即两个序列比大小，第一位小的小，若相等第二位小的小，若相等第三位小的小……）。

输入描述
输入一行，包括两个整数N, M。（2<M<N≤10）

输出描述
输出若干行，每行表示一个组合方式，按字典序输出。

注意：每行末尾有空格

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决组合问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：4 3；
预期输出：
1 2 3
1 2 4
1 3 4
2 3 4
*/

#include <stdio.h>
void zhs(int cur, int pre, int n, int m, int a[])
{
    /*
    int res[m];
    res[m-1]=0;
    do
    {
        if(!(res[m-1]))
        {
            /*
            for(int i=0; i<m; i++)
                res[i]=i+1;
            for(int i=0; i<m; i++)
                printf("%d ",res[i]);
                */
    /*
    for(int *p=res; p<res+m; p++)
    *p=(p-res)+1;
    for(int *p=res; p<res+m; p++)
    printf("%d ",*p);
    printf("\n");
    continue;
    }
    int k=1;
    */
    /*
    for(int i=0; i<m; i++)
    {
        if(n-res[i]==m-1-i)
        {
            res[i-1]++;
            for(int j=i; j<m; j++)
                res[j]=res[j-1]+1;
            k=0;
            break;
        }
    }
    */
    /*
    for(int *p=res; p<res+m; p++)
    {
        if(n-*p==m-1-(p-res))
        {
            (*(p-1))++;
            for(int *q=p; q<res+m; q++)
                *q=*(q-1)+1;
            k=0;
            break;
        }
    }
    if(k)
        res[m-1]++;
        */
    /*
    for(int i=0; i<m; i++)
    printf("%d ",res[i]);
    */
    /*
    for(int *p=res; p<res+m; p++)
        printf("%d ",*p);
    printf("\n");
    }
    while(n-res[0]!=m-1);
    */
    if(cur-1>=0)
        a[cur-1]=pre,pre++;
    if(cur>=m)
    {
        for(int i=0; i<m; i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    else
        for(int i=pre; (i<=n)&&(m-cur-1<=n-i); i++)
            zhs(cur+1,i,n,m,a);
}
//固定代码开始
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[11];
    zhs(0, 1, n, m, a);
    return 0;
}
//固定代码结束
