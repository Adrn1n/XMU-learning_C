/*
第2关：简单链表

任务描述
本关任务：编写一个代码程序解决简单链表问题。

相关知识
给定一个空链表，然后按如下要求操作。

输入描述
每行输入一个整数，表示依次将这些整数插入链表；直到输入0为止，表示输入结束。

输出描述
按照插入的顺序依次输出链表中的偶数，若无偶数，输出字符串“Empty”，整数之间以一个空格分开。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决解决简单链表问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
4
3
5
18
122
0
预期输出：4 18 122
*/

#include <stdio.h>
#include <stdlib.h>

/*
struct num
{
    int num;
    struct num *next;
};
*/
typedef struct Num
{
    int num;
    struct Num *next;
} Num;

//struct num *add_num(int num,struct num *LAST)
Num *add_num(int num,Num *LAST)
{
    /*
    if(LAST)
    {
        struct num *p=malloc(sizeof(struct num));
        LAST->next=p;
        p->num=num,p->next=NULL;
        return p;
    }
    else
    {
        struct num *p=malloc(sizeof(struct num));
        p->num=num,p->next=NULL;
        return p;
    }
    */
    Num *p=malloc(sizeof(Num));
    p->num=num,p->next=NULL;
    if(LAST)
        LAST->next=p;
    return p;
}

int main()
{
    //struct num *HEAD=NULL,*p=NULL;
    Num *HEAD=NULL,*p=NULL;
    /*
    for(int i=0;; i++)
    {
        int num=0;
        scanf("%d",&num);
        if(!num)
            break;
        p=add_num(num,p);
        if(!i)
            HEAD=p;
    }
    */
    int num=0;
    while(scanf("%d",&num),num)
    {
        p=add_num(num,p);
        if(!HEAD)
            HEAD=p;
    }
    p=HEAD;
    int k=1;
    while(p)
    {
        if(!(p->num%2))
            printf("%d ",p->num),k=0;
        p=p->next;
    }
    if(k)
        printf("Empty");
    printf("\n");
    return 0;
}
