/*
第2关：查找

任务描述
本关任务：编写一个代码程序解决查找问题。

相关知识
编写下列函数

　　void find_two_largest(int a[],int n,int *largest,int *second_largest);
当传递长度为n的数组a时，函数将在数组a中搜寻最大元素和第二大元素，把它们分别存储在largest和second_largest指向的变量中。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。

//固定头部开始
#include <stdio.h>
//固定头部结束
//你的代码开始
void find_two_largest(int a[],int n,int *largest,int *second_largest)
{
}
//你的代码结束
//固定尾部开始
int main()
{
   int i,n,arr[100],largest,second_largest;
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf("%d",&arr[i]);
   find_two_largest(arr,n,&largest,&second_largest);
   printf("%d %d",largest,second_largest);
   return 0;
}
//固定尾部结束
输入描述
第一行一个整数N (N<100)第二行N个整数，整数间有一个空格的间隔

输出描述
输出N个数中的最大元素和第二大元素，用一个空格隔开

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决查找问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
5
1 2 3 4 5
预期输出：5 4
*/

//固定头部开始
#include <stdio.h>
//固定头部结束

//你的代码开始
void find_two_largest(int a[],int n,int *largest,int *second_largest)
{
//********** Begin **********
    //int k=1;
    *largest=*second_largest=a[0];
    for(int *p=a+1; p<a+n; p++)
        /*
        if((*p>*largest)&&k)
            *largest=*p,k=0;
        else if(*p>*largest)
            *second_largest=*largest,*largest=*p;
            */
        if(*p>*largest)
            *second_largest=*largest,*largest=*p;
        else if(*p>*second_largest)
            *second_largest=*p;
//********** End **********
}
//你的代码结束

//固定尾部开始
int main()
{
    int i,n,arr[100],largest,second_largest;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&arr[i]);
    find_two_largest(arr,n,&largest,&second_largest);
    printf("%d %d",largest,second_largest);
    return 0;
}
//固定尾部结束
