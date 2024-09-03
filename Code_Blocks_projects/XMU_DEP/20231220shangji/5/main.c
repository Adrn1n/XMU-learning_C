/*
第5关：寻找最大内角

任务描述
本关任务：编写一个代码程序寻找最大内角。

相关知识
请定义Point结构体，Point结构体有两个int域代表点的坐标。现在给定N个点的坐标，问在这些点中任意选取3个点作为三角形，有可能得到的最大内角是多少。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。允许添加自定义函数。

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
double GetMaxAngle(struct Point pts[], int n)
{
}
//你的代码结束
//固定尾部开始
int main()
{
    int i, n;
    struct Point pts[50];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
       scanf("%d%d", &pts[i].x, &pts[i].y);
    printf("%.6f", GetMaxAngle(pts, n));
    return 0;
}
//固定尾部结束
输入描述
第一行输入一个整数N，代表点的个数。（N≤50）接下来N行每行两个整数X Y，代表每个点的坐标，（0≤X,Y≤1000），保证没有重叠点以及三点共线。

输出描述
输出一个实数，表示最大内角的度数，弧度制，保留6位小数。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序寻找最大内角。

余弦定理：c^2 = a^2 + b^2 − 2ab cos(C) 其中a、b、c是三角形的三条边，边c是角C的对边。

测试用例
平台会对你编写的代码进行测试：

测试输入：
4
0 0
5 5
3 5
4 6
预期输出：2.896614
*/

//固定头部开始
#include <stdio.h>
#include <math.h>
//固定头部结束
//你的代码开始
#define EPSILON 1e-10

/*
struct Point
{
    int x;
    int y;
};
*/

typedef struct Point
{
    int x;
    int y;
} Point;

double GetMaxAngle(struct Point pts[], int n)
{
    if(n>=3)
    {
        //double m=0,ang=0;
        double m=0;
        //for(struct Point *a=pts; a<pts+n; a++)
        for(Point *a=pts; a<pts+n; a++)
            //for(struct Point *b=pts; b<pts+n; b++)
            for(Point *b=pts; b<pts+n; b++)
                if(b!=a)
                    //for(struct Point *c=pts; c<pts+n; c++)
                    for(Point *c=pts; c<pts+n; c++)
                        if((c!=a)&&(c!=b))
                        {
                            double x_1=b->x-a->x,x_2=c->x-a->x,y_1=b->y-a->y,y_2=c->y-a->y,k=sqrt((x_1*x_1+y_1*y_1)*(x_2*x_2+y_2*y_2));
                            //if(k>1e-10)
                            if(k>EPSILON)
                            {
                                //ang=acos((x_1*x_2+y_1*y_2)/k);
                                double ang=acos((x_1*x_2+y_1*y_2)/k);
                                if(ang>m)
                                    m=ang;
                            }
                        }
        return m;
    }
    else
        return 0;
}
//你的代码结束
//固定尾部开始
int main()
{
    int i, n;
    struct Point pts[50];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d%d", &pts[i].x, &pts[i].y);
    printf("%.6f", GetMaxAngle(pts, n));
    return 0;
}
//固定尾部结束
