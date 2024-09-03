#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Strcmp(char * p1,char * p2)
{
    int k=0;
    char *p=p1,*q=p2;
    for(; (*p)||(*q); p++,q++)
    {
        if(*p-*q)
            k=*p-*q;
    }
    return k;
}

int main()
{
    int m=0,n=0;
    scanf("%u%u",&m,&n),getchar();
    char p1[m],p2[n];
    fgets(p1,m,stdin),fgets(p2,n,stdin);
    int k=Strcmp(p1,p2);
    printf("%d",k);
    return 0;
}
