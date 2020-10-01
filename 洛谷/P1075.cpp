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


//欧拉筛法  
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000010;
bool prime[maxn];//标记是否是素数 
int Prime[maxn];//存储素数表 
int num=0;
int main()
{
	int m,x,n;//64位系统中，int可以表示的数据范围是 -2147483648~+2147483647
	cin>>n;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==1) Prime[num++]=i;//i早已被他的因数筛查过
		for(int j=0;j<num&&Prime[j]*i<=n;j++)//不加Prime[j]*i<=n可能在运行下一句时超界 
		{
			prime[i*Prime[j]]=false;//筛选 标记
			if(i%Prime[j]==0) break;
			//剪枝 i>Prime[j]，若 i%Prime[j]==0则i的倍数早已被 Prime[j]筛查过 
		 } 
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		if(prime[x]==true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
} 