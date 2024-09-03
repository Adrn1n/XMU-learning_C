#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int m=0,n=0,i=0;
    scanf("%u%u",&m,&n);
    char A[m],B[n];
    getchar();
    fgets(A,m,stdin);
    fgets(B,n,stdin);
    do
    {
        A[i]=B[i];
        i++;
    }
    while((i<m-1)||(i<n-1)||B[i]);
    printf("%s\n",A);
    return 0;
}
