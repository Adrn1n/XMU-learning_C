/*
第3关：不重叠子串数

任务描述
本关任务：编写一个代码程序解决不重叠子串数问题。

相关知识
小明又找到一道难一点的题：给出两个字符串t和s，求出t中能找出几个不重叠的s串。比如t="tobeornottobe"，s="to"，则t中有2个不重叠的"to"串。

输入描述
第一行是一个正整数n，n≤10，表示接下来有几组测试数据接下来的每组数据有两个字符串t和s，都只包含字母，且长度不超过100000

输出描述
对每组数据输出对应的答案

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决不重叠子串数问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
2
vvvv
vvv
tobeornottobe
to
预期输出：
1
2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned int T=0;
    /*
    scanf("%u",&T);
    getchar();
    */
    scanf("%u",&T),getchar();
    //for(int t=0; t<T; t++)
    for(unsigned int t=0; t<T; t++)
    {
        char A[100001]= {0},B[100001]= {0};
        /*
        scanf("%s",A);
        getchar();
        scanf("%s",B);
        getchar();
        */
        scanf("%s",A),getchar(),scanf("%s",B),getchar();
        //unsigned int m=0,n=0,s=0;
        unsigned int m=strlen(A),n=strlen(B),s=0;
        //for(int i=0; i<m; i++)
        for(unsigned int i=0; i<m-n+1; i++)
        {
            char C[100001]= {0};
            strncpy(C,A+i,n);
            if(!(strcmp(C,B)))
            {
                s++;
                i+=n;
            }
        }
        printf("%u\n",s);
    }
    return 0;
}
