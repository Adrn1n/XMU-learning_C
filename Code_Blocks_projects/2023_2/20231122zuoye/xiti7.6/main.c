#include <stdio.h>
#include <stdlib.h>

void str_add(char A[],char B[],unsigned int a,unsigned int b,char C[])
{
    for(int i=0; i<a; i++)
        C[i]=A[i];
    for(int i=0; i<b; i++)
        C[a+i]=B[i];
}

int main()
{
    unsigned int m=0,n=0;
    scanf("%u%u",&m,&n),getchar();
    char A[m],B[n];
    int k=0;
    if(m>n)
        k=1;
    if(k)
    {
        for(int i=0; i<n; i++)
            A[i]=B[i]=0;
        for(int i=n; i<m; i++)
            A[i]=0;
    }
    for(int i=0; i<m; i++)
        A[i]=B[i]=0;
    for(int i=m; i<n; i++)
        B[i]=0;
    fgets(A,m,stdin),fgets(B,n,stdin);
    unsigned int a=0,b=0;
    for(int i=0; i<k?n:m; i++)
    {
        if(!(A[i]))
        {
            a=--i;
            break;
        }
        if(!(B[i]))
        {
            b=--i;
            break;
        }
    }
    if(a)
    {
        for(int i=a; i<k?m:n; i++)
        {
            if(!(B[i]))
            {
                b=--i;
                break;
            }
        }
    }
    else
    {
        for(int i=b-1; i<k?m:n; i++)
        {
            if(!(A[i]))
            {
                a=--i;
                break;
            }
        }
    }
    char C[a+b+1];
    C[a+b]=0;
    str_add(A,B,a,b,C);
    printf("%s\n",C);
    return 0;
}
