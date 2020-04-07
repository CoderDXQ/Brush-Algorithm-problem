#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int a[1005];
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<(int)(a[1]+a[2])/2<<' ';
	for(int i=2;i<=n-1;i++)
	    cout<<(int)(a[i-1]+a[i+1]+a[i])/3<<' ';
	cout<<(int)(a[n]+a[n-1])/2<<endl;
	
	return 0;
 } 
