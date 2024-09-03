/*
计算线段长度
描述

文学青年小鲁想学习编程，他去请教小华自己该如何入门。

小华说：想学编程，得从基础开始！这样吧，先给你出道简单题：

计算一下直角坐标系中以两点M(mx,my), N(nx,ny)为端点的线段长度。


输入
第一行输入正整数n,代表有n个测试实例。

第二行开始输入n行，每行代表一个测试实例。包含由空格分开的4个实数，分别表示mx,my,nx,ny。


输出
对于每组输入数据，输出一行，结果保留两位小数。


输入样例 1

2
0 0 0 1
0 3 6 4
输出样例 1

1.00
6.08
来源

5DG在线编程 http://122.51.69.77
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    unsigned int n=0;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        double m_x=0,m_y=0,n_x=0,n_y=0;
        scanf("%lf%lf%lf%lf",&m_x,&m_y,&n_x,&n_y);
        double l=sqrt((m_x-n_x)*(m_x-n_x)+(m_y-n_y)*(m_y-n_y));
        printf("%.2lf\n",l);
    }
    return 0;
}
