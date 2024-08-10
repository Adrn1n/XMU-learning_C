#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a=1,b=2,s=0;
    for(int i=1;i<=20;i++)
    {
        s+=(a/b);
        a+=b;
        b+=a;
    }
    printf("%f",s);
    return 0;
}
