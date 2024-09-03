#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n=0;
    scanf("%u",&n);
    double A[n],t=0;
    for(int i=0; i<n; i++)
        scanf("%lf",&A[i]);
    for(int i=0; i<n; i++)
        printf("%.2f\t",A[i]);
    printf("\n");
    for(int i=0; i<=(n-1)/2; i++)
    {
        t=A[i];
        A[i]=A[n-1-i];
        A[n-1-i]=t;
    }
    for(int i=0; i<n; i++)
        printf("%.2f\t",A[i]);
    printf("\n");
    return 0;
}
