#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[10]= {0};
    for(int i=0; i<10; i++)
        scanf("%d",&A[i]);
    for(int i=1; i<=10; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(A[j]>A[j+1])
            {
                A[j]+=A[j+1];
                A[j+1]=A[j]-A[j+1];
                A[j]-=A[j+1];
            }
        }
    }
    for(int i=0; i<10; i++)
        printf("%d\t",A[i]);
    return 0;
}
