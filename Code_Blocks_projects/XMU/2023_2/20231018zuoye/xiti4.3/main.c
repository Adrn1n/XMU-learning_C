#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=3,b=4,c=5,d,e,f,g,h,x,y=0;
    d=(a+b>c)&&(b==c);
    printf("%d",d);
    e=(a||b+c)&&(b-c);
    printf("%d",e);
    f=(!(a>b))&&(!c||1);
    printf("%d",f);
    g=(!(x=a))&&((y=b)&&0);
    printf("%d",g);
    h=(!(a+b)+c-1)&&(b+c/2);
    printf("%d",h);
    return 0;
}
