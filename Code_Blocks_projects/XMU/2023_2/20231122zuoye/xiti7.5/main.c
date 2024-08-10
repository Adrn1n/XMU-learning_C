#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_str(char A[],unsigned int n)
{
    for(int i=0; i<n/2; i++)
    {
        char c=A[i];
        A[i]=A[n-1-i];
        A[n-1-i]=c;
    }
}

int main()
{
    unsigned int m=0;
    scanf("%u",&m),getchar();
    char A[m+1];
    for(int i=0; i<m+1; i++)
        A[i]=0;
    fgets(A,m,stdin);
    unsigned int n=strlen(A);
    A[--n]=0;
    reverse_str(A,n);
    printf("%s\n",A);
    return 0;
}
