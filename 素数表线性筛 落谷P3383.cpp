//普通筛法（倍增标记） 
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000010;
bool prime[maxn];
int main()
{
	int m,x,n;//64位系统中，int可以表示的数据范围是 -2147483648~+2147483647
	cin>>n;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	int t=sqrt(n);
	for(register int i=2;i<=t;i++)//寄存器变量优化 ，能快六分之一 
	{
		if(prime[i])
		{
			for(register int j=2*i;j<=n;j+=i)
			{
				if(prime[j]==true)prime[j]=false;
			}
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
 
 
 
 
 
 
 
 
 
 
 
 
 
