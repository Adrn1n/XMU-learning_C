/*
Index的键盘
竞赛 1041, 题目 A

描述
Elysia给Index的生日礼物是一个特制的键盘。这个键盘的布局和普通的QWERTY键盘不一样，她叫它INDEX键盘，它主键盘部分的布局是这样的：

(Image: E:/Files/C/CLionProjects/SHOJ/2023niandi2zouzousai/A/download.png)

现在给你一个大写字母，你需要回答这个字母在INDEX键盘上对应的键的左边的一个字母是什么。如果左边不是字母，输出-。

输入
一个A到Z之间的大写字母。

输出
一个A到Z之间的大写字母，或者-。

样例输入
N
样例输出
I
判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>

int main() {
    char I[26] = {'-', 'A', 'P', 'N', 'D', 'B', 'F', 'C', '-', 'G', 'H', 'J', 'L', 'I', 'M', 'Z', 'O', '-', 'R', 'S',
                  'T', 'U', 'V', 'E', 'W', 'X'};
    char a;
    scanf("%c", &a);
    printf("%c\n", I[a - 'A']);
    return 0;
}
