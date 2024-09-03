#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n=0;
    scanf("%u",&n);
    int A[n],t=0;
    for(int i=0; i<n; i++)
        scanf("%d",&A[i]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(A[j]>A[j+1])
            {
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(A[i])
        {
            t=A[i];
            A[i]=A[0];
            A[0]=t;
            break;
        }
    }
    for(int i=0; i<n; i++)
        printf("%d",A[i]);
    return 0;
}
