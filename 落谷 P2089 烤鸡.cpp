#include<iostream>
#include<cstdio>
using namespace std;
int n,ans1,ans2[10001][11],a[11];
void trys(int t,int m)
{
	if(t>10)//递归返回条件 
	{
		if(m==n)
		{
			ans1++;
			for(int i=1;i<=10;i++) ans2[ans1][i]=a[i];
		}
		return;
	}
	for(int i=1;i<=3;i++)
	{
	    if(m+i>n) break;//剪枝
		a[t]=i;
		trys(t+1,m+i);
		a[t]=0;//回溯	
	}
}
int main()
{
	cin>>n;
	trys(1,0);
	cout<<ans1<<endl;
	for(int i=1;i<=ans1;i++)//i的作用域仅在循环内部 
	{
		for(int j=1;j<=10;j++) cout<<ans2[i][j]<<" ";
	    cout<<endl;
	}
	return 0;
}
