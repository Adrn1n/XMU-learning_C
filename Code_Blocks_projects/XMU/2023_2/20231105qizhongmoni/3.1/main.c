#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[101]= {'\0'},a='A';
    int s=0;
    scanf("%s",A);
    for(int i=0; i<101; i++)
    {
        if(A[i]=='\0')
            break;
        if(A[i]!=a)
        {
            if(s)
            {
                printf("%c",a);
                printf("%d ",s);
            }
            a=A[i];
            s=1;
        }
        else
            s++;
    }
    printf("%c",a);
    printf("%d ",s);
    return 0;
}
