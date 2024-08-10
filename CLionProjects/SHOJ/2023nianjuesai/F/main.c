/*
小晴的密码锁
竞赛 1042, 题目 F

描述

(Image: ./download.jpg)

小晴的身上被绑上了一枚定时炸弹，定时炸弹需要密码才能解除。

密码由 n 个 0 - 9 之间的数字组成。小晴可以获得密码的两种提示信息。

一是密码的资料卡片，密码的资料卡片一共有 n 张。每张资料卡片上写有一个 0 - 9 之间的数字或者字母 x 。一张某个数字的资料卡片代表这个数字有可能会在密码中出现一次，但出现的位置未知。如果资料卡上写的是字母 x ，则代表这张资料卡片是无效的。

二是备选密码，备选密码一共有 m 个。每个备选密码会按顺序直接给出 n 个 0 - 9 之间的数字，代表密码一种可能的值。同时，每个备选密码均有其准确度。

但由于两种提示信息均模糊不清，无法完全确定密码，小晴决定按照如下公式计算每个备选密码的可能性：

备选密码的可能性 = 该备选密码与资料卡片的匹配度 * 该备选密码的准确度。

备选密码和资料卡片匹配度的计算方式：将资料卡片任意顺序排列，排列后的资料卡片与该备选密码重合的数字个数的最大值。如 "1 2 3" 与 "3 1 2" 的匹配度为 3 ， "1 2 3" 和 "3 1 3" 匹配度为 2。

小晴会计算出可能性最大的一个备选密码作为密码输入，解除炸弹。

输入
第一行为一个正整数 n ，代表密码的位数。

第二行一共 n 个字符（字符的范围为  0 - 9 和 x ），代表所获得的资料卡片信息，其中 0 - 9 为有效密码数字信息， x 为无效密码数字信息。这 n 个字符以一个空格隔开。

第三行为一个正整数 m ，代表备选密码的个数。

接下来 m 行，每行为 n 个字符（字符的范围为  0 - 9） s_i1 ... s_in 和一个非负整数 a_i 。 s_i 数组代表该备选密码的值， a_i 代表该备选密码的准确度。数据间以一个空格隔开。

（ 1 <= n <= 1000, 1 <= m <= 1000, 0 <= a_i <= 10^9 ）

输出
一共输出 2 行。

第一行为备选密码中可能性的最大值。

第二行为 n 个字符（字符的范围为  0 - 9），代表可能性最大的备选密码的值，字符间以一个空格隔开。

保证答案是唯一的。请不要在行末输出多余空格！否则可能会被判定为格式错误。



样例输入
4
7 1 0 x
4
7 7 7 7 1
7 0 1 9 0
0 7 1 4 9
0 7 1 5 10
样例输出
30
0 7 1 5
提示
样例中，小晴拥有的 4 张资料卡片中只有 "7 1 0" 三张为有效。

对于第 1 个备选密码 "7 7 7 7" ，匹配度为 1 （只有一个 "7" 被匹配），准确度为 1 ，可能性 = 匹配度 * 准确度 = 1 * 1 = 1。

对于第 2 个备选密码 "7 0 1 9" ，匹配度为 3 （ "7 0 1" 匹配），准确度为 0 ，可能性 = 匹配度 * 准确度 = 3 * 0 = 0。

对于第 3 个备选密码 "0 7 1 4" ，匹配度为 3 （ "0 7 1" 匹配），准确度为 9 ，可能性 = 匹配度 * 准确度 = 3 * 9 = 27。

对于第 4 个备选密码 "0 7 1 5" ，匹配度为 3 （ "0 7 1" 匹配），准确度为 10 ，可能性 = 匹配度 * 准确度 = 3 * 10 = 30。

密码优先级为 4 > 3 > 1 > 2 。因此选择 "0 7 1 5" 作为密码。

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *const a, const void *const b) {
    return (*(short *) a > (*(short *) b));
}

short Cal_dup(const short Arr[], const short Val[], const short n) {
    short dup = 0;
    const short *p = Arr, *q = Val;
    while ((*q >= 0) && (p - Arr < n))
        if (*p > *q)
            q++;
        else if (*p < *q)
            ++p;
        else {
            p++, q++;
            dup++;
        }
    return dup;
}

short Cal_val(long long Val[], const short Opt[], const short Info[], const short m, const short n) {
    for (short i = 0; i < m; i++) {
        short Tmp[n];
        for (short *p = Opt + i * n, *q = Tmp; (p - (Opt + i * n) < n) && (q - Tmp < n); p++, q++)
            *q = *p;
        qsort(Tmp, n, sizeof(short), Cmp);
        Val[i] *= Cal_dup(Tmp, Info, n);
    }
    short res = 0;
    long long tmp = 0;
    for (long long *p = Val; p - Val < m; p++)
        if (*p > tmp)
            res = (short) (p - Val), tmp = *p;
    return res;
}

int main() {
    short n = 0, num = 0, m = 0;
    scanf("%hd", &n);
    short Info[n];
    getchar();
    for (short *p = Info; p - Info < n; p++)
        *p = -1;
    {
        short *p = Info, tmp = n;
        char c = 0;
        while (tmp--) {
            scanf("%c", &c);
            if ((c >= '0') && (c <= '9')) {
                *p++ = (short) (c - '0');
                num++;
            }
            getchar();
        }
        qsort(Info, num, sizeof(short), Cmp);
    }
    scanf("%hd", &m);
    short Opt[m][n];
    long long Val[m];
    for (short (*p)[n] = Opt; p - Opt < m; p++) {
        for (short *q = *p; q - *p < n; q++)
            scanf("%hd", q), getchar();
        scanf("%lld", Val + (p - Opt));
    }
    num = Cal_val(Val, *Opt, Info, m, n);
    printf("%lld\n", Val[num]);
    for (short *p = *(Opt + num); p - *(Opt + num) < n - 1; ++p)
        printf("%hd ", *p);
    printf("%hd\n", Opt[num][n - 1]);
    return 0;
}
