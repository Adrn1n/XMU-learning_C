/*
成绩分区
描述

教育是一个民族要崛起的必备条件。小嘉排除万难，创办学校。

艰苦创校期，小嘉自己身兼数职，既是校长，又是后勤总管，既要为办校募款，又要为学校广罗人才。

于此同时，还要亲自在一线教学，评估学生的学习状况。

小嘉每学期最重要的工作之一就是评估每个学生的学习成绩属于哪个档次，并且根据原始数据调整新学期的教学方案和人才引进方案。

给定一个[0,100]之间的浮点数Score，请你判断该数字属于以下哪个区间：

A:[90,100] B:[80,90) C:[70,80) D:[60,70) E:[0,60)

如果Score小于0或大于100，则程序输出“Wrong Score!”，表示超出范围。

开区间(a,b):  在实数a和实数b之间的所有实数，但不包含a和b。

闭区间[a,b]：在实数a和实数b之间的所有实数，包含a和b。


输入
输入数据有n行，每行是一个浮点数Score，代表学生的综合成绩。


输出
对于每行输入数据，请判定该数Score落在哪个区间，并且输出完整区间。

例如

输入数据是99.9 程序输出 A:[90,100]

输入数据是85，程序输出 B:[80,90)

若输入数据不在[0,100]区间内，程序输出：“Wrong Score!”。


输入样例 1

99.9
88.8
77.7
66.6
55.5
-77.7
输出样例 1

A:[90,100]
B:[80,90)
C:[70,80)
D:[60,70)
E:[0,60)
Wrong Score!
来源

5DG在线编程 http://122.51.69.77
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    double score=0;
    while((scanf("%lf",&score))!=EOF)
    {
        int flag=(int)(score/10);
        switch(flag)
        {
        case 10:
        case 9:
            if(score<=100)
                printf("A:[90,100]\n");
            else
                printf("Wrong Score!\n");
            break;
        case 8:
            printf("B:[80,90)\n");
            break;
        case 7:
            printf("C:[70,80)\n");
            break;
        case 6:
            printf("D:[60,70)\n");
            break;
        default:
            if((score>=0)&&(score<=100))
                printf("E:[0,60)\n");
            else
                printf("Wrong Score!\n");
        }
    }
    return 0;
}
