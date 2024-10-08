/*
第3关：第K高的人

任务描述
本关任务：编写一个代码程序解决第K高的人问题。

相关知识
对于男生来说，身高是一个比较“严肃”的话题：谁都希望自己能长高一点。很不幸，小明连170cm的门槛都没能迈进。也不知道小明从哪弄来一份全院男生的资料，不过小明最关心的还是身高！现在小明想从全院n个男生中找出第k高的男生的身高是多少，不过由于信息学院人口众多，小明想尽可能用快的方法找到他想知道的第k高的身高！

输入描述
第一行输入总男生人数n和需查询的第k高的身高，
0<k≤n<100,50<n<100

第二行输入n个身高值[150, 250]，保证n个身高值互不相同

输出描述
输出第k高的身高值

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决第K高的人问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
10 6
160 175 180 165 170 171 169 185 172 168
预期输出：170
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,k=0;
    scanf("%d%d",&n,&k);
    int A[n];
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(A[j]<A[j+1])
            {
                A[j]+=A[j+1];
                A[j+1]=A[j]-A[j+1];
                A[j]-=A[j+1];
            }
        }
    }
    /*
    k--;
    printf("%d",A[k]);
    */
    printf("%d",A[k-1]);
    return 0;
}
