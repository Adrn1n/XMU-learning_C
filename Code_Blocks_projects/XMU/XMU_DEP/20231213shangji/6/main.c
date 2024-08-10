/*
第6关：破译时间密码

任务描述
本关任务：编写一个代码程序解决破译时间密码问题。

相关知识
截获了一串敌军的密码字符串，其中包含2013年中某个重要的时间（某月某日），需对其破解翻译。

字符串中包含数字和其他字符，删除其中的非数字字符，得到一个数字字符串，记为整数N，并按照如下公式计算：

Q =（N*3） MOD 1131 + 101 ，M = Q /100，D = Q MOD 38，其中MOD表示取余运算。

计算得到的M、D均为整数，M表示月份，D表示日。

判断翻译后的日期（某月某日）是否正确，若翻译结果正确，则显示翻译后的日期（某月某日）；若翻译结果不对，则可能是截获的密码串有误，给出提示信息“input error!”。

例如：

若计算后的M = 9，D = 12，则输出9.12；

若计算后的M = 10，D = 32，则输出"input error!"（因为不存在10月32日）。

输入描述
一个字符串，文本长度 ≤1000

输出描述
第一行：整数N、Q、M、D（分别以一个空格间隔）

第二行：翻译后的日期

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决破译时间密码问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：I like 3this gam4e and this i12s just a test.；
预期输出：
3412  158  1  6
1.6

测试输入：http1://ww1w.google.c4om.hk7；
预期输出：
1147  149  1  35
input error!
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int get_num_in_str(char *A)
{
    unsigned int k=1,n=0;
    while(*A)
    {
        unsigned int a=*A-'0';
        //if(a<10)
        if((a<10)&&(a>=0))
            if(k&&a)
                n=a,k=0;
            else
                n=n*10+a;
        A++;
    }
    return n;
}

int main()
{
    char A[1001]="0";
    fgets(A,1000,stdin);
    unsigned int N=get_num_in_str(A);
    unsigned int Q=((N*3)%1131)+101,M=Q/100,D=Q%38;
    printf("%u %u %u %u\n",N,Q,M,D);
    //unsigned int k=1;
    unsigned int k=1,B[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    /*
    switch(M)
    {
    case 1:
        if(D>31||D<1)
            k=0;
        break;
    case 2:
        if(D>28||D<1)
            k=0;
        break;
    case 3:
        if(D>31||D<1)
            k=0;
        break;
    case 4:
        if(D>30||D<1)
            k=0;
        break;
    case 5:
        if(D>31||D<1)
            k=0;
        break;
    case 6:
        if(D>30||D<1)
            k=0;
        break;
    case 7:
        if(D>31||D<1)
            k=0;
        break;
    case 8:
        if(D>31||D<1)
            k=0;
        break;
    case 9:
        if(D>30||D<1)
            k=0;
        break;
    case 10:
        if(D>31||D<1)
            k=0;
        break;
    case 11:
        if(D>30||D<1)
            k=0;
        break;
    case 12:
        if(D>31||D<1)
            k=0;
        break;
    }
    */
    if((D>B[M-1])||(D<1))
        k=0;
    if(k)
        printf("%u.%u\n",M,D);
    else
        printf("input error!\n");
    return 0;
}
