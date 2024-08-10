/*
地毯花纹2
竞赛 1042, 题目 A

描述
index家地毯的花纹你研究腻了，写了个程序秒了有什么好说的。于是你打算来研究点新东西。你打算对地毯进行镜像、旋转变换。你希望知道经过各种变化之后地毯的样子。

输入
第一行，两个数字n、m，表示地毯的长宽（n小于等于100，m小于等于100）

接下来n行，每行m个字符表示地毯的花纹

第n+2，一个长度为x的字符串，每个字符分别代表一次操作，总共有以下的操作类型（x小于等于1000000）：

1. R：沿着经过地毯几何中心垂直于地毯所在平面的轴顺时针旋转90度

2. L：沿着经过地毯几何中心垂直于地毯所在平面的轴逆时针旋转90度

3. T：沿着经过地毯几何中心垂直于地毯所在平面的轴顺时针旋转180度

4. H：沿着经过地毯几何中心垂直于n长度边的轴进行镜像翻转

5. V：沿着经过地毯几何中心垂直于m长度边的轴进行镜像翻转

输出
输出n*m的字符，表示经过几何变换之后的地毯花纹

样例输入
3 3
ABA
BAB
ABC
RRRLLHV
样例输出
ABC
BAB
ABA
判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <stdlib.h>

#define LEN 1000000
#define dim 2

short *Matrix_Multiple(short A[], short m_A, short n_A, short B[], short m_B, short n_B, short r[]) {
    if (n_A == m_B) {
        short *w = r;
        for (short *p1 = A; p1 - A < m_A * n_A; p1 += n_A)
            for (short *p2 = B; p2 - B < n_B; p2++) {
                for (short *q1 = p1, *q2 = p2; ((q1 - p1 < n_A) && (q2 - p2 < m_B * n_B)); q1++, q2 += n_B)
                    *w += *q1 * *q2;
                w++;
            }
        return r;
    } else
        return NULL;
}

short *Write_TransRes(short dest[], short src[], short m, short n) {
    for (short *p1 = dest, *p2 = src; ((p1 - dest < m * n) && (p2 - src < m * n)); p1 += n, p2 += n)
        for (short *q1 = p1, *q2 = p2; ((q1 - p1 < n) && (q2 - p2 < n)); q1++, q2++)
            *q1 = *q2, *q2 = 0;
    return dest;
}

short *Trans_Coords(short X[], short m1, short n1) {
    if (X[0] < 0)
        X[0] += n1;
    else
        X[0]--;
    if (X[1] < 0)
        X[1] += m1;
    else
        X[1]--;
    return X;
}

int main() {
    short n0 = 0, m0 = 0, n1, m1;
    scanf("%hd%hd", &n0, &m0);
    char A[n0][m0 + 1];
    for (char (*p)[m0 + 1] = A; *p - A[n0] < 0; p++)
        scanf("%s", *p);
    char S[LEN + 1] = {0};
    scanf("%s", S);
    short Trans[dim][dim] = {{1, 0},
                             {0, 1}},
            R[dim][dim] = {{0, -1},
                           {1, 0}},
            L[dim][dim] = {{0,  1},
                           {-1, 0}},
            T[dim][dim] = {{-1, 0},
                           {0,  -1}},
            H[dim][dim] = {{1, 0},
                           {0, -1}},
            V[dim][dim] = {{-1, 0},
                           {0,  1}},
            res0[dim][dim] = {{0, 0},
                              {0, 0}},
            a[dim][1] = {{m0},
                         {n0}},
            res1[dim][1] = {{0},
                            {0}};
    for (char *p = S; *p; p++)
        switch (*p) {
            case 'R':
                Matrix_Multiple(R[0], dim, dim, Trans[0], dim, dim, res0[0]);
                Write_TransRes(Trans[0], res0[0], dim, dim);
                break;
            case 'L':
                Matrix_Multiple(L[0], dim, dim, Trans[0], dim, dim, res0[0]);
                Write_TransRes(Trans[0], res0[0], dim, dim);
                break;
            case 'T':
                Matrix_Multiple(T[0], dim, dim, Trans[0], dim, dim, res0[0]);
                Write_TransRes(Trans[0], res0[0], dim, dim);
                break;
            case 'H':
                Matrix_Multiple(H[0], dim, dim, Trans[0], dim, dim, res0[0]);
                Write_TransRes(Trans[0], res0[0], dim, dim);
                break;
            case 'V':
                Matrix_Multiple(V[0], dim, dim, Trans[0], dim, dim, res0[0]);
                Write_TransRes(Trans[0], res0[0], dim, dim);
                break;
        }
    Matrix_Multiple(Trans[0], dim, dim, a[0], dim, 1, res1[0]);
    Write_TransRes(a[0], res1[0], dim, 1);
    m1 = (short) abs(a[0][0]), n1 = (short) abs(a[1][0]);
    char Res[n1][m1 + 1];
    for (char (*p)[m1 + 1] = Res; *p - Res[n1] < 0; p++)
        *(*p + m1) = 0;
    for (char (*p)[m0 + 1] = A; *p - A[n0] < 0; p++) {
        for (char *q = *p; q - *p < m0; q++) {
            a[0][0] = (short) (q - *p + 1), a[1][0] = (short) (p - A + 1);
            Matrix_Multiple(Trans[0], dim, dim, a[0], dim, 1, res1[0]);
            Write_TransRes(a[0], res1[0], dim, 1);
            Trans_Coords(a[0], n1, m1);
            Res[a[1][0]][a[0][0]] = *q;
        }
    }
    for (char (*p)[m1 + 1] = Res; *p - Res[n1] < 0; p++)
        printf("%s\n", *p);
    return 0;
}
