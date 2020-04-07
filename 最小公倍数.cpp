#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=0;
int gongbei(int n,int m)
{
	if(n<m) swap(n,m);
 	return n%m==0?n:n*m/__gcd(n,m);
 } 
 int main()
 {
 	cin>>n>>m;//默认n为大数 
	 /*
 	if(n<m) swap(n,m);
 	if(n%m==0) cout<<n;
 	else cout<<(n*m)/gcd(n,m);*/
 	cout<<gongbei(n,m);
	 return 0;
 }
