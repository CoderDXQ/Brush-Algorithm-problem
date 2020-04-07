#include<bits/stdc++.h>
using namespace std;
//模拟的思路一定会超时 
int main()
{
	//int f[10000000];
	int k,l,n,ans=0;
	//memset(f,0,sizeof(f));
	cin>>n;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=i;j++)
		{
			if(i%j==0) ans++;
		}
	//	ans+=f[i];
		//cout<<i<<' '<<f[i]<<endl;
	}
	cout<<ans;
	return 0;
}
