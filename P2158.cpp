#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int e[40005];
	cin>>n;
	if(n==1)
	{//����
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
	for(int i=2;i<n;i++)//i<n�ų���б��Ϊ0����� 
	    ans+=e[i];
	ans<<=1;//��2 
	ans=ans+1+2;//2����б��Ϊ������0�����������2,2������� 
	cout<<ans;
	return 0;
}
