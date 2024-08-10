/*
风雪里的旅店
竞赛 1042, 题目 D

描述
index和facedawn外出查案，有一家旅店是重点怀疑对象。但是这家旅店的记录实在是不够直观，旅店有时候会记录顾客第几天来的住了几天，有时候会记录顾客是第几天来第几天走的，有时候会记录顾客是第几天走的总共住了几天。index希望你能设计一个程序，你告诉它第x天，它能直接告诉你当天住了几个人分别是谁。

输入
第一行一个数字n表示旅店有几条记录

接下来n行，每行有1个字符串和3个数字name x y z ，第一个字符串表示人名，如果x是1，表示这个顾客是第y天来的，一共住了z天。如果x是2，表示这个顾客是第y天来的，第z天走的。如果第一个数字是3，表示这个顾客是第y天走的，一共住了z天。（注：当日离店的客人，不计为住宿人员）

第n+2行，一个数字m，表示会有m次询问。

接下来m行，每行1个数字k，表示希望知道第几天有多少个人分别是谁。

我们保证。客人住店离店的日期一定位于区间[1,1000]内。name的长度小于等于15，n小于等于8000，x只能为1或2或3，y、z，k小于等于1000，m小于等于100000（可能会重复问）。没有重名的客人。

输出
m行，每行先输出一个数字x表示这一天有几个人，接来输出x个人名用空格分隔来表示当天住店的人。（名字的输出前后顺序，请按照输入的先后顺序）

我们保证最终输出的答案的总长度一定小于16MB。

样例输入
3
Bob 1 1 2
Lily 1 2 3
LiHua 1 3 1
2
1
3
样例输出
1 Bob
2 Lily LiHua
提示
请切勿在行尾输出多余的空格，否则可能会被判定为格式错误！

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <stdlib.h>

#define name_len 15
#define day_max 1000

typedef struct Reg_srt {
    char name[name_len + 1];
    short x, y, z;
} Reg;

typedef struct Req_srt {
    Reg **res;
    short req_day, cnt;
} Req;

short Format_date(Reg *const reg) {
    switch (reg->x) {
        case 1: {
            reg->z += reg->y;
            break;
        }
        case 3: {
            reg->y -= reg->z;
            reg->z = reg->y + reg->z;
            break;
        }
        default:
            break;
    }
    return 1;
}

short Search(Reg reg[], const short N, const short k, Reg *res[]) {
    short cnt = 0;
    for (Reg *p = reg; p - reg < N; p++)
        if ((p->y <= k) && (p->z > k))
            res[cnt] = p, cnt++;
    return cnt;
}

short Print(const Req *const req) {
    printf("%d", req->cnt);
    for (Reg **p = req->res; p - req->res < req->cnt; p++)
        printf(" %s", (*p)->name);
    printf("\n");
    return 1;
}

int main() {
    short n = 0, req_num = 0;
    scanf("%hd", &n);
    Reg reg[n];
    for (Reg *p = reg; p - reg < n; p++) {
        scanf("%s%hd%hd%hd", p->name, &(p->x), &(p->y), &(p->z));
        Format_date(p);
    }
    Req req[day_max];
    int m = 0;
    scanf("%d", &m);
    while (m--) {
        short k = 0, flag = 1;
        scanf("%hd", &k);
        for (Req *p = req; p - req < req_num; p++)
            if (p->req_day == k) {
                Print(p);
                flag = 0;
                break;
            }
        if (flag) {
            req[req_num].req_day = k;
            req[req_num].res = malloc(n * sizeof(Reg));
            req[req_num].cnt = Search(reg, n, k, req[req_num].res);
            Print(&req[req_num]);
            req_num++;
        }
    }
    for (Req *p = req; p - req < req_num; p++)
        free(p->res);
    return 0;
}
