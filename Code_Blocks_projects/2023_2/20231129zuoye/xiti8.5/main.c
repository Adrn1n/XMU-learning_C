#include <stdio.h>
#include <stdlib.h>

unsigned int count_left(char *A,unsigned int m,unsigned int n,unsigned int k)
{
    unsigned int l=n;
    for(char *p=A; p<A+m*n; p+=m)
    {
        if(!((((p-A)/m)+1)%k))
        {
            *p=0;
            l--;
        }
    }
    return l;
}

int main()
{
    unsigned int m=0,n=0;
    scanf("%u%u",&m,&n);
    char A[n][m];
    for(char *p=A[0]; p<A[0]+n*m; p+=m)
        scanf("%s",p);
    unsigned int k=0;
    scanf("%u",&k);
    unsigned int l=count_left(A[0],m,n,k);
    printf("%u\n",l);
    for(char *p=A[0]; p<A[0]+n*m; p+=m)
    {
        if(*p)
            printf("%lld : %s\n",((p-A[0])/m)+1,p);
    }
    return 0;
}
