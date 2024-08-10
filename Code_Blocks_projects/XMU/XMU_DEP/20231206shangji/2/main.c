/*
第2关：简单的几何问题

任务描述
本关任务：编写一个代码程序解决简单的几何问题。

相关知识
写一个函数，给定半径r，计算对应圆的周长，圆的面积，球的表面积，以及球的体积，四舍五入保留两位小数。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。

//固定头部开始
#include <stdio.h>
//固定头部结束
//你的代码开始
void GetInfo(double r, double result[])
{
}
//你的代码结束
//固定尾部开始
int main() {
  double r, result[4];
  scanf("%lf", &r);
  GetInfo(r, result);
  printf("%.2f\n%.2f\n%.2f\n%.2f", result[0], result[1], result[2], result[3]);
  return 0;
}
//固定尾部结束
输入描述
输入只包含一行，一个实数r，代表半径，注意过程中所有变量应使用double类型。（0<r<100）

输出描述
输出4行，每行分别代表对应圆的周长，圆的面积，球的表面积，以及球的体积，保留两位小数。（π取3.14159）

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决简单的几何问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：1.1；
预期输出：
6.91
3.80
15.21
5.58
*/

//固定头部开始
#include <stdio.h>
//固定头部结束
//你的代码开始
void GetInfo(double r, double result[])
{
#define Pi 3.14159
    result[0]=2*Pi*r;
    result[1]=Pi*r*r;
    result[2]=4*Pi*r*r;
    result[3]=(4*Pi*r*r*r)/3;
}
//你的代码结束
//固定尾部开始
int main()
{
    double r, result[4];
    scanf("%lf", &r);
    GetInfo(r, result);
    printf("%.2f\n%.2f\n%.2f\n%.2f", result[0], result[1], result[2], result[3]);
    return 0;
}
//固定尾部结束
