#include<bits/stdc++.h>
using namespace std;
int main()//本题实际是内存调度的先进先出原则 
{
	bool a[1005]={0};
	int b[1005];
	int i,j=0,m,n,k=0,shu,ans=0;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>shu;
		if (a[shu]==0)//标记+计数 
		{             //内存未满 
			j++; 
			ans++;
			a[shu]=1;
			b[j]=shu;
			if(j>m)//模拟换出实质，但不模拟过程 
		    {
				k++;
			    a[b[k]]=0;
		    }
		}
	}
	cout<<ans<<endl;
}
