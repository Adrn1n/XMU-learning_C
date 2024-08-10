/*
来玩2048吧
竞赛 1042, 题目 E

描述
2048游戏的规则是：

1. 游戏棋盘是一个4x4的方格，每个方格中都可以有一个数字。
2. 每一步，玩家可以通过选择上、下、左、右四个方向中的一个，令棋盘上的方块都朝该方向运动，直至撞到边界或者另一个方块。
3. 滑动后，若相邻的两个方块数字相同，它们会合并成一个新的方块，数字为原方块数字的两倍。
4. 每次滑动后，棋盘上会随机出现一个数字为2或4的新方块，出现2的概率更高（在本题中，分别设为7/8与1/8）。
5. 当棋盘上没有空格时，且无法进行进一步合并时，游戏结束。
6. 游戏的得分是所有合并过程中产生的方块数字的总和。
现在，已经有一个简单的2048游戏程序，你需要实现decide函数，来决定每一步往哪个方向滑动，以尽可能获得高分。如果你在所有测试点中均在100步以内得到250分或更高，则会被认为通过。（如果在你的策略下，某次游戏未达到100步就已经结束，但此时分数已达到250分，这也会被算作通过。）

输入
本题为交互题，你需要完成以下代码并提交：

#include "2048.h"
int decide(int (*board)[4])
{
   // write your code here
}
你可以把参数board当成4x4的二维int数组使用，它存储了棋盘的每个方格中的数，如果方格中没有数则为0。

你只需要实现这个函数，你不需要自己编写main函数，也不需要自己处理I/O。

输出
decide函数的返回值为一个0到3的整数，0表示向上，1表示向下，2表示向左，3表示向右。

样例输入
本题没有样例输入数据。

样例输出
本题没有样例输出数据。

提示
请你在你的程序开头写下：

#include "2048.h"
为了方便你的调试，这里提供头文件：

2048.h  (./2048.h)

请不要在你的程序中使用2048.h中以下划线开头的函数和变量。

在本地调试运行时，你需要先输入随便一个整数作为随机数种子，然后可以一步一步地查看游戏在你的策略下的进程（按回车查看下一步）。

判题方式
本题采用   特殊判题   。判题机根据出题人制作的判题程序读入用户输出，符合既定规则，则判为正确。该模式下，用户输出不需要与参考答案每个字符都相同。
*/

#include "2048.h"

int decide(int (*board)[4]) {
    // write your code here
    int Tmp[4][4] = {0};
    memcpy(Tmp, board, 4 * 4 * sizeof(int));
    short move = -1, score = 0, score_tmp, move_flag[4] = {0};
    for (int(*p)[4] = Tmp + 1; p - Tmp < 4; p++)
        for (int *q = *p; q - *p < 4; q++)
            if (*q) {
                if (*(q - 4)) {
                    if (*(q - 4) == *q) {
                        *(q - 4) += *q, *(q - 4) = -(*(q - 4)), *q = 0;
                        score -= *(q - 4);
                        *move_flag = 1;
                        move = 0;
                    }
                } else {
                    int *ptr = q - 4;
                    for (; (ptr - *Tmp >= 4) && ((!(*(ptr - 4))) || (*(ptr - 4) == *q)); ptr -= 4);
                    if (*ptr == *q) {
                        *ptr += *q, *ptr = -(*ptr), *q = 0;
                        score -= *ptr;
                        move = 0;
                    } else if (!(*ptr))
                        *ptr = *q, *q = 0;
                    else
                        return -1;
                    *move_flag = 1;
                }
            }
    memcpy(Tmp, board, 4 * 4 * sizeof(int)), score_tmp = 0;
    for (int(*p)[4] = Tmp + 2; p - Tmp >= 0; p--)
        for (int *q = *p; q - *p < 4; q++)
            if (*q) {
                if (*(q + 4)) {
                    if (*(q + 4) == *q) {
                        *(q + 4) += *q, *(q + 4) = -(*(q + 4)), *q = 0;
                        score_tmp -= *(q + 4);
                        move_flag[1] = 1;
                    }
                } else {
                    int *ptr = q + 4;
                    for (; (Tmp[3] + 3 - ptr >= 4) && ((!(*(ptr + 4))) || (*(ptr + 4) == *q)); ptr += 4);
                    if (*ptr == *q) {
                        *ptr += *q, *ptr = -(*ptr), *q = 0;
                        score_tmp -= *ptr;
                    } else if (!(*ptr))
                        *ptr = *q, *q = 0;
                    else
                        return -1;
                    move_flag[1] = 1;
                }
            }
    if (score_tmp > score)
        score = score_tmp, move = 1;
    memcpy(Tmp, board, 4 * 4 * sizeof(int)), score_tmp = 0;
    for (int *p = *Tmp + 1; p - *Tmp < 4; p++)
        for (int *q = p; q - p < 4 * 4; q += 4)
            if (*q) {
                if (*(q - 1)) {
                    if (*(q - 1) == *q) {
                        *(q - 1) += *q, *(q - 1) = -(*(q - 1)), *q = 0;
                        score_tmp -= *(q - 1);
                        move_flag[2] = 1;
                    }
                } else {
                    int *ptr = q - 1;
                    for (; (((ptr - *Tmp) % 4) > 0) && ((!(*(ptr - 1))) || (*(ptr - 1) == *q)); ptr--);
                    if (*ptr == *q) {
                        *ptr += *q, *ptr = -(*ptr), *q = 0;
                        score_tmp -= *ptr;
                    } else if (!(*ptr))
                        *ptr = *q, *q = 0;
                    else
                        return -1;
                    move_flag[2] = 1;
                }
            }
    if (score_tmp > score)
        score = score_tmp, move = 2;
    memcpy(Tmp, board, 4 * 4 * sizeof(int)), score_tmp = 0;
    for (int *p = *Tmp + 2; p - *Tmp >= 0; p--)
        for (int *q = p; q - p < 4 * 4; q += 4)
            if (*q) {
                if (*(q + 1)) {
                    if (*(q + 1) == *q) {
                        *(q + 1) += *q, *(q + 1) = -(*(q + 1)), *q = 0;
                        score_tmp -= *(q + 1);
                        move_flag[3] = 1;
                    }
                } else {
                    int *ptr = q + 1;
                    for (; (((ptr - *Tmp) % 4) < 3) && ((!(*(ptr + 1))) || (*(ptr + 1) == *q)); ptr++);
                    if (*ptr == *q) {
                        *ptr += *q, *ptr = -(*ptr), *q = 0;
                        score_tmp -= *ptr;
                    } else if (!(*ptr))
                        *ptr = *q, *q = 0;
                    else
                        return -1;
                    move_flag[3] = 1;
                }
            }
    if (score_tmp > score)
        move = 3;
    if (move < 0) {
        short num = 0;
        for (short *p = move_flag; p - move_flag < 4; p++)
            if (*p)
                num++;
        int a = rand();
        a %= num, ++a;
        for (short *p = move_flag; p - move_flag < 4; p++)
            if (*p)
                if (--a) {
                    move = (short) (p - move_flag);
                    break;
                }
    }
    return move;
}
