#include <stdio.h>
#include <stdlib.h>

int main()
{
    char A[100]= {'\0'},Ops[10][10]= {'\0'};
    int p=0,q=0,a=0;
    scanf("%s",A);
    for(int i=0; i<100; i++)
    {
        if(A[i]=='\0')
            break;
        if((A[i]!='+')&&(A[i]!='-')&&(A[i]!='*')&&(A[i]!='/')&&(A[i]!='(')&&(A[i]!=')'))
        {
            Ops[p][q]=A[i];
            q++;
            a=1;
        }
        else
        {
            if(!a)
                continue;
            p++;
            q=0;
            a=0;
        }
    }
    for(int i=0; i<10; i++)
    {
        if(Ops[i][0]=='\0')
            break;
        for(int j=0; j<10; j++)
        {

            if(Ops[i][j]!='\0')
                printf("%c",Ops[i][j]);
            else
            {
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
