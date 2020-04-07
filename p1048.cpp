#include<bits/stdc++.h>
using namespace std;
#define time ti
int t,m; 
int time[105],value[105];
int f[1005];
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++) cin>>time[i]>>value[i];
	for(int i=1;i<=m;i++)
	    for(int j=t;j>=time[i];j--)
	    {
	    	f[j]=max(f[j],f[j-time[i]]+value[i]);
		}
	cout<<f[t]<<endl;
	return 0;
 } 
