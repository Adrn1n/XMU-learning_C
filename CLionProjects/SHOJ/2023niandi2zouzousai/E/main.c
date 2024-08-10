/*
顺子的大小
竞赛 1041, 题目 E

描述
江浙地区有一种流行的扑克牌玩法叫做“跑得快”，顾名思义，玩家需要尽可能思考如何快速地将自己的手牌打出去赢得最后的胜利，这也使得“顺子”这种出牌方法成为了许多玩家的制胜法宝。“顺子”也叫“连牌”，构成顺子有两个限制，玩家需要组合五张及以上连续的扑克牌方能组成顺子，比如“A 2 3 4 5”这种最小的顺子，又比如“A 2 3 4 5 6 7 8 9 10 J Q K”这种大的顺子。如何比较顺子的大小呢？主要有两个标准，大顺子的第一张牌不能小于小顺子的第一张牌且大顺子的数量不能小于小顺子的数量。除此之外，在顺子中还有一种比较特殊的牌型——“同花顺”，即玩家打出的顺子的每张牌的花色相同，也就是全为黑桃、红桃、梅花和方块四种花色之一。

现定义这样一种玩法，首先定义每张扑克牌的大小为：“A < 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < J < Q < K”，然后解除构成顺子的最小数量限制（“A”也可作为顺子）和连续的限制（“A K”也可以作为顺子），保留由小到大的顺序限制（“K A”并不是顺子）和不能重复的限制 (”K K“不是顺子)，并将顺子的长度作为顺子大小的首要判定标准（“K”<“5 K”<“A 2 J”）。

假如长度相同，接着将两个顺子从第一张牌开始比大小（即按字典序比较，例如“A 2 J”<“A 3 4”，又例如“2 3”>“A 2”）。

假如字典序比较的结果也相同，在此基础上还需考虑花色对某一顺子的影响。首先定义同花顺为顺子的不同花色里最大的四个，同花顺之间的大小为：“黑桃 < 红桃 < 梅花 < 方块”。

假如两个顺子都不是同花顺，还需要按花色做字典序比较，花色之间的大小也为“黑桃 < 红桃 < 梅花 < 方块”（例如 “黑桃A 红桃2”<“红桃A 红桃2”，又比如“红桃A 黑桃2”>“黑桃A 红桃2”）。

从由“A~K”组成 的 13 张牌中任意选出 n 张牌组成按照“如上定义的顺子”，并给出每张牌的花色：0 代表黑桃、1 代表红桃、2 代表梅花、3 代表方块，请你判断这条顺子是所有顺子中第几小的顺子？

输入
输入共三行。

第一行为整数 n 代表给出顺子的扑克牌数量（1 <= n <= 13）。

第二行有 n 个空格隔开的字符串 c 分别表示给出的顺子里每张牌的大小（c belongs to {A,2,3,4,5,6,7,8,9,10,J,Q,K}）。

第三行有 n 个空格隔开的整数 s 分别表示顺子里每张牌的花色（0 <= s <= 3）。

保证输入的顺子一定正确，即按照如上定义。

输出
一行一个整数表示该顺子为所有可能的顺子里第几小的顺子。

样例输入
2
A 2
0 0
样例输出
65
提示
样例解释：

首先考虑大于单张牌组成的顺子，单张牌组成的顺子每个顺子里有 4 种花色，共有 13 * 4 = 52 种；

再考虑两张牌的顺子，“A 2”为两张牌的顺子里最小的顺子，因此仅需考虑花色的影响，“A 2”共有 16 种花色搭配，其中 0 0 表示黑桃同花顺，因此为 16 种里第 13 大的花色；

所以，52 + 13 = 65。

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>

long long A(int n, int m) {
    long long r = 1;
    for (int i = n; n - i < m; i--)
        r *= i;
    return r;
}

long long Factorial(int n) {
    long long r = 1;
    for (int i = n; i > 0; i--)
        r *= i;
    return r;
}

long long Power(int a, int n) {
    long long r = 1;
    for (int i = 0; i < n; i++)
        r *= a;
    return r;
}

unsigned Search(unsigned n, unsigned v[], unsigned max) {
    unsigned s = 0;
    while (*v) {
        short k = 1;
        for (unsigned *p = v; p - v < n - 1; p++)
            if (k) {
                if (*p >= *(p + 1))
                    (*p)--, k = 0;
            } else
                *p = max - (v + (n - 1) - p);
        if (k)
            s++, (*(v + (n - 1)))--;
        else
            *(v + (n - 1)) = max;
    }
    return s;
}

unsigned p_to_d(unsigned p, unsigned n, int N[]) {
    unsigned s = 0;
    {
        unsigned i;
        for (int *q = N; (i = q - N) < n; q++)
            s += *q * Power((int) p, (int) (n - i - 1));
    }
    return s;
}

unsigned set_n(int a, unsigned n, int A[]) {
    unsigned m = n;
    for (int *p = A; p - A < n; p++)
        *p = a, m--;
    return m;
}

unsigned cnt_c(unsigned N, int c[]) {
    int B[N];
    set_n(3, N, B);
    unsigned n = p_to_d(4, N, B);
    set_n(2, N, B);
    unsigned a2 = p_to_d(4, N, B);
    set_n(1, N, B);
    unsigned a1 = p_to_d(4, N, B);
    unsigned s = p_to_d(4, N, c);
    if (!s)
        return n - 2;
    else if (s < a1)
        return s;
    else if (s == a1)
        return n - 1;
    else if (s < a2)
        return s - 1;
    else if (s == a2)
        return n;
    else if (s < n)
        return s - 2;
    else
        return s + 1;
}

int main() {
    short n = 0;
    char S[163] = {0};
    scanf("%hd", &n), getchar();
    int C[n];
    unsigned V[n];
    fgets(S, 162, stdin);
    for (int *p = C; p - C < n; p++)
        scanf("%u", p);
    {
        unsigned *q = V;
        for (char *p = S; *p; p++) {
            unsigned i = *p - '0';
            if ((i >= 2) && (i <= 9))
                *(q++) = i;
            else
                switch (i) {
                    case 'A' - '0':
                        *(q++) = 1;
                        break;
                    case 1:
                        *(q++) = 10;
                        break;
                    case 'J' - '0':
                        *(q++) = 11;
                        break;
                    case 'Q' - '0':
                        *(q++) = 12;
                        break;
                    case 'K' - '0':
                        *(q++) = 13;
                        break;
                    default:;
                }
        }
    }
    unsigned m = 0;
    for (int i = 1; i <= n - 1; i++)
        m += (A(13, i) / Factorial(i)) * Power(4, i);
    m += (Search(n, V, 13) - 1) * Power(4, n);
    m += cnt_c(n, C);
    printf("%u\n", m);
    return 0;
}
