/*
斗地主
竞赛 1041, 题目 C

描述
斗地主是一项普及广泛的娱乐活动。一副牌总计有54张。其中2~10每个点数分别有4张，J、Q、K、A分别有4张，一张小王与一张大王。现在你在与index、yjy打斗地主的时候想要知道index的底牌是什么，你买通了yjy，他会把他的牌告诉你，现在需要你从小到大输出index的手牌（大王>小王>2>A>K>Q>J>10>9>8>7>6>5>4>3）。大王用X表示，小王用Y表示。这道题无需关心牌的花色。

输入
两行字符串，两行分别表示你与yjy的手牌

输出
一行字符串，表示index的手牌

样例输入
3344556677889
3344556677889
样例输出
9910101010JJJJQQQQKKKKAAAA2222YX
提示
真糟糕，看起来你们这把打不过index了。



注意：你和yjy手上的牌不一定是13张。你和yjy手上的牌也不一定数量相同，但是你们两手上至少有一张牌，且你们两人的牌加上Index的牌就是一副完整的牌组。

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>

short Except(short I[], char *S) {
    short i = 14;
    for (char *p = S; *p; p++) {
        int a = *p - '3';
        if ((a >= 0) && (a <= 6))
            I[a]--;
        else
            switch (a) {
                case -2:
                    I[7]--, p++;
                    break;
                case 'J' - '3':
                    I[8]--;
                    break;
                case 'Q' - '3':
                    I[9]--;
                    break;
                case 'K' - '3':
                    I[10]--;
                    break;
                case 'A' - '3':
                    I[11]--;
                    break;
                case -1:
                    I[12]--;
                    break;
                case 'Y' - '3':
                    I[13]--;
                    break;
                case 'X' - '3':
                    I[14]--;
                    break;
                default:;
            }
        i--;
    }
    return i;
}

short Print(char a, short *i) {
    while (*i)
        printf("%c", a), (*i)--;
    return *i;
}

int main() {
    short I[15] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1};
    char A[54] = {0}, B[54] = {0};
    scanf("%s", A), scanf("%s", B);
    Except(I, A), Except(I, B);
    for (short *p = I;; p++) {
        int a = (int) (p - I);
        if (a >= 15)
            break;
        else {
            if (a == 12)
                a = -1;
            if (a <= 7)
                while (*p)
                    printf("%d", a + 3), (*p)--;
            else
                switch (a) {
                    case 8:
                        Print('J', p);
                        break;
                    case 9:
                        Print('Q', p);
                        break;
                    case 10:
                        Print('K', p);
                        break;
                    case 11:
                        Print('A', p);
                        break;
                    case 13:
                        Print('Y', p);
                        break;
                    case 14:
                        Print('X', p);
                        break;
                    default:;
                }
        }
    }
    printf("\n");
    return 0;
}
