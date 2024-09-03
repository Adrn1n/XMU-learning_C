/*
第1关：伪ackermann函数

任务描述
本关任务：编写一个代码程序解决伪ackermann函数问题。

相关知识
小明在看数学书的时候看到了一个叫ackerman的数学函数，感觉非常神奇，于是他写了几个小数据算了一下，发现怎么也算不出来。无奈的他小小的修改了一下函数，发现变的简单许多。可是他现在想要得到的结果有很多，你能帮他吗？该函数如下：A(m,n)={n+1   m=0,n>0; A(m−1,1)   m>0,n=0; A(m−1,n−1)+n   m>0,n>0; 0  m=0,n=0}

//固定头部开始
#include <stdio.h>
//固定头部结束
//你的代码开始
int Ackermann(int m, int n)
{
      //********** Begin **********
    //********** End **********
}
//你的代码结束
//固定尾部开始
int main() {
    int T;
    scanf("%d", &T);
    int m[T], n[T];
    for(int i=0;i<T;i++) {
        scanf("%d %d", &m[i], &n[i]);
    }
    for(int i=0;i<T;i++) {
        printf("%d\n", Ackermann(m[i],n[i]));
    }
    return 0;
}
//固定尾部结束
输入描述
输入第一行一个整数T，表示小明询问你的次数。（T≤100）接下来的T行每行两个整数M,N。（0≤M,N≤1000）

输出描述
对每个M,N输出相应的A(M,N)的值，每个值输出一行。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决伪ackermann函数问题。

测试用例
平台会对你编写的代码进行测试：

测试输入:
3
1 1
22 15
23 21
预期输出：
1
125
232
*/


//固定头部开始
#include <stdio.h>
//固定头部结束
//你的代码开始
int Ackermann(int m, int n)
{
    //********** Begin **********
    /*
    if((!m)&&(!n))
        return 0;
    else if((!m)&&(n))
        return n+1;
    else if((m)&&(!n))
        return Ackermann(m-1,1);
    else
        return Ackermann(m-1,n-1)+n;
        */
    if((m>0)&&(n>0))
        return Ackermann(m-1,n-1)+n;
    else if((m)&&(!n))
        return Ackermann(m-1,1);
    else if((!m)&&(n))
        return n+1;
    else
        return 0;
    //********** End **********
}
//你的代码结束
//固定尾部开始
int main()
{
    int T;
    scanf("%d", &T);
    int m[T], n[T];
    for(int i=0; i<T; i++)
    {
        scanf("%d %d", &m[i], &n[i]);
    }
    for(int i=0; i<T; i++)
    {
        printf("%d\n", Ackermann(m[i],n[i]));
    }
    return 0;
}
//固定尾部结束
