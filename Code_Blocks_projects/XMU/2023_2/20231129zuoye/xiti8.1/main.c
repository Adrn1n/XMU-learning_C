#include <stdio.h>
#include <stdlib.h>

void ascendant_sort(double A[],unsigned int n)
{
    for(unsigned int i=0; i<n; i++)
    {
        double *p=A;
        for(; p<A+n-i-1; p++)
        {
            if(*p>*(p+1))
            {
                *p+=*(p+1);
                *(p+1)=*p-*(p+1);
                *p-=*(p+1);
            }
        }
    }
}

int main()
{
    unsigned int n=0;
    scanf("%u",&n);
    double A[n];
    for(double *p=A; p<A+n; p++)
        scanf("%lf",p);
    ascendant_sort(A,n);
    for(double *p=A; p<A+n; p++)
        printf("%.2f ",*p);
    printf("\n");
    return 0;
}
