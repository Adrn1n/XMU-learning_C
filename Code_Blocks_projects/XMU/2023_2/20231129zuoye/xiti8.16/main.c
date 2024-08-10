#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int int_in_str(char *A,int N[])
{
    unsigned int s=0,k=1;
    int *n=N-1;
    for(char *p=A; *p; p++)
    {
        if((*p>='0')&&(*p<='9'))
        {
            if(k)
            {
                s++;
                n++;
            }
            if((p>A)&&(*(p-1)=='-'))
                *n=-(*p-'0');
            else
            {
                if(*n>=0)
                    *n=(*n)*10+(*p-'0');
                else
                    *n=(*n)*10-(*p-'0');
            }
            k=0;
        }
        else
            k=1;
    }
    return s;
}

int main()
{
    int n=0;
    scanf("%u",&n),getchar();
    char A[n];
    fgets(A,n,stdin);
    unsigned int m=strlen(A);
    int N[(m/2)+1];
    for(int *p=N; p<N+(m/2)+1; p++)
        *p=0;
    unsigned int s=int_in_str(A,N);
    printf("%u\n",s);
    for(int *p=N; p<N+s; p++)
        printf("%d ",*p);
    if(s)
        printf("\n");
    return 0;
}
