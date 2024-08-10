#include <stdio.h>
#include <stdlib.h>

struct YMD
{
    int y;
    int m;
    int d;
} a= {0,0,0};

int days(struct YMD *p)
{
    int D=p->d;
    switch(p->m)
    {
    case 12:
        D+=30;
    case 11:
        D+=31;
    case 10:
        D+=30;
    case 9:
        D+=31;
    case 8:
        D+=31;
    case 7:
        D+=30;
    case 6:
        D+=31;
    case 5:
        D+=30;
    case 4:
        D+=31;
    case 3:
        if((!((p->y))%4)&&((p->y)%100)||(!((p->y)%400)))
            D+=29;
        else
            D+=28;
    case 2:
        D+=31;
    }
    return D;
}

int main()
{
    struct YMD *p=&a;
    printf("YEAR: "),scanf("%d",&(p->y));
    printf("MOUNTH: "),scanf("%d",&(p->m));
    printf("DAY: "),scanf("%d",&(p->d));
    int D=days(p);
    printf("Days = %d\n",D);
    return 0;
}
