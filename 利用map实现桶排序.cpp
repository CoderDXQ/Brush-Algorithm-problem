#include<bits/stdc++.h>
using namespace std;
map<int,int>a;
int main()
{
	int n,t,x,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(a[t]==0) sum++;
		a[t]++;
	 } 
	 cout<<sum<<endl;
	for(map<int,int>::iterator it=a.begin();it!=a.end();it++)
	{
		x=it->second;
		if(x)
		{
		    cout<<it->first<<' ';
		}
	}
	
}
