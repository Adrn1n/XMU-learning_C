#include <stdio.h>
#include <stdlib.h>

int day_number(int x,int y,int z)
{
    int s=z;
    switch(y)
    {
    case 12:
        s+=30;
    case 11:
        s+=31;
    case 10:
        s+=30;
    case 9:
        s+=31;
    case 8:
        s+=31;
    case 7:
        s+=30;
    case 6:
        s+=31;
    case 5:
        s+=30;
    case 4:
        s+=31;
    case 3:
        if(((!(x%4))&&(x%100))||(!(x%400)))
            s+=29;
        else
            s+=28;
    case 2:
        s+=31;
    }
    return s;
}

int main()
{
    int a=0,b=0,c=0,n=0;
    scanf("%d,%d,%d",&a,&b,&c);
    n=day_number(a,b,c);
    printf("%d\n",n);
    return 0;
}
