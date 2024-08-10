/*
请问您点的是兔子吗？
题目 1098

描述
Hoto CoCoa误打误撞的来到了SoftwareHouse，成为SoftwareHouse的一名店员。

现在她的主要任务是要处理客人们的订单。不幸的是，自助结账机总是出故障。以往打印的小票的末尾会以"Software_House"作为小票的结束分割符。（不含引号），而现在，打印完"Software_House"之后结账机还会打印乱码！

Hoto Cocoa找到了你，她希望你能写一个程序，自动去掉Software_House与之后的乱码部分。注意，如果有多次出现"Software_House",你只需要考虑它出现的第一个位置，而把后面的部分视作乱码的一部分。

输入
一行连续的字符串，其中不包含空白符（空格，换行或回车），字符串最大长度小于等于10的6次方。

输入保证一定包含“Software_House"。

输出
一行字符串，代表你去掉乱码与结束分割符之后的字符串。

样例输入
RabbitSoftware_Housejfasdksdlfjsdklfjls??9!!__9834Software_Housefff
样例输出
Rabbit
判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>
#include <string.h>

int main() {
    char A[1000001] = {0}, B[14] = "Software_House";
    scanf("%s", A);
    unsigned int n = strlen(A), m = 0;
    for (unsigned int i = 0; i < n; i++) {
        int k = 1;
        for (unsigned int j = 0; j < 14; j++) {
            if (A[i + j] != B[j]) {
                k = 0;
                break;
            }
        }
        if (k) {
            m = i;
            break;
        }
    }
    A[m] = 0;
    printf("%s\n", A);
    return 0;
}
