/*
第4关：小明的生词本

任务描述
本关任务：编写一个代码程序解决小明的生词本问题。

相关知识
小明知道自己的单词量远远不及他人，于是他想编程给自己建一个生词本，每次遇到新的单词的时候就加入到自己的生词本中。不过由于有时记性不好，本来已经存在生词本中的单词又被小明当成生词加入到了生词本中，对于这种情况，并不需要再给这个单词在分配一块内存来存放数据，也就是说，保证生词本中的单词之间的相异性。在加入一系列单词后，小明想知道自己的生词本中有多少个单词。

输入描述
第一行为一个正整数N，0<N≤1000，N代表小明加入的单词总数

接下来N行，每一行都是由小写字母组成的单词，单词长度不超过10

输出描述
输出生词本中的生词总数M

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决小明的生词本问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
9
the
quick
brown
fox
jumps
over
the
lazy
dog
预期输出：8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    unsigned int N=0;
    scanf("%u",&N);
    char A[N][11];
    unsigned int n=N;
    /*
    for(int i=0; i<N; i++)
    {
        scanf("%s",A[i]);
        getchar();
    }
    */
    for(unsigned int i=0; i<N; i++)
        scanf("%s",A[i]),getchar();
    //for(int i=0; i<N-1; i++)
    for(unsigned int i=0; i<N-1; i++)
    {
        //for(int j=i+1; j<N; j++)
        for(unsigned int j=i+1; j<N; j++)
        {
            if((A[i][0])&&(A[j][0])&&(!(strcmp(A[i],A[j]))))
                A[j][0]=0;
        }
    }
    //for(int i=0; i<N; i++)
    for(unsigned int i=0; i<N; i++)
    {
        if(!(A[i][0]))
            n--;
    }
    printf("%u\n",n);
    return 0;
}
