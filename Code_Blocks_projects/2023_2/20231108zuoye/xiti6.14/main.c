#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int n=0;
    int d=0;
    scanf("%d",&n);
    char A[n],B[n];
    for(int i=0; i<n; i++)
        A[i]=B[i]=0;
    getchar();
    fgets(A,n,stdin);
    fgets(B,n,stdin);
    for(int i=0; i<n; i++)
    {
        d=(int)(A[i])-(int)(B[i]);
        if(d)
            break;
    }
    printf("%d\n",d);
    return 0;
}
