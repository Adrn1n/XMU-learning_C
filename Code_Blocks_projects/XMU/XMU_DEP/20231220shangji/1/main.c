/*
第1关：数据查找

任务描述
本关任务：编写一个代码程序解决数据查找问题。

相关知识
按一定条件对n个货物数据“货号 库存 价格 体积”查询，现在按其中某一条件查找大于等于某数值的数据（询问1按库存查找，询问2按价格查找，询问3按体积查找）。输出符合要求的数据信息。

输入描述
输入的第一行为一个整数N，代表有N个货物数据。（n≤1000）

接下来每一行依次输入货号、库存、价格、体积，其中货号是一个六位整数，其余数据是范围[0，10000]的整数。

再一行输入2个询问整数K，S，其中K∈{1,2,3}，表示按第K种条件查找，0≤S≤10000，表示查找大于等于S的数据。
输出描述
按原顺序输出符合条件的货物数据（包括货号、库存、价格、体积，注意行尾无空格）；

若无符合条件的数据，输出“nothing”。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决数据查找问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：

3
122034 70 50 30
230201 50 60 70
102203 56 90 63
2 60
预期输出：
230201 50 60 70
102203 56 90 63
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Properties {Inventory,Price,Volume,n_Properties};

/*
struct Stuff
{
    char num[7];
    unsigned int left,value,volume;
    struct Stuff *next;
};
*/

typedef struct Cargo
{
    char num[7];
    unsigned int properties[n_Properties];
    struct Cargo *next;
} Cargo;

//struct Stuff *add_stuff(char *num,unsigned int left,unsigned int value,unsigned int volume,struct Stuff *LAST)
Cargo *add_cargo(char *num,unsigned int properties[],Cargo *LAST)
{
    /*
    if(LAST)
    {
        struct Stuff *p=malloc(sizeof(struct Stuff));
        LAST->next=p;
        strcpy(p->num,num),p->left=left,p->value=value,p->volume=volume,p->next=NULL;
        return p;
    }
    else
    {
        struct Stuff *p=malloc(sizeof(struct Stuff));
        strcpy(p->num,num),p->left=left,p->value=value,p->volume=volume,p->next=NULL;
        return p;
    }
    */
    Cargo *p=malloc(sizeof(Cargo));
    strcpy(p->num,num),*(p->properties+Inventory)=*(properties+Inventory),*(p->properties+Price)=*(properties+Price),*(p->properties+Volume)=*(properties+Volume),p->next=NULL;
    if(LAST)
        LAST->next=p;
    return p;

}

int main()
{
    unsigned int N=0;
    scanf("%u",&N);
    //struct Stuff *HEAD=NULL,*p=NULL;
    Cargo *HEAD=NULL,*p=NULL;
    for(int i=0; i<N; i++)
    {
        char num[7]= {0};
        /*
        unsigned int left=0,value=0,volume=0;
        scanf("%s",num),scanf("%u%u%u",&left,&value,&volume);
        p=add_stuff(num,left,value,volume,p);
        */
        unsigned int properties[n_Properties]= {0};
        scanf("%s",num),scanf("%u%u%u",properties+Inventory,properties+Price,properties+Volume);
        p=add_cargo(num,properties,p);
        if(!i)
            HEAD=p;
    }
    unsigned int K=0,S=0;
    scanf("%u%u",&K,&S);
    K--;
    //struct Stuff *q=HEAD;
    p=HEAD;
    /*
    if(K==1)
        while(q)
        {
            if(q->left>=S)
                printf("%s %u %u %u\n",q->num,q->left,q->value,q->volume);
            q=q->next;
        }
    else if(K==2)
        while(q)
        {
            if(q->value>=S)
                printf("%s %u %u %u\n",q->num,q->left,q->value,q->volume);
            q=q->next;
        }
    else if(K==3)
        while(q)
        {
            if(q->volume>=S)
                printf("%s %u %u %u\n",q->num,q->left,q->value,q->volume);
            q=q->next;
        }
        */
    while(p)
    {
        if(*(p->properties+K)>=S)
            printf("%s %u %u %u\n",p->num,*(p->properties+Inventory),*(p->properties+Price),*(p->properties+Volume));
        p=p->next;
    }
    return 0;
}
