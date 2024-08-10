/*
第1关：变与不变

任务描述
本关任务：编写一个代码程序解决变与不变问题。

相关知识
编写下列函数

　　void change(int *a,int *b,int flag);
根据flag的值对a、b进行处理。

当flag为正数时，对a、b指向的变量求绝对值;

当flag为0时， a、b指向变量值不变；

当flag为负数时，交换a、b指向的变量的值。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。

//固定头部开始
#include <stdio.h>
//固定头部结束
//你的代码开始
void change(int *a,int *b,int flag)
{
}
//你的代码结束
//固定尾部开始
int main()
{
    int t,a,b,flag;
    void change(int *a,int *b,int flag);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d",&a,&b,&flag);
        change(&a,&b,flag);
        printf("%d %d\n",a,b);
    }
    return 0;
}
//固定尾部结束
输入描述
第一行一个整数t，表示测试数据组数

接下来t行，每一行三个整数，分别为a，b，flag

输出描述
输出a、b指向变量的值，用一个空格隔开

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决变与不变问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
3
-1 2 3
-1 2 -3
-1 2 0
预期输出：
1 2
2 -1
-1 2
*/

//固定头部开始
#include <stdio.h>
//固定头部结束

//你的代码开始
void change(int *a,int *b,int flag)
{
//********** Begin **********
    if(flag>0)
    {
        if(*a<0)
            *a=-(*a);
        if(*b<0)
            *b=-(*b);
    }
    else if(flag<0)
    {
        *a+=(*b);
        *b=*a-(*b);
        *a-=*b;
    }
//********** End **********
}
//你的代码结束

//固定尾部开始
int main()
{
    int t,a,b,flag;
    void change(int *a,int *b,int flag);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d",&a,&b,&flag);
        change(&a,&b,flag);
        printf("%d %d\n",a,b);
    }
    return 0;
}
//固定尾部结束
