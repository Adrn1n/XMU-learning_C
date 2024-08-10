/*
第3关：小明的考题2——数与单词

任务描述
本关任务：编写一个代码程序解决数与单词问题。

相关知识
上一道分段函数的题目被小强轻松秒杀了，这一次，小明知道该出有深度一点的题目了。“数学是科学之王”，小明对此坚信不疑！数学的强悍之处在于它能通过一种映射的关系，把两种不相关的东西联系在一起。 现在，小明想考小强的是，小强需要建立起阿拉伯数字与英文字母的对应关系，小明不想过于为难小强，就限制了一下定义域为0—9的10个数字，映射规则为：0—zero、1—one、…、9—nine，现在小明随便说一个0—9的数字，小强的程序能输出该数字对应的英文单词。

输入描述
输入一个[0,9]区间的整数

输出描述
输出该数字对应的英文单词

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决数与单词问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：8；
预期输出：eight
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x=0;
    scanf("%d",&x);
    switch (x)
    {
    case 0:
        printf("zero");
        break;
    case 1:
        printf("one");
        break;
    case 2:
        printf("two");
        break;
    case 3:
        printf("three");
        break;
    case 4:
        printf("four");
        break;
    case 5:
        printf("five");
        break;
    case 6:
        printf("six");
        break;
    case 7:
        printf("seven");
        break;
    case 8:
        printf("eight");
        break;
    case 9:
        printf("nine");
        break;
        /*
        default:
            break;
            */
    }
    return 0;
}
