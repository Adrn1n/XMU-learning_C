/*
wxw的项链
题目 1097

描述
wxw有一天收到了一条项链，上面重复刻着“wxwnb”的字样（“wxwnbwxwnbwxw…”）. wxw不是很喜欢这条项链，平常喜欢扣上面的珠子，他从第一个珠子（即刻着”wxwnb“的第一个”w“）开始数，并把数到m的珠子扣下来，再由下一个珠子从1开始计数，数到m的珠子再扣下来。。。 请输出扣下来的n个珠子上的刻字。

输入
输入两个整数n、m。 n表示项链一共有n个珠子，m表示每隔m位扣下来一个珠子。

输出
一行字符串，按时间顺序输出扣下来的珠子上刻的字

样例输入
10 3
样例输出
wwnxxwwbbn
提示
1<=n<=3600, 1<=m<=3600

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>

unsigned int strip(unsigned int k, unsigned int n) {
    if (k >= n)
        k -= n;
    return k;
}

int main() {
    char A[5] = {'w', 'x', 'w', 'n', 'b'};
    unsigned int n = 0, m = 0;
    scanf("%u%u", &n, &m);
    char B[n];
    for (int i = 0; i <= n; i++) {
        B[i] = A[i % 5];
    }
    unsigned int k = 0;
    for (unsigned int i = 0; i < n; i++) {
        for (unsigned int j = 0; j < m;) {
            if (B[k]) {
                k++, j++;
                k = strip(k, n);
            } else {
                k++;
                k = strip(k, n);
            }
        }
        k--;
        if (k > n)
            k = n - 1;
        printf("%c", B[k]);
        B[k] = 0;
        k++;
        k = strip(k, n);
    }
    return 0;
}
