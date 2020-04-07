#include<bits/stdc++.h>
using namespace std;
int t,m; 
int ti[10005],value[10005];
long long f[100005];
int main()
{
	cin>>t>>m;
	for(int i=1;i<=m;i++) {cin>>ti[i]>>value[i];}    
	for(int i=1;i<=m;i++)
	    for(int j=ti[i];j<=t;j++)
	    {//三重循环一定会超时 
	    	f[j]=max(f[j],f[j-ti[i]]+value[i]);
		}
	cout<<f[t]<<endl;
	return 0;
 } 
