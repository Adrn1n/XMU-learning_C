#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int m=0,n=0,p=0,k=0;
    scanf("%u%u",&m,&n);
    char A[m],B[n];
    getchar();
    fgets(A,m,stdin);
    fgets(B,n,stdin);
    for(int i=0; i<m; i++)
    {
        if(A[i]=='\n')
            k=1;
        if(k&&(B[p]!='\n'))
        {
            A[i]=B[p];
            p++;
        }
        if(B[p]=='\n')
            break;
    }
    printf("%s\n",A);
    return 0;
}
