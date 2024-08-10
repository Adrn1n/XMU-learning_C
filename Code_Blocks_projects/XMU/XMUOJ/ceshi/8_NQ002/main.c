/*
字符比大小
描述

小鲁刚接触编程不久，但他一直不明白计算机中存储的字符跟数值一样是有大小关系的，但是谁大谁小，他一直搞不清楚。你能帮帮他解除这个疑惑吗？

请输入N组数据，每组数据包含三个字符，然后按从小到大的顺序输出这三个字符。


输入
第一行输入数值N

输入N行，每行3个字符。


输出
输出有N行，每行是排序后的3个字符，用空格隔开。


输入样例 1

3
awe
bsd
aZt
输出样例 1

a e w
b d s
Z a t
提示

利用ASCⅡ码值比较大小

来源

5DG在线编程 http://122.51.69.77
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned N=0;
    scanf("%u",&N),getchar();
    for(int i=0; i<N; i++)
    {
        char a=0,b=0,c=0;
        scanf("%c%c%c",&a,&b,&c),getchar();
        if(a>b)
            a+=b,b=a-b,a-=b;
        if(b>c)
            b+=c,c=b-c,b-=c;
        if(a>b)
            a+=b,b=a-b,a-=b;
        printf("%c %c %c\n",a,b,c);
    }
    return 0;
}
