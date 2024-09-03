#include <stdio.h>
#include <stdlib.h>

int if_prime(int x)
{
    int k=1;
    if((x!=1)&&(x!=2))
    {
        for(int i=2; i<=0.5*x+1; i++)
        {
            if(!(x%i))
            {
                k=0;
                break;
            }
        }
    }
    else if(x==1)
        k=0;
    else if(x==2)
        k=1;
    return k;
}

int main()
{
    int a=0;
    scanf("%d",&a);
    a=if_prime(a);
    printf("%d\n",a);
    return 0;
}
