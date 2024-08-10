/*
变异系数
竞赛 1039, 题目 E

描述
给出若干个长度相同的数列，求其中变异系数最小的一个。

对于长度为 L 的数列 A ，定义：
    sum(A) := Sigma(a_i belongs to A) a_i
    avg(A) := sum(A) / L
    var(A) := Sigma(a_i belongs to A) (a_i - avg(A))^2 / L
    sd(A) := sqrt(var(A))
    cv(A) := sd(A) / avg(A)

其中 cv(A) 即为数列 A 的变异系数。

输入
第一行为两个整数 n 和 L （1 <= n , L <= 1*10^5，保证 nL <= 1*10^6），分别表示数列的数量和长度。

接下来 n 行，每行 L 个整数 A_ij（1 <= A_ij <= 1000），每行表示一个数列。

输出
仅一行 L 个整数，表示变异系数最小的数列。保证不存在两个数列的变异系数之差的绝对值小于 10^-10 。

样例输入
2 4
1 2 3 4
5 5 5 5
样例输出
5 5 5 5
判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <math.h>

int main() {
    unsigned int n = 0, L = 0, t = 0;
    scanf("%u%u", &n, &L);
    double A[n][L], cv[n];
    for (int i = 0; i < n * L; i++)
        A[0][i] = 0;
    for (int i = 0; i < n; i++)
        cv[i] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < L; j++)
            scanf("%lf", &A[i][j]);
    }
    for (int i = 0; i < n; i++) {
        double s = 0;
        for (int j = 0; j < L; j++)
            cv[i] += A[i][j] * A[i][j], s += A[i][j];
        s /= L, cv[i] = sqrt(fabs((cv[i] / L) - s * s)) / s;
    }
    double m = cv[0];
    for (int i = 1; i < n; i++) {
        if (m - cv[i] > 1e-10) {
            m = cv[i], t = i;
        }
    }
    for (int i = 0; i < L; i++) {
        printf("%.0lf", A[t][i]);
        if (i < L - 1)
            printf(" ");
    }
    printf("\n");
    return 0;
}
