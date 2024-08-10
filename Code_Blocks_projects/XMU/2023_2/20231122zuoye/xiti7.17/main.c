#include <stdio.h>
#include <stdlib.h>

void ItoC(int a,unsigned int n,char A[])
{
    if(a>=0)
    {
        if(n>1)
        {
            A[--n]=(a%10)+'0';
            a/=10;
            ItoC(a,n,A);
        }
        else
            A[0]=a+'0';
    }
    else
    {
        ++n;
        A[0]='-';
        if(n>2)
        {
            A[--n]=((-a)%10)+'0';
            a=-((-a)/10);
            n--;
            ItoC(a,n,A);
        }
        else
            A[1]=(-a)+'0';
    }
}

int main()
{
    int a=0,b=0;
    scanf("%d",&a);
    if(a<0)
        b=-a;
    else
        b=a;
    unsigned int n=2;
    for(int i=1; (b/i)>0; i*=10)
        n++;
    char A[n];
    A[--n]=0,A[--n]=0;
    ItoC(a,n,A);
    printf("%s\n",A);
    return 0;
}
