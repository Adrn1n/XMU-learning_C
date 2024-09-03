/*
第1关：判断素数

任务描述
本关任务：编写一个代码程序解决判断素数问题。

相关知识
写一个函数，判断一个数组中有多少个素数。在主函数中输入多个整数，输出素数的个数。

注意：

你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码；
可以增加自定义函数。
//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
int primes(int a[], int n)
{
}
//你的代码结束
//固定尾部开始
int main()
{
  int i,n;
  int a[10000];
  scanf("%d", &n);
  for(i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("%d", primes(a, n));
  return 0;
}
//固定尾部结束
输入描述
输入一个整数n，代表数组有元素的个数。（n≤10000）

第二行输入n个数的数组。(数值在[1, 10000])

输出描述
输出整型数组中素数的个数。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决判断素数问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
6
4 33 53 3 5 100
预期输出：3
*/

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
int primes(int a[], int n)
{
    //int s=0;
    int s=n;
    for(int i=0; i<n; i++)
    {
        //int k=0;
        for(int j=2; j<(a[i]+1)/2+1; j++)
        {
            if(!(a[i]%j))
            {
                //k=1;
                s--;
                break;
            }
        }
        /*
        if(!k)
            s++;
            */
        if(a[i]==1)
            s--;
    }
    return s;
}
//你的代码结束
//固定尾部开始
int main()
{
    int i,n;
    int a[10000];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("%d", primes(a, n));
    return 0;
}
//固定尾部结束
