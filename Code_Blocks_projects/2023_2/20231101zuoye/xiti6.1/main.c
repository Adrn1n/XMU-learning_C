#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    int c=0;
    for(int a=2; a<=100; a++)
    {
        for(int b=2; b<a; b++)
        {
            if(!(a%b))
            {
                c=1;
                break;
            }
        }
        if(!c)
            printf("%d\n",a);
        c=0;
    }
    */
    int A[100]= {0};
    for(int i=1; i<100; i++)
    {
        if(!A[i])
        {
            printf("%d\n",i+1);
            /*
            for(int j=1; ((i+1)*j-1)<100; j++)
                A[(i+1)*j-1]=1;
                */
            for(int j=i; j<100; j+=(i+1))
                A[j]=1;
        }
    }
    return 0;
}
