/*
第5关：高精度乘法

任务描述
本关任务：编写一个代码程序解决高精度乘法问题。

相关知识
之前做过了一道关于高精度加法的，想必难不倒大家，那么请大家现在尝试一下高精度乘法吧！

#include <stdio.h>
#include <string.h>
// 大整数相加函数
void multiply(char num1[], char num2[], char result[]) {
    //********** Begin **********
    //*********** End **********
}
int main() {
    char num1[1001];
    char num2[1001];
    char result[2002];
    scanf("%s", num1);
    scanf("%s", num2);
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0) {
    printf("0\n");
    return 0;
}
    multiply(num1, num2, result);
    printf("%s\n", result);
    return 0;
}
输入描述
输入包括两行。

第一行一个整数A，第二行一个整数B。（0≤A,B≤10^1000）

输出描述
输出一行，A和B的乘积。

编程要求
根据提示，在右侧编辑器补充代码，编写一个代码程序解决高精度乘法问题。

测试用例
平台会对你编写的代码进行测试：

测试输入：
111111111111
111111111111
预期输出：12345679012320987654321
*/

#include <stdio.h>
#include <string.h>
// 大整数相加函数
void multiply(char num1[], char num2[], char result[])
{
    //********** Begin **********
    unsigned int m=0,n=0,k=1,l=1;
    for(unsigned int i=0; ; i++)
    {
        if(k&&(!(num1[i])))
        {
            m=i;
            k=0;
        }
        if(l&&(!(num2[i])))
        {
            n=i;
            l=0;
        }
        if((!k)&&(!l))
            break;
    }
    unsigned int R[m+n];
    for(unsigned int i=0; i<m+n; i++)
        R[i]=0;
    for(unsigned int i=n-1; i<=n-1; i--)
    {
        for(unsigned int j=m-1; j<=m-1; j--)
            R[(m-i)+(n-j)-2]+=(num1[j]-'0')*(num2[i]-'0');
    }
    for(unsigned int i=0; i<m+n; i++)
    {
        R[i+1]+=R[i]/10;
        R[i]%=10;
    }
    for(unsigned int i=1; i<=m+n; i++)
    {
        if(R[m+n-i])
        {
            k=m+n-i+1;
            break;
        }
    }
    for(unsigned int i=k-1; i<=k-1; i--)
        result[k-1-i]=R[i]+'0';
    result[k]=0;
    //*********** End **********
}
int main()
{
    char num1[1001];
    char num2[1001];
    char result[2002];
    scanf("%s", num1);
    scanf("%s", num2);
    if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
    {
        printf("0\n");
        return 0;
    }
    multiply(num1, num2, result);
    printf("%s\n", result);
    return 0;
}
