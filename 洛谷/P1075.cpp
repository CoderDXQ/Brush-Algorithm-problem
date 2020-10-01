//题目存在漏洞，“已知正整数n是两个不同的质数的乘积，试求出两者中较大的那个质数。”，因为质数不能再分解，因此只要a*b=n,a！=1，就能得出结果，不需要验证是不是质数
#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

bool prime(long long a);
int main()
{
    long long i,n;
    cin>>n;
    for(int i=1;i<=sqrt(n);i++)
    {
        if((n%i)==0)
        {
            if(prime(i) && prime(n/i))  //？？？类型转换
                cout<<n/i<<endl;    //？？？类型转换
        }
    }
    
    return 0;
}

bool prime(long long a)
{
    if(a==1 || a==2) return true;
    bool tag=true;
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
            tag=false;
    }

    return tag;
}