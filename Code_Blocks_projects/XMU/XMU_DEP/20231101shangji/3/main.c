/*
第3关：小明的自娱自乐

任务描述
本关任务：编写一个代码程序解决小明的自娱自乐问题。

相关知识
练习完前面四个题，小明有点累了，就上上网，找找C语言的资料。碰巧看到这样一道题：输入一个正整数，然后从个位开始一次输出每一位数字对应的英文字母。例如：输入1532，输出two three five one。

输入描述
第一行输入一个T，代表有T组测试数据，T<100
对于每一组测试数据，输入一个整数x（0<x<100,000,000）

输出描述
对于每一组测试数据，输出对应结果，每个结果占一行，行末有空格

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决小明的自娱自乐问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
3
24
1993
562431
预期输出：
four two
three nine nine one
one three four two six five
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0,a=0,b=0,c=0;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        scanf("%d",&a);
        for(int j=1; j<=a; j*=10)
        {
            b=a/j-a/(j*10)*10;
            switch(b)
            {
            case 0:
                printf("zero ");
                break;
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
            }
        }
        if(a==0)
            printf("zero");
        printf("\n");
    }
    return 0;
}
