/*
第4关：哥德巴赫猜想的验证

任务描述
本关任务：编写一个代码程序解决哥德巴赫猜想的验证问题。

相关知识
著名的哥德巴赫猜想是这样的：

任何一个大于2的偶数都可以分解成两个素数之和；
任何一个大于5的奇数都可以分解成三个素数之和。
现在请你写两个函数验证一下这个著名的猜想。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
int isPrime(int num) {
//此函数可自行增删
}
void OddDiv(int n)
{
}
void EvenDiv(int n)
{
}
//你的代码结束
//固定尾部开始
int main()
{
  int n;
  scanf("%d", &n);
  (n % 2 == 0) ? EvenDiv(n) : OddDiv(n);
  return 0;
}
//固定尾部结束
输入描述
一个整数N，代表要验证的数，5≤N≤10000，当N为偶数时，验证哥德巴赫猜想1，当N为奇数时，验证哥德巴赫猜想2。

输出描述
对每个验证，输出相应的表达式，要求加数构成的序列的字典序最小，即确保第一位最小，再确保第二位最小（再确保第三位最小）。

例如：

N=13，13=3+3+7=7+3+3

则应输出：

13=3+3+7

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决哥德巴赫猜想的验证问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：13；
预期输出：13=3+3+7
*/

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
int isPrime(int num)
{
    /*
    int k=1;
    for(int i=2; i<=sqrt(num); i++)
    {
        if(!(num%i))
        {
            k=0;
            break;
        }
    }
    if(num==1)
        k=0;
    return k;
    */
    if(num<=1)
        return 0;
    for(int i=2; i<=sqrt(num); i++)
        if(!(num%i))
            return 0;
    return 1;
//此函数可自行增删
}
void OddDiv(int n)
{
    /*
    int t=0;
    for(int i=2; i<n; i++)
    {
        if(!(isPrime(i)))
            continue;
        else
        {
            for(int j=i; j<n; j++)
            {
                if(!(isPrime(j)))
                    continue;
                else
                {
                    for(int k=j; k<n; k++)
                    {
                        if(!(isPrime(k)))
                            continue;
                        else
                        {
                            if(i+j+k==n)
                            {
                                printf("%d=%d+%d+%d\n",n,i,j,k);
                                t=1;
                                break;
                            }
                        }
                    }
                    if(t)
                        break;
                }
            }
            if(t)
                break;
        }
    }
    */
    for(int i=2; i<n; i++)
        if(isPrime(i))
            for(int j=i; j<n; j++)
                if(isPrime(j))
                    if(isPrime(n-i-j))
                    {
                        printf("%d=%d+%d+%d\n",n,i,j,n-i-j);
                        return;
                    }
}
void EvenDiv(int n)
{
    /*
    int t=0;
    for(int i=2; i<n; i++)
    {
        if(!(isPrime(i)))
            continue;
        else
        {
            for(int j=i+1; j<n; j++)
            {
                if(!(isPrime(j)))
                    continue;
                else
                {
                    if(i+j==n)
                    {
                        printf("%d=%d+%d\n",n,i,j);
                        t=1;
                        break;
                    }
                }
            }
            if(t)
                break;
        }
    }
    */
    for(int i=2; i<n; i++)
        if(isPrime(i))
            if(isPrime(n-i))
            {
                printf("%d=%d+%d\n",n,i,n-i);
                return;
            }
}
//你的代码结束
//固定尾部开始
int main()
{
    int n;
    scanf("%d", &n);
    (n % 2 == 0) ? EvenDiv(n) : OddDiv(n);
    return 0;
}
//固定尾部结束
