#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,s,sum=0,out=0,a;
    cin>>n;
    while(cin>>a)//直到输入结束为止
    {
        for(int i=1;i<=a;i++)
        {
            cout<<out;
            sum++;
            if(sum%n==0) cout<<endl;
        }
        out=!out;

    }
    return 0;
}

#include <cstdio>
int N,p,q,t; // 定义四个变量，N如题所示，p记录正在处理的压缩码，q表示本行已输出的字符数量，t 表示输出的内容（0或1）
int main()
{
    for(scanf("%d",&N); ~scanf("%d",&p);t^=1)
// 上句共三个功能，分别是循环开始时读入 N ；不断读入 P 以及 每次循环后 t 交换 01 状态
    {
        for(; p--; q++) // 先执行一次 p-- ， 此后每次顺序执行 q++ , p-- ，直到 (p--) == 0 时结束本层循环
        {//下面是用ASCII码直接控制输出的
            if(q==N)q=0&putchar(10); // 如果输出达到 N 个，q置零并且输出换行符
            putchar(38+t); // 输出字符 0 或 1
        }
    }
}