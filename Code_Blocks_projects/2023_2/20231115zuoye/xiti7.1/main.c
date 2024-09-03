#include <stdio.h>
#include <stdlib.h>

int GCD(int x,int y)
{
    if(x<y)
    {
        x+=y;
        y=x-y;
        x-=y;
    }
    int t=x;
    while(y>1)
    {
        t=x;
        x=y;
        y=t%x;
    }
    return x;
}

int LCM(int x,int y)
{
    x=x*y/GCD(x,y);
    return x;
}

int main()
{
    int a=0,b=0,c=0;
    scanf("%d%d",&a,&b);
    c=GCD(a,b);
    printf("GCD = %d\n",c);
    c=LCM(a,b);
    printf("LCM = %d\n",c);
    return 0;
}
