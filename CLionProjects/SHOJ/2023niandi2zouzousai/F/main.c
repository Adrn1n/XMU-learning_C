/*
Long Live The Queen II
竞赛 1041, 题目 F

描述
题目背景
一场突如其来的变故，导致Nova王国的上一任女王Fidelia在极为可疑的情况下去世。这样一来，王位就将交给Fidelia唯一的未成年女儿Elodie继承。

Nova王国的法律规定，Elodie必须在成年时才能正式登基继承王位。在此期间，她的父亲Joslyn将作为摄政王暂时统治Nova王国，而她必须在父亲Joslyn的帮助下学习处理政治。

然而，Nova王国正面临着内忧外患。

一方面，许多不满意现状的贵族都开始试探未来的新女王Elodie的能力，Elodie必须在舞会，庆典，宴会，仲裁，法庭审判，外交谈判，节日游行等活动中展现出足够的政治能力，否则，不满的贵族极有可能尝试挑起一场内战来改朝换代。

另外一方面，Elodie作为未成年少女，自然也不能结婚，因此目前没有任何在法理上具有继承权的后代。由于Nova王国奇特的继承法规定王位必须由未成年女性继承，在这种情况下，Elodie的舅舅Merva公爵的女儿Charlott，也是Elodie的表妹和最好的朋友，将作为王位的第二继承人。而一旦Elodie像她母亲一样，在极为可疑的情况下不幸去世，Charlott将会继承王位。尽管不愿意怀疑Merva公爵，但Elodie必须提防可能的袭击和刺杀，这就需要Elodie自身具有一定的特殊能力来应对极端情况。

同时，Nova王国正在面临着数个主要敌人的外部威胁，南部的Ixon王国目前非法占据了Nova王国的半个省份，东部的Talasse王国希望通过一场和Elodie的政治联姻兵不血刃的吞并Nova王国。更不要说海对面强大的Shanjia王国，在吞并了数个邻国后，已经把目光投向了主少国疑的Nova王国，随时准备发起一场入侵。这对Elodie将是一个艰巨的考验。

最后，我们将目光投向最关键的下层建筑。Nova王国常年以来的治理水平，虽然不能称得上是政通人和吧，至少也算的上是一个惨淡经营。Fidelia陛下在她任上勉强弹压的数次农民战争的余烬仍未冷却，而他们反弹的怒火似乎一次比一次强烈。王国下辖的各自由市的商人与小市民们并不满足于他们已有的特权，而这一欲望随着王室一次又一次的借贷与特别征税而熊熊燃烧。与此同时，来自海外的印刷机与火药，随同宗教改革的思潮一同淹向了Nova王国的边境。

当Elodie仍然沉浸在母亲过世的悲伤中时，国立教团的第二祭司Selene和女公爵Julianna告诉了Elodie一个惊天的秘密：之所以Nova王国的王位必须由未成年女性继承，是因为每一任Nova王国的统治者都将要在未成年未登基之时，举行许愿仪式，继承上一任女王的力量成为魔法少女……

(Music: https://music.163.com/#/song?id=2004668126)

题目描述
离继承王位还有一段日期，在这段时间内，为了应对上述危机，Elodie每天都要不断锻炼自己的政治能力和魔法能力。

Elodie每天可以学习一节课，她可以从政治课程和魔法特训课程中选择一门课程来学习。每次学习都将提高若干点对应的能力值。Elodie的初始政治能力和魔法能力均为 0 。

每天学习完毕后，Elodie可能面临一个挑战，如果Elodie的能力不足以通过这项挑战，则Elodie将无法顺利继承王位，迎来并不美好的结局。

请帮助Elodie选择每天的课程内容，让她能够活到加冕登基之日。

(Image: E:/Files/C/CLionProjects/SHOJ/2023niandi2zouzousai/F/download.jpg)

输入
第一行，一个正整数 t ，代表一共有 t 组数据。

对于每一组数据：

第一行，三个整数 n ，c_1 , c_2 ，代表Elodie还需要经过 n 天才能抵达加冕日，每次学习政治课程可以增加 c_1 点政治能力值，每次学习魔法课程可以增加 c_2 点魔法能力值。

接下来一共有 n 行输入，每行开头都有一个数字 o_i ，代表检定类型。

如果 o_i = 0 ， "今日无事"，Elodie在日记中写道。第 i 日她不需要通过任何检定。

如果 o_i = 1 ，则Elodie第 i 日只需要通过政治检定即可。接下来输入一个数字 a_i ，代表通过检定所需的最小政治能力值。

如果 o_i = 2 ，则Elodie第 i 日只需要通过魔法检定即可。接下来输入一个数字 b_i ，代表通过检定所需的最小魔法能力值。

如果 o_i = 3 ，则Elodie第 i 日需要通过一个政治检定再通过一个魔法检定。接下来输入两个数字 a_i 和 b_i ，代表通过检定所需的最小政治能力值和魔法能力值。

如果 o_i = 4 ，则Elodie第 i 日需要通过一个联合检定。接下来输入三个数字 s_i ，p_i 和 m_i，s_i 代表通过检定所需的最小能力总和，p_i 代表政治能力权重，m_i 代表魔法能力权重。（即，检定通过的条件为：政治能力值 *p_i +魔法能力值 *m_i >= s_i）。

如果Elodie不能通过任意一个检定，那么Elodie将无法继承王位导致BAD END。

输出
一共有 t 组输出。

对于每一组数据，请输出 YES 或 NO（区分大小写），代表Elodie是否有可能抵达加冕日。

样例输入
2
5 1 2
2 1
1 1
0
4 12 1 2
3 2 6
4 1 1
0
0
1 3
2 2
样例输出
YES
NO
提示
让我们祝愿Elodie长命百岁！

对于输入数据，我们保证：t belongs to [1,10^4],n belongs to [1,10^4],并且 n*t <= 10^6
c_1,c_2,p_i,m_i belongs to [0,10^3]
o belongs to [0,4]
a_i,b_i,s_i belongs to [0,10^9]
以上数字均为整数。



样例解释：

第一组数据解释如下：

Elodie一共需要活过 5 天。每次学习政治课程可以增加 1 点政治能力，每次学习魔法课程可以增加 2 点魔法能力。其初始政治能力和魔法能力为 0 .

下面我们给出一种可能的课程学习方案：

第一天Elodie选择了魔法课程，课程结束后，她的政治能力为 0 ，魔法能力为 2 。接下来她面临一个魔法检定，要求其具有至少 1 点魔法能力。Elodie通过了检定。

第二天Elodie选择了政治课程，课程结束后，她的政治能力为 1 ，魔法能力为 2 。接下来她面临一个政治检定，要求其具有至少 1 点政治能力。Elodie通过了检定。

第三天Elodie选择了魔法课程，课程结束后，她的政治能力为 1 ，魔法能力为 4 。今日Elodie平安无事。

第四天Elodie选择了魔法课程，课程结束后，她的政治能力为 1 ，魔法能力为 6 。接下来她面临一个联合检定，要求政治能力*1+魔法能力*2 >= 12。Elodie通过了检定。

第五天Elodie选择了政治课程，课程结束后，她的政治能力为 2 ，魔法能力为 6 。接下来她面临一个政治检定和魔法检定，要求其具有至少 2 点政治能力和 6 点魔法能力。Elodie通过了检定。

在该学习方案下，Elodie成功活到了登基日。



第二组数据解释如下：

Elodie一共需要活过4天，每次学习课程只能增加 1 点能力值。她在第三天需要至少具有 3 点政治能力，而在第四天需要至少具有 2 点魔法能力，而这是不可能实现的。Elodie注定无法活到加冕的那一天。

判题方式
本题采用   普通判题   。判题机读入用户输出，与参考答案逐一比对，除最末空白以外所有字符都相同，则判为正确。
*/

