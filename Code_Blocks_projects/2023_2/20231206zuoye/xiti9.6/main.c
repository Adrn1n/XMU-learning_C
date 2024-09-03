#include <stdio.h>
#include <stdlib.h>

struct Person
{
    struct Person *last;
    char name[101];
    unsigned int number;
    struct Person *next;
};

struct Person *add_person(struct Person *LAST,unsigned int i)
{
    struct Person *p=malloc(sizeof(struct Person));
    if (LAST)
        LAST->next=p,p->last=LAST;
    else
        p->last=NULL;
    printf("NAME: "),scanf("%s",p->name);
    p->number=i;
    p->next=NULL;
    return p;
}

int main()
{
    unsigned int n=0,m=0;
    printf("TOTAL = "),scanf("%u",&n);
    printf("NUMBER OUT = "),scanf("%u",&m);
    struct Person *HEAD=NULL,*p=NULL;
    for(int i=0; i<n; i++)
        if (p)
            p=add_person(p,i+1);
        else
            p=HEAD=add_person(HEAD,i+1);
    p=HEAD;
    for(int i=0; i<n; i++)
    {
        if(!((i+1)%m))
        {
            if(p==HEAD)
            {
                HEAD=p->next;
                if(HEAD)
                    HEAD->last=NULL;
                free(p),p=HEAD;
            }
            else
            {
                (p->last)->next=p->next,p=p->next;
                if(p)
                    free(p->last);
            }
            continue;
        }
        p=p->next;
    }
    p=HEAD;
    if(HEAD)
        do
            printf("%u : %s\n",p->number,p->name),p=p->next;
        while(p);
    else
        printf("0\n");
    return 0;
}
