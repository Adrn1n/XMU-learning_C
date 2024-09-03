#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    scanf("%d",&a);
    //if (a>=90)
    if(a>=90)
        printf("A");
    //else if (a>=80)
    else if(a>=80)
        printf("B");
    //else if (a>=70)
    else if(a>=70)
        printf("C");
    //else if (a>=60)
    else if(a>=60)
        printf("D");
    else
        printf("E");
    return 0;
}
