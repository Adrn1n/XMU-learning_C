/*
第3关：数据排序

任务描述
本关任务：编写一个代码程序解决数据排序问题。

相关知识
按一定顺序给定n个学生数据“学号 语文成绩 数学成绩 英语成绩 物理成绩 化学成绩 生物成绩”，现在让你按其中某一成绩从大到小排序（询问1按语文成绩排序，询问2按数学成绩排序，询问3按英语成绩排序，询问4按物理成绩排序，询问5按化学成绩排序，询问6按生物成绩排序），若成绩相同，学号小的排在前面。输出排序后每个同学之前在原数据中的位置（约定第一个读入数据的同学为1，最后一个读入数据的同学为N）。

注意：学号的数值超过int类型表示的最大范围，请使用字符数组或者long long存储。

输入描述
输入的第一行是一个整数N，代表有N个学生数据。（N≤1000）

接下来每一行一次输入学号、语文成绩、数学成绩、英语成绩、物理成绩、化学成绩、生物成绩，其中学号是一个十四位整数，成绩是一个范围[0，100]的整数。

再一行输入一个询问整数K∈{1,2,3,4,5,6}，表示按第K种成绩排序，如题目所述。
输出描述
输出N行，代表排序后每个同学在原数据中所处的位置，即这个同学在原数据中是第几行。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决数据排序问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：

3
23020102203458 70 50 30 60 80 90
23020102203457 50 60 70 80 90 100
23020102203456 70 60 50 30 20 80
2
预期输出：

3
2
1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Grades {C,M,ENG,PHY,CHEM,BIO,n_Grades};

/*
struct Student
{
    char num[15];
    int ord,c,m,eng,phy,chem,bio;
    struct Student *next;
};
*/

typedef struct Student
{
    char num[15];
    int ord,grades[n_Grades];
    struct Student *next;
} Student;

//struct Student *add_student(char *num,int ord,int c,int m,int eng,int phy,int chem,int bio,struct Student *LAST)
Student *add_student(char *num,int ord,int grades[],Student *LAST)
{
    /*
    if(LAST)
    {
        struct Student *p=malloc(sizeof(struct Student));
        LAST->next=p;
        strcpy(p->num,num),p->ord=ord,p->c=c,p->m=m,p->eng=eng,p->phy=phy,p->chem=chem,p->bio=bio,p->next=NULL;
        return p;
    }
    else
    {
        struct Student *p=malloc(sizeof(struct Student));
        strcpy(p->num,num),p->ord=ord,p->c=c,p->m=m,p->eng=eng,p->phy=phy,p->chem=chem,p->bio=bio,p->next=NULL;
        return p;
    }
    */
    Student *p=malloc(sizeof(Student));
    strcpy(p->num,num),p->ord=ord,*(p->grades+C)=*(grades+C),*(p->grades+M)=*(grades+M),*(p->grades+ENG)=*(grades+ENG),*(p->grades+PHY)=*(grades+PHY),*(p->grades+CHEM)=*(grades+CHEM),*(p->grades+BIO)=*(grades+BIO),p->next=NULL;
    if(LAST)
        LAST->next=p;
    return p;
}

//struct Student *swap_student(struct Student *f,struct Student *b,struct Student *f_p,struct Student *b_p)
Student *swap_student(Student *f,Student *b,Student *f_p,Student *b_p)
{
    if(f!=b_p)
    {
        b_p->next=b->next,b->next=f->next;
        f->next=b_p->next,b_p->next=f;
        if(f_p)
            f_p->next=b;
    }
    else
    {
        f->next=b->next,b->next=f;
        if(f_p)
            f_p->next=b;
    }
    return b;
}

