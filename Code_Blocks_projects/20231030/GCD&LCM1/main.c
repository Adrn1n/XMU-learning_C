#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0,b=0,c=0,d=0,e=0;
    scanf("%d%d",&a,&b);
    c=a,d=b;
    if(c<d)
    {
        c+=d;
        d=c-d;
        c-=d;
    }
    while(d>0)
    {
        e=c;
        c=d;
        d=e%c;
    }
    printf("GCD = %d\n",c);
    e=a*b/c;
    printf("LCM = %d\n",e);
    return 0;
}
