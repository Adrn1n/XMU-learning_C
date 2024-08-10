/*
第1关：合并队伍

任务描述
本关任务：编写一个代码程序解决合并队伍问题。

相关知识
小华虽然在数学上不及小明，编程上肯定不及小强。但是在体育方面却是无人能及的。小华可是在千军万马中千辛万苦地杀出一条血路，终于选上了一门体育课！第一次体育课，小华向老师毛遂自荐当体育委员，当然老师也爽快的答应了！

在整理队伍的时候，小明发现女生站两排有点短了，于是想把两排女生合为一排。在合并之前，每一排女生都是从左至右按身高从高到低的顺序排好的。为了保持这个顺序，小华要怎么指导女生，才能保证在合并之后，女生仍然是按照从左至右按身高从高到低的顺序排列的？

输入描述
第一行输入两个正整数m，n，m为第一排女生的人数，n为第二排女生人数。0<m,n<10000

第二行输入m个正整数ai，非递增顺序（即a_i≥a_(i+1)​），代表m个女生的身高

第三行输入n个正整数bi，非递增顺序（即b_i​≥b_(i+1)​），代表n个女生的身高

输出描述
输出合并后的身高，非递增顺序

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决合并队伍问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
5 6
165 163 159 155 150
169 164 160 158 155 151
预期输出：
169 165 164 163 160 159 158 155 155 151 150
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int m=0,n=0;
    scanf("%d%d",&m,&n);
    int A[m],B[m+n];
    for(int i=0; i<m; i++)
        scanf("%d",&A[i]);
    for(int i=m; i<m+n; i++)
        scanf("%d",&B[i]);
    for(int i=0; i<m; i++)
        B[i]=A[i];
    for(int i=0; i<m+n; i++)
    {
        for(int j=0; j<m+n-1; j++)
        {
            if(B[j]<B[j+1])
            {
                B[j]+=B[j+1];
                B[j+1]=B[j]-B[j+1];
                B[j]-=B[j+1];
            }
        }
    }
    for(int i=0; i<m+n; i++)
        printf("%d ",B[i]);
        */
    unsigned int m=0,n=0;
    scanf("%u%u",&m,&n);
    unsigned int A[m+n],B[n];
    for(unsigned int i=0; i<m; i++)
        scanf("%u",&A[i]);
    for(unsigned int i=0; i<n; i++)
        scanf("%u",&B[i]);
    for(unsigned int i=0; i<n; i++)
        A[m+i]=B[i];
    for(unsigned int i=0; i<m+n; i++)
    {
        for(unsigned int j=0; j<m+n-1-i; j++)
        {
            if(A[j]<A[j+1])
            {
                A[j]+=A[j+1];
                A[j+1]=A[j]-A[j+1];
                A[j]-=A[j+1];
            }
        }
    }
    for(unsigned int i=0; i<m+n; i++)
        printf("%u ",A[i]);
    return 0;
}