int main()
{
    unsigned int N=0;
    scanf("%u",&N);
    //struct Student *HEAD=NULL,*p=NULL;
    Student *HEAD=NULL,*p=NULL;
    for(int i=0; i<N; i++)
    {
        char num[15]= {0};
        //int c=0,m=0,eng=0,phy=0,chem=0,bio=0;
        int grades[n_Grades]= {0};
        scanf("%s",num),scanf("%d%d%d%d%d%d",grades+C,grades+M,grades+ENG,grades+PHY,grades+CHEM,grades+BIO);
        p=add_student(num,i+1,grades,p);
        if(!i)
            HEAD=p;
    }
    /*
    unsigned int K=0;
    scanf("%u",&K);
    */
    unsigned short K=0;
    scanf("%hu",&K);
    K--;
    //struct Student *f_p=NULL,*f=HEAD,*b_p=HEAD,*b=HEAD->next,*temp=NULL;
    if(N>1)
        for(Student *f_p=NULL,*f=HEAD; f; f=f->next)
        {
            for(Student *b=f->next,*b_p=f,*temp=NULL; b; b_p=b_p->next,b=b->next)
                if(*(f->grades+K)<*(b->grades+K))
                {
                    if(f_p==NULL)
                        HEAD=swap_student(f,b,f_p,b_p);
                    else
                        swap_student(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                else if(*(f->grades+K)==*(b->grades+K))
                    if(strcmp(f->num,b->num)>0)
                    {
                        if(f_p==NULL)
                            HEAD=swap_student(f,b,f_p,b_p);
                        else
                            swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
            if(f_p==NULL)
                f_p=HEAD;
            else
                f_p=f_p->next;
        }
    /*
    if(K==1)
    {
        for(; f; f=f->next)
        {
            b=f->next,b_p=f;
            if(f_p==NULL)
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->c<b->c)
                    {
                        HEAD=swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->c==b->c)
                        if(strcmp(f->num,b->num)>0)
                        {
                            HEAD=swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=HEAD;
            }
            else
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->c<b->c)
                    {
                        swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->c==b->c)
                        if(strcmp(f->num,b->num)>0)
                        {
                            swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=f_p->next;
            }
        }
    }
    else if(K==2)
    {
        for(; f; f=f->next)
        {
            b=f->next,b_p=f;
            if(f_p==NULL)
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->m<b->m)
                    {
                        HEAD=swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->m==b->m)
                        if(strcmp(f->num,b->num)>0)
                        {
                            HEAD=swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=HEAD;
            }
            else
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->m<b->m)
                    {
                        swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->m==b->m)
                        if(strcmp(f->num,b->num)>0)
                        {
                            swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=f_p->next;
            }
        }
    }
    else if(K==3)
    {
        for(; f; f=f->next)
        {
            b=f->next,b_p=f;
            if(f_p==NULL)
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->eng<b->eng)
                    {
                        HEAD=swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->eng==b->eng)
                        if(strcmp(f->num,b->num)>0)
                        {
                            HEAD=swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=HEAD;
            }
            else
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->eng<b->eng)
                    {
                        swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->eng==b->eng)
                        if(strcmp(f->num,b->num)>0)
                        {
                            swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=f_p->next;
            }
        }
    }
    else if(K==4)
    {
        for(; f; f=f->next)
        {
            b=f->next,b_p=f;
            if(f_p==NULL)
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->phy<b->phy)
                    {
                        HEAD=swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->phy==b->phy)
                        if(strcmp(f->num,b->num)>0)
                        {
                            HEAD=swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=HEAD;
            }
            else
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->phy<b->phy)
                    {
                        swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->phy==b->phy)
                        if(strcmp(f->num,b->num)>0)
                        {
                            swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=f_p->next;
            }
        }
    }
    else if(K==5)
    {
        for(; f; f=f->next)
        {
            b=f->next,b_p=f;
            if(f_p==NULL)
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->chem<b->chem)
                    {
                        HEAD=swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->chem==b->chem)
                        if(strcmp(f->num,b->num)>0)
                        {
                            HEAD=swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=HEAD;
            }
            else
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->chem<b->chem)
                    {
                        swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->chem==b->chem)
                        if(strcmp(f->num,b->num)>0)
                        {
                            swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=f_p->next;
            }
        }
    }
    else if(K==6)
    {
        for(; f; f=f->next)
        {
            b=f->next,b_p=f;
            if(f_p==NULL)
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->bio<b->bio)
                    {
                        HEAD=swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->bio==b->bio)
                        if(strcmp(f->num,b->num)>0)
                        {
                            HEAD=swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=HEAD;
            }
            else
            {
                for(; b; b_p=b_p->next,b=b->next)
                    if(f->bio<b->bio)
                    {
                        swap_student(f,b,f_p,b_p);
                        if(b_p==f)
                            b_p=b;
                        temp=f,f=b,b=temp;
                    }
                    else if(f->bio==b->bio)
                        if(strcmp(f->num,b->num)>0)
                        {
                            swap_student(f,b,f_p,b_p);
                            if(b_p==f)
                                b_p=b;
                            temp=f,f=b,b=temp;
                        }
                f_p=f_p->next;
            }
        }
    }
    */
    /*
    p=HEAD;
    for(int i=0; i<N; i++)
    {
        printf("%d\n",p->ord);
        p=p->next;
    }
    */
    if(N)
        for(p=HEAD; p; p=p->next)
            printf("%d\n",p->ord);
    return 0;
}
