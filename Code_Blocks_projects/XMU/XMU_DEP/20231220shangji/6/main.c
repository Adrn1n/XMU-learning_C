/*
第6关：第K早之日

任务描述
本关任务：编写一个代码程序解决第K早之日问题。

相关知识
写一个结构体变量（包括年月日），输入N（1≤N≤1000）个年/月/日信息，用链表保证其有序，再输入一个k，输出排序后的第k个日期，即给定输入的时间最早的第k天。

输入描述
第一行输入一个整数N，表示给定的天数。接下来N行，每行给出形如YYYY/MM/DD的格式，代表YYYY年MM月DD日。（例如：1991/06/21，0123/02/01）最后一行一个整数K(1≤K≤N)，如题所述。

输出描述
仅一行，输出给定的日子里面第K早之日，输出格式与输入格式相同。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决第K早之日问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
4
1937/05/23
1991/02/15
1946/10/30
1999/06/09
2
预期输出：1946/10/30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct YMD
{
    char Y[5],M[3],D[3];
    struct YMD *next;
};
*/

typedef struct YMD
{
    char Y[5],M[3],D[3];
    struct YMD *next;
} YMD;

//struct YMD *add_day(char *y,char *m,char *d,struct YMD *LAST)
YMD *add_day(char *y,char *m,char *d,YMD *LAST)
{
    //struct YMD *p=malloc(sizeof(struct YMD));
    YMD *p=malloc(sizeof(YMD));
    strcpy(p->Y,y),strcpy(p->M,m),strcpy(p->D,d),p->next=NULL;
    if(LAST)
        LAST->next=p;
    return p;
}

//struct YMD *swap_day(struct YMD *f,struct YMD *b,struct YMD *f_p,struct YMD *b_p)
YMD *swap_day(YMD *f,YMD *b,YMD *f_p,YMD *b_p)
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
    scanf("%u",&N),getchar();
    //struct YMD *HEAD=NULL,*p=NULL;
    YMD *HEAD=NULL,*p=NULL;
    for(int i=0; i<N; i++)
    {
        char y[5]= {0},m[3]= {0},d[3]= {0},temp[11]= {0};
        scanf("%s",temp),getchar();
        strncpy(y,temp,4),strncpy(m,temp+5,2),strncpy(d,temp+8,2);
        p=add_day(y,m,d,p);
        if(!i)
            HEAD=p;
    }
    unsigned int K=0;
    scanf("%u",&K);
    //for(struct YMD *f_p=NULL,*f=HEAD; f; f=f->next)
    for(YMD *f_p=NULL,*f=HEAD; f; f=f->next)
    {
        //for(struct YMD *b_p=f,*b=f->next,*temp=NULL; b; b_p=b_p->next,b=b->next)
        for(YMD *b_p=f,*b=f->next,*temp=NULL; b; b_p=b_p->next,b=b->next)
            if(strcmp(f->Y,b->Y)>0)
            {
                /*
                if(f_p)
                {
                    swap_day(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                else
                {
                    HEAD=swap_day(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                */
                if(f_p)
                    swap_day(f,b,f_p,b_p);
                else
                    HEAD=swap_day(f,b,f_p,b_p);
                if(b_p==f)
                    b_p=b;
                temp=f,f=b,b=temp;
            }
            else if((!strcmp(f->Y,b->Y))&&(strcmp(f->M,b->M)>0))
            {
                /*
                if(f_p)
                {
                    swap_day(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                else
                {
                    HEAD=swap_day(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                */
                if(f_p)
                    swap_day(f,b,f_p,b_p);
                else
                    HEAD=swap_day(f,b,f_p,b_p);
                if(b_p==f)
                    b_p=b;
                temp=f,f=b,b=temp;
            }
            else if((!strcmp(f->Y,b->Y))&&(!strcmp(f->M,b->M))&&(strcmp(f->D,b->D)>0))
            {
                /*
                if(f_p)
                {
                    swap_day(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                else
                {
                    HEAD=swap_day(f,b,f_p,b_p);
                    if(b_p==f)
                        b_p=b;
                    temp=f,f=b,b=temp;
                }
                */
                if(f_p)
                    swap_day(f,b,f_p,b_p);
                else
                    HEAD=swap_day(f,b,f_p,b_p);
                if(b_p==f)
                    b_p=b;
                temp=f,f=b,b=temp;
            }
        if(f_p)
            f_p=f_p->next;
        else
            f_p=HEAD;
    }
    p=HEAD;
    /*
    for(int i=0; i<N; i++)
    {
        if(i+1==K)
            printf("%s/%s/%s\n",p->Y,p->M,p->D);
        p=p->next;
    }
    */
    if(p)
        for(int i=0; i<N; i++,p=p->next)
            if(i+1==K)
                printf("%s/%s/%s\n",p->Y,p->M,p->D);
    return 0;
}
