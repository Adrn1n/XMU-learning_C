/*
第2关：ID1507-付钱

任务描述
本关任务：编写一个代码程序解决付钱问题。

相关知识
不考虑找零的情况，用最少张数的钞票来支付账单。假设钞票面值只有100元、50元、20元、10元、5元、2元和1元。

输入描述
一个正整数（不超过int的范围），表示要支付的金额。

输出描述
具体支付方式，共7行，每行两个数，中间用空格和减号隔开，分别表示面额和张数。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决付钱问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：125；
预期输出：
100 - 1
50 - 0
20 - 1
10 - 0
5 - 1
2 - 0
1 - 0
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int t,a,b,c,d,e,f,g=0;
    int t=0,a=0,b=0,c=0,d=0,e=0,f=0,g=0;
    scanf("%d",&t);
    a=t/100;
    b=(t-a*100)/50;
    c=(t-a*100-b*50)/20;
    d=(t-a*100-b*50-c*20)/10;
    e=(t-a*100-b*50-c*20-d*10)/5;
    f=(t-a*100-b*50-c*20-d*10-e*5)/2;
    g=(t-a*100-b*50-c*20-d*10-e*5-f*2);
    printf("100 - %d\n50 - %d\n20 - %d\n10 - %d\n5 - %d\n2 - %d\n1 - %d\n",a,b,c,d,e,f,g);
    return 0;
}