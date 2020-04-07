#include <bits/stdc++.h>
using namespace std;
int b[10001],i,j,k,m,n,t;
void work()
{
	for(int i=1;i<=m;i++)
	{
		for(j=n-1;j>=1;j--)
		   if(b[j]<b[j+1])
		       break;
		for(k=n;k>=1;k--)
		   if(b[k]>b[j])
		       break;
		swap(b[j],b[k]);
		j=j+1;k=n;
		while(j<k)
		{//原来就是升序排列 
			swap(b[j],b[k]);
			j++;k--;
		}
	}
}
int main()
{
	cin>>n>>m;
    for(i=1;i<=n;i++)cin>>b[i];	
	work();
	for(i=1;i<=n-1;i++) cout<<b[i]<<' ';
	cout<<b[n]<<endl;
	return 0;
}  