#include <stdio.h>

short aDb_E(int a, int b, short *K) {
    if ((a) && (!b)) {
        *K = 0;
        return 1;
    } else
        return 0;
}

int Celi_aDb(int a, int b) {
    if (b)
        if (a % b)
            return (a / b + 1);
        else
            return a / b;
    else
        return 0;
}

short Judge(int X[], unsigned int n) {
    int m_0 = 0, m_1 = 0, i;
    for (int *p = X; (i = (int) (p - X)) < n; p++) {
        if (*p > m_0)
            m_0 = *p;
        if (*(p + n) > m_1)
            m_1 = *(p + n);
        if (m_0 + m_1 > i + 1)
            return 0;
    }
    return 1;
}

int main() {
    short T = 0;
    scanf("%hd", &T);
    for (short t = 0; t < T; t++) {
        short n = 0;
        scanf("%hd", &n);
        int X[2][n];
        short c_1 = 0, c_2 = 0;
        scanf("%hd%hd", &c_1, &c_2);
        short K = 1, i;
        for (int *P = X[0]; (i = (short) (P - X[0])) < n; P++) {
            int *Q = P + n;
            short o = 0;
            scanf("%hd", &o);
            if (o == 4) {
                int s = 0;
                short p = 0, m = 0;
                scanf("%d%hd%hd", &s, &p, &m);
                int k = p * c_1 - m * c_2, y = s - m * c_2 * (i + 1);
                if (k > 0) {
                    if (y > 0)
                        *P = Celi_aDb(y, k);
                    else
                        *P = 0;
                    *Q = 0;
                } else if (k < 0) {
                    if (y > 0)
                        K = 0;
                    else
                        *P = y / k, *Q = i + 1 - X[0][i], *P = 0;
                } else {
                    if (y > 0)
                        K = 0;
                    else
                        *P = *Q = 0;
                }
            } else if (o == 3) {
                int a = 0, b = 0;
                scanf("%d%d", &a, &b);
                if (!(aDb_E(a, c_1, &K)) && (!aDb_E(b, c_2, &K)))
                    *P = Celi_aDb(a, c_1), *Q = Celi_aDb(b, c_2);
            } else if (o == 2) {
                int b = 0;
                scanf("%d", &b);
                if (!aDb_E(b, c_2, &K))
                    *P = 0, *Q = Celi_aDb(b, c_2);
            } else if (o == 1) {
                int a = 0;
                scanf("%d", &a);
                if (!aDb_E(a, c_1, &K))
                    *P = Celi_aDb(a, c_1), *Q = 0;
            } else
                *P = *Q = 0;
        }
        if ((K) && (Judge(X[0], n)))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
