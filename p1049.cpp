#include<bits/stdc++.h>
using namespace std;
int v,n;
int f[20005],vv[35];
int main()
{
	cin>>v;cin>>n;
	for(int i=1;i<=n;i++) cin>>vv[i];
	for(int i=1;i<=n;i++)
	    for(int j=v;j>=vv[i];j--)
	    {
	    	f[j]=max(f[j],f[j-vv[i]]+vv[i]);
		}
	cout<<v-f[v]<<endl;//一定是输出f[v],而不是f[n] 
	return 0;
 } 
