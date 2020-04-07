#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int e[40005];
	cin>>n;
	if(n==1)
	{//特判
		cout<<0;
		return 0;
	 } 
	for(int i=1;i<=n;i++) e[i]=i;
	for(int i=2;i<=n;i++)
	    if(e[i]==i){
	        for(int j=i;j<=n;j+=i)
	            e[j]=e[j]/i*(i-1);
	    }
	int ans=0;
	for(int i=2;i<n;i++)//i<n排除了斜率为0的情况 
	    ans+=e[i];
	ans<<=1;//乘2 
	ans=ans+1+2;//2代表斜率为无穷大和0的情况，代表（2,2）这个点 
	cout<<ans;
	return 0;
}
