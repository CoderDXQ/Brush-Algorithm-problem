#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool a[1000005];
	int n,sum=0,l,r;
	bool b;
	memset(a,0,sizeof(a));
	cin>>n;
	for(register int i=1;i<=n;i++)
	{
		cin>>l>>r;
		for(int j=l;j<r;j++)
		    a[j]=1;
	}//用点来向右代表区间 
	for(register int i=1;i<=n;i++)
	{ 
	    cin>>l>>r;
		for(int j=l;j<r;j++)
		{
			if(a[j]==1) sum++;
			}    
		//if(b==true) sum--;
	}
	cout<<sum<<endl;
	return 0;
} 
