/*
文宣楼下的守望者
竞赛 1040, 题目 B

描述
在文宣楼下，有一只孤独的轮胎，就 ATt3Z1 的记录而言，它已经至少于此地呆了 3 年。

(Image: E:\Files\C\CLionProjects\SHOJ\2023niandi1zouzousai\B\download.jpg)  (Image: E:\Files\C\CLionProjects\SHOJ\2023niandi1zouzousai\B\download (1).jpg)

（左图摄于2023年，右图摄于2020年）

时间在它身上仿佛静止一般，它目送厦大学子来来去去多年。但毕竟是个没人要的轮胎，指不定哪天就被人拿走扔掉了。

现从今日记为第 0 天，假设轮胎每过一天各种意外被扔掉的概率为 a% ，且学校将会在第 b 天组织一次大清扫，轮胎在大清扫中被扔掉的概率为 c% 。 ATt3Z1 希望知道轮胎第 d 天还能存在的概率。每天因意外被扔和因大清扫被扔为独立事件。

ATt3Z1 对这个轮胎十分的不舍，所以希望知道这个概率，现在他想通过编程解决这个问题。

输入
输入一共 T + 1 行，第一行为一个正整数 T ，代表数据的行数。

接下来 T 行，每一行四个正整数 a ，b ， c ， d ，用一个空格隔开。

（1 <= T <= 1000, 1 <= a, b, c, d <=100）

输出
一共输出 T 行。

每行一个百分数（保留小数点后 2 位即可），代表轮胎第 d 天还能存在的概率。

你输出的答案与标准答案相差不超过0.01%，就会被认为是正确答案。

样例输入
2
1 1 3 1
2 3 4 2
样例输出
96.03%
96.04%
提示
第一个数据，轮胎会经历一天意外的可能性和一次大清扫的可能性。所以概率为 (1 - 1%) * (1 - 3%) = 96.03%

第二个数据，轮胎会经历两天意外的可能性但不会遇见大清扫的可能性。所以概率为 (1 - 2%)^2 * 1 = 96.04%

判题方式
本题采用   特殊判题   。判题机根据出题人制作的判题程序读入用户输出，符合既定规则，则判为正确。该模式下，用户输出不需要与参考答案每个字符都相同。
*/

#include <stdio.h>

int main() {
    unsigned int T = 0;
    scanf("%u", &T);
    for (unsigned int t = 0; t < T; t++) {
        double a = 0, b = 0, c = 0, d = 0, p = 100;
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        a = 1 - a / 100, c = 1 - c / 100;
        for (int i = 0; i < d; i++)
            p *= a;
        if (b <= d)
            p *= c;
        printf("%.2f%%\n", p);
    }
    return 0;
}