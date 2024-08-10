#include <stdio.h>
#include <stdlib.h>

struct Student
{
    struct Student *last;
    unsigned int stdnum;
    double grade;
    struct Student *next;
};

struct Student *add_student(struct Student *LAST)
{
    struct Student *p=malloc(sizeof(struct Student));
    if(LAST)
        LAST->next=p,p->last=LAST;
    else
        p->last=NULL;
    printf("STUDENT NUMBER: "),scanf("%u",&(p->stdnum));
    printf("GRADE: "),scanf("%lf", &(p->grade));
    p->next=NULL;
    return p;
}

int main()
{
    unsigned int n0=0,n1=0;
    printf("N1 = "),scanf("%u", &n0),printf("N2 = "),scanf("%u", &n1);
    struct Student *HEAD0=NULL,*p0=NULL,*HEAD1=NULL,*p1=NULL;
    for(int i=0; i<n0; i++)
        if(p0)
            p0=add_student(p0);
        else
            p0=HEAD0=add_student(HEAD0);
    for(int i=0; i<n1; i++)
        if(p1)
            p1=add_student(p1);
        else
            p1=HEAD1=add_student(HEAD1);
    p0->next=HEAD1,HEAD1->last=p0;
    printf("\n\n");
    p0=HEAD0,p1=HEAD1;
    for(int i=0; i<n0; i++,p0=p0->next)
        printf("GROUP1: STUDENT NUMBER: %u\tGRADE: %.2lf\n",p0->stdnum,p0->grade);
    printf("\n");
    for(int i=0; i<n1; i++,p1=p1->next)
        printf("GROUP2: STUDENT NUMBER: %u\tGRADE: %.2lf\n",p1->stdnum,p1->grade);
    printf("\n\n");
    for(int i=0; i<n0+n1; i++)
    {
        p0=HEAD0;
        p1=HEAD0->next;
        for(int j=0; j<n0+n1-i-1; j++)
        {
            if(p0->stdnum>p1->stdnum)
            {
                p0->next=p1->next,p1->last=p0->last;
                p0->last=p1,p1->next=p0;
                if(!(p1->last))
                    HEAD0=p1;
                else
                    (p1->last)->next=p1;
                if(p0->next)
                    (p0->next)->last=p0;
                struct Student *temp=p0;
                p0=p1,p1=temp;
            }
            p0=p0->next,p1=p1->next;
        }
    }
    p0=HEAD0;
    for(int i=0; i<n0+n1; i++,p0=p0->next)
        printf("STUDENT NUMBER: %u\nGRADE: %.2lf\n\n",p0->stdnum,p0->grade);
    return 0;
}
