#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int max_word(char A[],unsigned int n,char B[])
{
    unsigned int S=0,s=0;
    for(int i=0; i<n; i++)
    {
        if(((A[i]>='A')&&(A[i]<='Z'))||((A[i]>='a')&&(A[i]<='z')))
            s++;
        else
        {
            if(s>S)
            {
                S=s;
                for(int j=0; j<S; j++)
                    B[j]=A[i-S+j];
            }
            s=0;
        }
    }
    return S;
}

int main()
{
    unsigned int m=0;
    scanf("%u",&m),getchar();
    char A[m],B[m];
    for(int i=0; i<m; i++)
        A[i]=B[i]=0;
    fgets(A,m,stdin);
    unsigned int n=strlen(A);
    max_word(A,n,B);
    printf("%s\n",B);
    return 0;
}
