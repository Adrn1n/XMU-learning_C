/*
第5关：子串删除

任务描述
本关任务：编写一个代码程序解决子串删除问题。

相关知识
给定两个字符串s和t，若s是t的子串，将t中的子串s删除，若存在多个子串，则全部删除；若s不是t的子串，对字符串t不做处理。字符串s和t长度不超过1000。

输入描述
第一行，字符串t，文本长度≤1000。

第二行，字符串s，文本长度≤1000。

输出描述
处理后的字符串t

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决子串删除问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
Hello World!
Hello
预期输出：World!

测试输入：
No pain, no gain
ain
预期输出：No p, no g
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delstr(char *t,char *s)
{
    //char temp[1001]="0";
    char temp[1001]= {0};
    unsigned int l_t=strlen(t),l_s=strlen(s);
    //for(int i=0; i<l_t-l_s; i++)
    for(char *p=t; p<=t+l_t-l_s; p++)
    {
        //strncpy(temp,t+i,l_s);
        strncpy(temp,p,l_s);
        //
        if(!(strcmp(s,temp)))
        {
            /*
            for(int j=0; j<l_t-i; j++)
                *(t+i+j)=*(t+i+j+l_s);
                */
            strcpy(p,p+l_s);
            p--;
        }
    }
}

int main()
{
    //char t[1001]= "0",s[1001]="0";
    char t[1001]= {0},s[1001]= {0};
    fgets(t,1000,stdin);
    for(char *p=t; p<t+1001; p++)
        if(*p=='\n')
        {
            *p=0;
            break;
        }
    fgets(s,1000,stdin);
    for(char *p=s; p<s+1001; p++)
        if(*p=='\n')
        {
            *p=0;
            break;
        }
    delstr(t,s);
    printf("%s\n",t);
    return 0;
}
