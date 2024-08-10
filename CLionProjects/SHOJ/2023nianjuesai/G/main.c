/*
病床边的数字3
竞赛 1042, 题目 G

描述
小知和小贵对于前两道数字题目已经快精疲力精了，但她们决定用最后的力气再玩一个游戏，玩完就早点睡觉。

同样是写有数字 1 ~ n 的 n 张卡牌，小贵想到了一个玩法，如果能将这 n 张卡牌分成 k 个集合，且每个集合的所有元素之和相等，那一定会很有趣。

输入
输入一共 T + 1 行，第一行为一个正整数 T ，代表数据的行数。

接下来 T 行，每一行两个正整数 n 和 k 。保证 n 的和和 k 的和不超过 10^6 。

（ 1 <= T <= 1000, 1 <= n, k <= 10^6 ）

输出
一共输出 T 个结果。

如果可以被分成 k 个集合，那么输出 "YES"，然后输出 k 行，第 i 行第一个数字为 m ，代表第 i 个集合的数字个数，然后输出 m 个正整数，代表该集合中具体的数字。

如果不可以被分为 k 个集合，那么输出 "NO" 即可。

样例输入
2
10 11
10 5
样例输出
NO
YES
2 1 10
2 2 9
2 3 8
2 4 7
2 5 6
提示
本题采用特殊判题，只要符合要求的答案都算正确。

对于第一行数据，显然 10 张卡片是分不出 11 个集合的，故输出 "NO" 。

对于第二行数据，显然如答案所示两两配对即可分成 5 个和相等的集合。

判题方式
本题采用   特殊判题   。判题机根据出题人制作的判题程序读入用户输出，符合既定规则，则判为正确。该模式下，用户输出不需要与参考答案每个字符都相同。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node_d {
    int val;
    struct Node_d *next;
} node_d;

typedef struct Arr_d {
    int n;
    node_d *node_d_ptr;
} arr_d;

node_d *Add_d_to_node(arr_d *const Arr, int val) {
    node_d *p = malloc(sizeof(node_d));
    p->val = val, p->next = Arr->node_d_ptr;
    Arr->n++, Arr->node_d_ptr = p;
    return p;
}

arr_d *Merge_arr_d(arr_d *const dest, const arr_d *const src) {
    for (node_d *p = src->node_d_ptr; p; p = p->next)
        Add_d_to_node(dest, p->val);
    return dest;
}

long long Div_k(arr_d Ans[], const int n, const int k) {
    long long S = ((long long) n * (n + 1)) / 2;
    if (S % k)
        return -1;
    else {
        S /= k;
        if ((S >= n) && (S > 0)) {
            if (S > n + n - 1) {
                for (int i = 0; i < k; i++)
                    Add_d_to_node(&Ans[i], n - i), Add_d_to_node(&Ans[i], n - 2 * k + 1 + i);
                if (Div_k(Ans, n - 2 * k, k) <= 0)
                    return -1;
            } else {
                int b = n, a = (int) (S - b), i = 0;
                while (a < b) {
                    Add_d_to_node(&Ans[i], b--);
                    if (a > 0)
                        Add_d_to_node(&Ans[i], a);
                    a++, i++;
                }
                if (i < k)
                    if (a > b) {
                        if (Div_k(Ans + i, (int) (S - n - 1), k - i) <= 0)
                            return -1;
                    } else {
                        int _k = 2 * (k - i) - 1;
                        arr_d Tmp[_k];
                        for (arr_d *p = Tmp; p - Tmp < _k; p++)
                            p->n = 0, p->node_d_ptr = NULL;
                        if (Div_k(Tmp, (int) (S - n - 1), _k) > 0) {
                            for (int j = 1; j < _k; i++, j += 2)
                                Merge_arr_d(&Ans[i], &Tmp[j - 1]), Merge_arr_d(&Ans[i], &Tmp[j]);
                            Merge_arr_d(&Ans[i], &Tmp[_k - 1]), Add_d_to_node(&Ans[i], a);
                        } else
                            return -1;
                    }
                else if (i > k)
                    return -1;
            }
            return S;
        } else
            return -1;
    }
}

short Print_arr_d(const arr_d *const arr_d_ptr) {
    int n = arr_d_ptr->n;
    node_d *ptr = arr_d_ptr->node_d_ptr, *tmp;
    while (ptr) {
        printf("%d ", ptr->val);
        tmp = ptr, ptr = ptr->next;
        free(tmp);
        n--;
    }
    return (short) (!n);
}

int main() {
    short T = 0;
    scanf("%hd", &T);
    while (T--) {
        int n = 0, k = 0;
        scanf("%d%d", &n, &k);
        arr_d Ans[k];
        for (arr_d *p = Ans; p - Ans < k; p++)
            p->n = 0, p->node_d_ptr = NULL;
        if (Div_k(Ans, n, k) > 0) {
            printf("YES\n");
            for (arr_d *p = Ans; p - Ans < k; p++) {
                printf("%d ", p->n);
                Print_arr_d(p);
                printf("\n");
            }
        } else
            printf("NO\n");
    }
    return 0;
}
