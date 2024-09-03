#include <stdio.h>
#include <stdlib.h>

int adjust(double A[],unsigned int n,unsigned int m)
{
    if(m<=n)
    {
        for(unsigned int i=0; i<m; i++)
        {
            for(double *p=A; p<A+n-1; p++)
            {
                *p+=*(p+1);
                *(p+1)=*p-*(p+1);
                *p-=*(p+1);
            }
        }
        return 0;
    }
    else
        return 1;
}

int main()
{
    unsigned int n=0,m=0;
    scanf("%u%u",&n,&m);
    double A[n];
    for(double *p=A; p<A+n; p++)
        scanf("%lf",p);
    int k=adjust(A,n,m);
    if(!k)
    {
        for(double *p=A; p<A+n; p++)
            printf("%.2f ",*p);
    }
    else
        printf("ERROR!");
    printf("\n");
    return 0;
}
