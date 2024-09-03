#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100,b=0,c=0,d=0;
    for(a; a<1000; a++)
    {
        /*
        b=a/100;
        c=(a-(a/100)*100)/10;
        d=(a-b*100-c*10)/1;
        */
        b=a%10;
        c=(a/10)%10;
        d=(a/100)%10;
        if(a==b*b*b+c*c*c+d*d*d)
            printf("%d\n",a);
    }
    return 0;
}
