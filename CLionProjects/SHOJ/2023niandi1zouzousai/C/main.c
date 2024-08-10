/*
地毯花纹1
竞赛 1040, 题目 C

描述
index家有一个地毯，这条地毯很神奇。已知这个地毯有三种花纹，A、B、C。其中A花纹只能与B花纹相邻,B花纹可以与A、C相邻，C花纹只能与B花纹相邻。这里的相邻指的是上下左右四个方向。现在你突然想到是否可以写一个程序来判断地毯花纹的合法性。

输入
第一行，两个整数n、m，分别表示地毯花纹的行数与列数。

接下来的n行，每行m个字符，来表示ABC三种花色。

保证 n <= 10^6 ，m <= 10^6 ，n * m <= 10^7 。

输出
“invalid”来表示不合法，“valid”来表示合法

样例输入
3 3
CBC
BAB
CBC
样例输出
valid
提示
注意本题内存限制为16M。

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned long long n = 0, m = 0;
    scanf("%llu%llu", &n, &m), getchar();
    unsigned long long N = n * m;
    char *p = (char *) (malloc(N * sizeof(char)));
    for (char *q = p; q < p + N; q++) {
        if ((!((q - p) % m)) && (q - p))
            getchar();
        scanf("%c", q);
    }
    int k = 0;
    for (char *q = p; q < p + N; q++) {
        if ((*q == 'A') || (*q == 'C')) {
            if ((q + 1 - p) % m) {
                if ((*(q + 1) == 'C') || (*(q + 1) == 'A')) {
                    k = 1;
                    break;
                }
            }
            if ((q - p) < N - m) {
                if ((*(q + m) == 'C') || (*(q + m) == 'A')) {
                    k = 1;
                    break;
                }
            }
        } else if (*q == 'B') {
            if ((q + 1 - p) % m) {
                if (*(q + 1) == 'B') {
                    k = 1;
                    break;
                }
            }
            if ((q - p) < N - m) {
                if (*(q + m) == 'B') {
                    k = 1;
                    break;
                }
            }
        }
    }
    free(p);
    if (k)
        printf("invalid\n");
    else
        printf("valid\n");
    return 0;
}
