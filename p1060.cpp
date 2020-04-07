#include<bits/stdc++.h>
using namespace std;
int v[30],w[30],f[30005];
//f[]数组的下标代表钱数 
int n,m;
int main()
{
	cin>>n>>m;//n是总钱数，m是个数 
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>w[i];
		w[i]=w[i]*v[i];
	}
	for(int i=1;i<=m;i++)
	{//枚举所有物品 
		for(int j=n;j>=v[i];j--)
		{//j代表钱数 
			f[j]=max(f[j],f[j-v[i]]+w[i]);//判断放入背包还是不放入 
        //j>=v[i]代表买得起 
		}
	}
	cout<<f[n]<<endl;
	return 0;
 } 
