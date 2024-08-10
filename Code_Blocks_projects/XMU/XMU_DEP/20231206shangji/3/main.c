/*
第3关：数组的平衡

任务描述
本关任务：编写一个代码程序解决数组的平衡问题。

相关知识
写一个函数，计算一个整形数组a的中心分割点。假设某个分割点的下标为k，那么s1=a[1]+a[2]+…+a[k]，s2=a[k+1]+a[k+2]+…+a[n]，让s1和s2差距最小的下标k即为数组a的中心分割点，若有多个中心分割点，选择值小的。

为了与题目描述保持一致，以下程序框架中，数组a的0下标并没有用到。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
int center(int a[], int n)
{
}
//你的代码结束
//固定尾部开始
int main()
{
  int i, n, a[10001];
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("%d", center(a, n));
  return 0;
}
//固定尾部结束
输入描述
第一行输入一个整数n，代表数组元素个数。（n≤10000）

第二行输入n个整数，每个数的范围[0, 1000]

输出描述
输出题目中所述的中心分割点的值，若有多个中心分割点，选择值小的。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决数组的平衡问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
5
1 1 1 2 3
预期输出：3
*/

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
int center(int a[], int n)
{
    long long int D=0;
    /*
    int res;
    for(int i=0; i<n; i++)
        D+=a[i+1];
    D=abs(D);
    for(int i=1; i<n; i++)
    {
        int f=0,b=0;
        for(int j=0; j<=i; j++)
            f+=a[j+1];
        for(int j=i+1; j<n; j++)
            b+=a[j+1];
        long long int d=abs(f-b);
        if(d<D)
            D=d,res=i;
    }
    */
    int res=1;
    for(int *p=a+2; p<=a+n; p++)
        D+=*p;
    D-=a[1];
    D=abs(D);
    for(int *p=a+2; p<=a+n; p++)
    {
        long long int f=0,b=0;
        for(int *q=a+1; q<=p; q++)
            f+=*q;
        for(int *q=p+1; q<=a+n; q++)
            b+=*q;
        long long int d=abs(f-b);
        if(d<D)
            D=d,res=p-a;
    }
    return res;
}
//你的代码结束
//固定尾部开始
int main()
{
    int i, n, a[10001];
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", center(a, n));
    return 0;
}
//固定尾部结束
