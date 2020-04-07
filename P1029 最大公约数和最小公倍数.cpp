
#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0;
int gcd(int x,int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
 } 
 int main()
 {
 	cin>>n>>m;
 	int k=sqrt(m/n);
 	//cout<<k<<' ';
 	for(int i=1;i<=k;i++)
 	    {
 	    	int j=m/n/i;
 	    	int p=i*n,q=n*j;
 	    //	cout<<p<<' '<<q<<endl;
 	    	if((gcd(p,q)==n)&&(p*q==m*n)) ans++;
		 }
 	cout<<(ans<<1);
	 return 0;
 }
