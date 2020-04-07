#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int f[1000005];
int main()
{//素数的因子只有1和它本身 
	memset(a,true,sizeof(a));
	int l,r,n,m;
	cin>>n>>m;
    a[0]=a[1]=false;
    int t=sqrt(m);
	
	for(register int i=2;i<=t;i++)
	{//一个非质数一定有质数因子比他小 
		if(a[i])//i是质数 
		    for(register int j=i+i;j<=m;j+=i)
		        if(a[j]==true) a[j]=false;//质数的倍数全部不是质数 
	}
	int sum=0;
	for(register int i=1;i<=m;i++)
	{
		if(a[i]==true) sum++;
		f[i]=sum;
	}//求前缀和 
	
	for(register int i=1;i<=n;i++)
	{
		cin>>l>>r;
		int num;
		if(a[l]==true)num=f[r]-f[l]+1;
		else num=f[r]-f[l];
		if(l<1||r>m) cout<<"Crossing the line"<<endl;
		else cout<<num<<endl;
	}
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int f[1000005];
int main()
{//素数的因子只有1和它本身 
	memset(a,true,sizeof(a));
	int l,r,n,m;
	cin>>n>>m;
    a[0]=a[1]=false;
    int t=sqrt(m);
	
	for(register int i=2;i<=t;i++)
	{//一个非质数一定有质数因子比他小 
		if(a[i])
		    for(register int j=i+i;j<=m;j+=i)
		        if(a[j]==true) a[j]=false;
	}
	int sum=0;
	for(register int i=1;i<=m;i++)
	{
		if(a[i]==true) sum++;
		f[i]=sum;
	}
	
	for(register int i=1;i<=n;i++)
	{
		cin>>l>>r;
		if(l<1||r>m) cout<<"Crossing the line"<<endl;
		else cout<<f[r]-f[l-1]<<endl;
	}
	//f[l-1]不管l是不是质数一定不包含l 
	
	return 0;
}
