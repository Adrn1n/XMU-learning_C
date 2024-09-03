#include <stdio.h>
#include <stdlib.h>

void print_digits(int x)
{
    int k=0,a=0;
    char c=0;
    for(int i=1E4; i>=1; i/=10)
    {
        a=x/i;
        x=x-a*i;
        if(a)
            k=1;
        if(k)
        {
            c=a+'0';
            printf("%c ",c);
        }
    }
    printf("\n");
}


int main()
{
    int a=0;
    scanf("%d",&a);
    print_digits(a);
    return 0;
}
