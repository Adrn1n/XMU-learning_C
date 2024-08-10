/*
三角函数代换
竞赛 1040, 题目 D

描述
ATt3Z1很喜欢三角函数知识，现在他想挑战一下自己，把所有三角函数式子都用 sin(x) 表示。

对于 cos(x) ，ATt3Z1将利用公式 cos(x) = sqrt( 1 - sin(x)^2 ) 进行代换。

对于 tan(x) ，ATt3Z1将利用公式 tan(x) = 1 / sqrt(1 / sin(x)^2 - 1) 进行代换。

对于所有输入，为一个特定格式的字符串：

a(b(...c(x)))

其中 abc 都是三角函数的名字（ sin 或 cos 或 tan ）， x 就是一个字符 x 。

输入
输入一共 n + 1 行，第一行为一个正整数 n ，代表数据的行数。

接下来 n 行，每一行一个三角函数式子，按照题中的格式给出。

（每个式子三角函数的个数 <= 100）

输出
一共输出 n 行。

代表原三角函数式子用题中所给公式替换后的字符串。请不要加入多余空格或括号。

样例输入
2
sin(cos(tan(x)))
tan(sin(cos(x)))
样例输出
sin(sqrt(1-sin(1/sqrt(1/sin(x)^2-1))^2))
1/sqrt(1/sin(sin(sqrt(1-sin(x)^2)))^2-1)
判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <string.h>

int main() {
    unsigned int N = 0;
    scanf("%u", &N), getchar();
    for (int n = 0; n < N; n++) {
        char A[100 * 5 + 1 + 1] = {0}, B[20 * 100 + 1 + 1] = {0};
        scanf("%s", A);
        char *p = A, *w_f = B, *w_b = B + 20 * 100 + 1;
        char TEMP[5] = {0}, sin[] = "sin(", cos[] = "cos(", tan[] = "tan(";
        char cos_in_sin_f[11] = "sqrt(1-sin(", cos_in_sin_b[4] = ")^2)", tan_in_sin_f[13] = "1/sqrt(1/sin(", tan_in_sin_b[6] = ")^2-1)";
        for (; *p; p += 4) {
            if (*p == 'x') {
                *w_f = 'x';
                w_f++;
                break;
            }
            strncpy(TEMP, p, 4);
            if (!(strcmp(TEMP, sin))) {
                strncpy(w_f, sin, 4), w_f += 4;
                w_b--, *w_b = ')';
                continue;
            }
            if (!(strcmp(TEMP, cos))) {
                strncpy(w_f, cos_in_sin_f, 11), w_f += 11;
                strncpy(w_b -= 4, cos_in_sin_b, 4);
                continue;
            }
            if (!(strcmp(TEMP, tan))) {
                strncpy(w_f, tan_in_sin_f, 13), w_f += 13;
                strncpy(w_b -= 6, tan_in_sin_b, 6);
                continue;
            }
        }
        char *q = w_f;
        for (; w_b < B + 20 * 100 + 1; w_b++, q++) {
            *q = *w_b;
            *w_b = 0;
        }
        printf("%s\n", B);
    }
    return 0;
}
