#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n=0;
    scanf("%u",&n);
    double A[n+1];
    for(int i=0; i<n; i++)
        scanf("%lf",&A[i]);
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(A[j]>A[j+1])
            {
                A[j]+=A[j+1];
                A[j+1]=A[j]-A[j+1];
                A[j]-=A[j+1];
            }
        }
    }
    for(int i=0; i<n; i++)
        printf("%.2f\t",A[i]);
    printf("\n");
    scanf("%lf",&A[n]);
    for(int i=0; i<n; i++)
    {
        if(A[n]<A[i])
        {
            for(int j=i; j<n; j++)
            {
                A[n]+=A[j];
                A[j]=A[n]-A[j];
                A[n]-=A[j];
            }
            break;
        }
    }
    for(int i=0;i<n+1;i++)
        printf("%.2f\t",A[i]);
    printf("\n");
    return 0;
}
