/*
第3关：模式匹配

任务描述
本关任务：编写一个代码程序解决模式匹配问题。

相关知识
以字符串的形式给出文本text和模式串p1,p2...pn。请使用指针方法编写程序判断有多少个模式串出现在文本中。

输入描述
第一行一个整数N(N≤20)，表示模式串的个数。

第二行，一个字符串，表示给定的文本。文本长度≤20。

第三行至第N+2行，每行一个字符串，表示模式串。模式串长度≤10。
输出描述
输出一个整数，即出现在文本中的模式串的个数。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决模式匹配问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
2
Abc
Ab
bc
预期输出：2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int Compare_char(char *A,char *B)
{
    unsigned int i=0;
    char C[21]= {0};
    unsigned int l_A=strlen(A),l_B=strlen(B);
    for(char *p=A; p<=A+l_A-l_B; p++)
    {
        strncpy(C,p,l_B);
        if(!(strcmp(C,B)))
        {
            i++;
            break;
        }
    }
    return i;
}

int main()
{
    unsigned int n=0,s=0;
    scanf("%u",&n);
    char A[21]= {0},B[10][21]= {0};
    scanf("%s",A);
    for(int i=0; i<n; i++)
        scanf("%s",B[i]);
    for(int i=0; i<n; i++)
        s+=Compare_char(A,B[i]);
    printf("%u\n",s);
    return 0;
}
