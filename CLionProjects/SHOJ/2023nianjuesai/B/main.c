/*
地毯花纹3
竞赛 1042, 题目 B

描述
index家又买了一块新地毯，这次地毯的花纹不止A、B、C三种样式，可能是A~Z任一一个大写字母。突然你童心大发，决定在进门的时候给自己定几条规则，只能按照字母顺序移动，A到B，B到C，C到D，以此类推……最终你将会有多少种方式从门口移动到index家的客厅。

地毯长宽为3、3。现在你将从（0，0）出发移动到（2，2）的位置。且每次移动你的横坐标和纵坐标都只能增加不能减少。相邻的含义只能是上下左右的相邻，不能为斜角。（0，0）是输入的左上角，（2，2）是输入的右下角。

输入
接下来3行每行3个字符表示地毯花纹

输出
从（0，0）出发移动到（2，2）的位置可能的路线数量。

样例输入
ABC
BAD
CDE
样例输出
2
提示
这道题或许你不需要想的太复杂，路线只有那么几条可以试试直接枚举出来

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>

#define m 3
#define n 3

short min(short a, short b) {
    return (short) ((a < b) ? (a) : (b));
}

short *Write_Path(char cur_char, char pre_char, short *cur_short, short *pre_short) {
    if ((cur_char - pre_char) == 1)
        *cur_short += *pre_short;
    return cur_short;
}

int main() {
    char S[m][n + 1];
    for (char (*p)[n + 1] = S; *p - S[m] < 0; p++)
        scanf("%s", *p);
    short A[m][n];
    A[0][0] = 1;
    for (short *p = *A + 1; p - *A < m * n; p++)
        *p = 0;
    for (short i = 1; i < n; i++) {
        short cnt = min((short) (i + 1), m);
        for (short j = 0; j < cnt; j++) {
            if (j > 0)
                Write_Path(S[j][i - j], S[j - 1][i - j], &A[j][i - j], &A[j - 1][i - j]);
            if ((i - j) > 0)
                Write_Path(S[j][i - j], S[j][i - j - 1], &A[j][i - j], &A[j][i - j - 1]);
        }
    }
    for (short i = 1; i < m; i++) {
        short cnt = min((short) (m - i + 1), n);
        for (short j = 0; j < cnt; j++) {
            if ((n - 1 - j) > 0)
                Write_Path(S[i + j][n - 1 - j], S[i + j][n - 2 - j], &A[i + j][n - 1 - j], &A[i + j][n - 2 - j]);
            if ((i + j) > 0)
                Write_Path(S[i + j][n - 1 - j], S[i + j - 1][n - 1 - j], &A[i + j][n - 1 - j],
                           &A[i + j - 1][n - 1 - j]);
        }
    }
    printf("%hd\n", A[m - 1][n - 1]);
    return 0;
}
