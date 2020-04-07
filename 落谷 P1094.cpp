#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,x,n,p[201],ans=0,mm;
	cin>>w>>n;
	for(int i=0;i<=w;i++) p[i]=0;//数组必须初始化 
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		p[x]++;
	}
	for(int i=w;i>=5;i--)//for循环内不能加判断语句 
	{
		if(p[i]>0)
		{
			for(int j=5;j<=w-i;j++)//贪心算法,必须是双向走 
			{
				if((p[i]>0)&&(p[j]>0))
				{
					mm=min(p[i],p[j]);
					if(i!=j) {p[i]=p[i]-mm;p[j]=p[j]-mm;ans+=mm;}
					if(i==j) {p[i]=p[i]-mm;ans+=(mm+1)/2;}
				}
			}
			if(p[i]>0) {ans+=p[i];p[i]=0;}
	    }
	}
	cout<<ans<<endl;
	return 0;
 } 
