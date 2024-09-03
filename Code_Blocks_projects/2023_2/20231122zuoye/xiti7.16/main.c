#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int HtoD(char A[],unsigned int n)
{
    unsigned int s=0,a=1;
    for(int i=n-1; i>=0; i--)
    {
        if((A[i]>='0')&&(A[i]<='9'))
            s+=(A[i]-'0')*a;
        else if((A[i]>='A')&&(A[i]<='F'))
            s+=((A[i]-'A')+10)*a;
        else
            s+=((A[i]-'a')+10)*a;
        a*=16;
    }
    return s;
}

int main()
{
    unsigned int m=0;
    scanf("%u",&m),getchar();
    char A[m];
    for(int i=0;i<m;i++)
        A[i]=0;
    scanf("%s",A);
    unsigned int n=strlen(A),s=HtoD(A,n);
    printf("%u\n",s);
    return 0;
}
