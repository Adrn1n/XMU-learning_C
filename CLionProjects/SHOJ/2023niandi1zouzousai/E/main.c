/*
Lambda表达式
竞赛 1040, 题目 E

描述
如果一个字符串为以下形式之一，则我们称它为一个Lambda表达式：

1. 任意小写字母，如a

2. 任意Lambda表达式在前面或后面加上任意个数的空格，如 b

3. 任意两个Lambda表达式连写，如：a b

4. 一个反斜杠、任意小写字母和任意Lambda表达式连写，如：\x x y

5. 一个左圆括号、任意Lambda表达式和一个右圆括号连写，如：(\x x)

给出一个字符串，请判断它是否是符合以上定义的Lambda表达式。

输入
第一行一个整数 n（1 <= n <= 1*10^5），表示字符串的数量。

接下来 n 行，每行一个字符串 s ，保证仅由小写字母、空格、反斜杠和圆括号组成。保证不会全为空格。

保证所有字符串的长度之和不超过 1*10^6。

输出
对于每个字符串，如果是Lambda表达式，请输出Yes，否则输出No。

样例输入
1
\x\y(xy)z
样例输出
Yes
判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <stdlib.h>

unsigned short Judge(char *S) {
    unsigned short has_ib = 0, has_b = 0, has_l = 0, has_s = 0;
    long long cnt_b = 0;
    for (char *p = S; *p; p++) {
        if ((*p >= 'a') && (*p <= 'z')) {
            has_l = 1;
            if (has_s)
                has_s = 0;
        } else if (*p == '(') {
            has_ib = 0, has_b = 1, has_l = 0, cnt_b++;
            if (has_s)
                has_s = 0;
        } else if (*p == ')') {
            if (!has_ib) {
                if (!has_l)
                    return 0;
                else
                    has_ib = 1;
            }
            cnt_b--;
            if (cnt_b < 0)
                return 0;
            else if (cnt_b == 0)
                has_ib = 0;
            if (has_s)
                return 0;
            has_l = 0;
        } else if (*p == '\\') {
            p++;
            if ((*p < 'a') || (*p > 'z'))
                return 0;
            else
                has_l = 0, has_s = 1;
        }
    }
    if ((cnt_b) || ((!has_b) && (!has_l)) || (has_s))
        return 0;
    else
        return 1;
}

int main() {
    unsigned n = 0;
    scanf("%u", &n), getchar();
    for (int i = 0; i < n; i++) {
        char *S = malloc((1000000 + 2) * sizeof(char)), *p = S;
        fgets(p, 1000001, stdin);
        if (Judge(p))
            printf("Yes\n");
        else
            printf("No\n");
        free(S);
    }
    return 0;
}
