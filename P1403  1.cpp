#include<bits/stdc++.h>
using namespace std;

int main()
{
	int f[100];
	int i,j,k,l,n,ans=0;
	memset(f,0,sizeof(f));
	cin>>n;
	for(int i=1;i<100;i++)
	{
		for(j=1;j<=i;j++)
		{
			if(i%j==0) f[i]++;
		}
		ans+=f[i];
		//cout<<i<<' '<<f[i]<<endl;
	}
	cout<<ans;
	return 0;
}
