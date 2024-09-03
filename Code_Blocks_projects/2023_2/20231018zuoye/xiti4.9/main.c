#include <stdio.h>
#include <stdlib.h>
//#include <math.h>

int main()
{
    int a=0,c=0,d=0,e=0,f=0,g=0,h=0;
    //double b=0;
    scanf("%d",&a);
    /*
    c=(int)(log10(a)+1);
    */
    //if (0<a&&a<10)
    if(0<a&&a<10)
        c=1;
    //else if (10<=a&&a<100)
    else if(10<=a&&a<100)
        c=2;
    //else if (100<=a&&a<1000)
    else if(100<=a&&a<1000)
        c=3;
    //else if (1000<=a&&a<10000)
    else if(1000<=a&&a<10000)
        c=4;
    else
        c=5;
    printf("\ndigits=%d\n\n",c);
    switch(c)
    {
    case 5:
        d=a/10000;
        a=a-d*10000;
        printf("%d\n",d);
    case 4:
        e=a/1000;
        a=a-e*1000;
        printf("%d\n",e);
    case 3:
        f=a/100;
        a=a-f*100;
        printf("%d\n",f);
    case 2:
        g=a/10;
        a=a-g*10;
        printf("%d\n",g);
    case 1:
        h=a/1;
        a=a-h*1;
        printf("%d\n\n",h);
    }
    //printf("%d\n%d\n%d\n%d\n%d\n\n",d,e,f,g,h);
    switch(c)
    {
    case 5:
        printf("%d%d%d%d%d\n",h,g,f,e,d);
        break;
    case 4:
        printf("%d%d%d%d\n",h,g,f,e);
        break;
    case 3:
        printf("%d%d%d\n",h,g,f);
        break;
    case 2:
        printf("%d%d\n",h,g);
        break;
    case 1:
        printf("%d\n",h);
        break;
    }
    return 0;
}
