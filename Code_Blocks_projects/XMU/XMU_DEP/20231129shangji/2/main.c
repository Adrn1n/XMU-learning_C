/*
第2关：石子消耗游戏

任务描述
本关任务：编写一个代码程序解决石子消耗游戏问题。

相关知识
小明和小强在路上看到了一堆石子，数了数发现有N颗。无聊的他们决定玩一个游戏，由小明先取K颗石子，取完后换小强取，取2K颗，接着再换小明取，取3K颗，以此类推，他们轮流取，每次都比上一次多取K颗，问最后谁把石子取完（包括取的时候石子不够了），以及他们一共取了多少轮。请用函数嵌套来实现。

注意：你提交的代码将被插入到以下程序框架中一起编译，所以请不要提交全部代码。
//固定头部开始
#include <stdio.h>
void MingPick(int left, int k, int turn);
void QiangPick(int left, int k, int turn);
//固定头部结束
//你的代码开始
void MingPick(int left, int k, int turn)
{
}
void QiangPick(int left, int k, int turn)
{
}
//你的代码结束
//固定尾部开始
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    MingPick(n, k, 1);
    return 0;
}
//固定尾部结束
输入描述
输入只有一行，包括2个整数N，K，如题目所述。
（0<N,K<2^31）

输出描述
输出两行。第一行若小明先取完，则输出“MING!”，否则输出“QIANG!”。（不包括引号）

第二行输出一个整数，代表取的轮次数。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决分解质因数问题。

1、小明取3颗

2、小强取6颗

3、小明取9颗

4、小强取2颗（取完）

测试用例
平台会对你编写的代码进行测试：

测试输入：20 3；
预期输出：QIANG
*/

//固定头部开始
#include <stdio.h>
void MingPick(int left, int k, int turn);
void QiangPick(int left, int k, int turn);
//固定头部结束
//你的代码开始
void MingPick(int left, int k, int turn)
{
    left-=k*turn;
    if(left<=0)
        printf("MING!\n%d",turn);
    else
    {
        turn++;
        QiangPick(left,k,turn);
    }
}
void QiangPick(int left, int k, int turn)
{
    left-=k*turn;
    if(left<=0)
        printf("QIANG!\n%d",turn);
    else
    {
        turn++;
        MingPick(left,k,turn);
    }
}
//你的代码结束
//固定尾部开始
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    MingPick(n, k, 1);
    return 0;
}
//固定尾部结束
