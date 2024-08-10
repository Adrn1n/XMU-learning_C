/*
第4关：高级模式匹配

任务描述
本关任务：编写一个代码程序解决高级模式匹配问题。

相关知识
给定两个字符串s和t，判断s是否是t的子序列，即从t中删除若干个（包括0个）字符，将剩余的字符连接起来，即可获得s。字符串s和t长度不超过1000。

输入描述
第一行，字符串t，文本长度≤1000。

第二行，字符串s，文本长度≤1000。

输出描述
若s是t的子序列，输出1，否则输出0

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决高级模式匹配问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
ATBhCde His
This
预期输出：1

测试输入：
ATBhCde His
That
预期输出：0
*/

#include <stdio.h>
#include <stdlib.h>

unsigned int Judge(char *t,char *s)
{
    //while(1)
    while(*s)
    {
        /*
        if(!(*s))
            return 1;
            */
        if(!(*t))
            return 0;
        unsigned int k=1;
        /*
        if(*s==0)
            return 1;
            */
        if(*t==*s)
            t++,s++,k=0;
        if(k)
            t++;
    }
    return 1;
}

int main()
{
    char t[1001]= {0},s[1001]= {0};
    fgets(t,1000,stdin);
    fgets(s,1000,stdin);
    printf("%u\n",Judge(t,s));
    return 0;
}
