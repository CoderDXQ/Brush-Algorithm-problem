#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,x,n,p[201],ans=0,mm;
	cin>>w>>n;
	for(int i=0;i<=w;i++) p[i]=0;//��������ʼ�� 
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		p[x]++;
	}
	for(int i=w;i>=5&&i>=w/2;i--)
	{
		if(p[i]>0)//Ӧ����if������while 
		{
			for(int j=w-i;j>=5;j--)//̰���㷨 
			{
				if((p[i]>0)&&(p[j]>0))
				{
					mm=min(p[i],p[j]);
					p[i]-=mm;p[j]-=mm;
					ans+=mm;
				}
			}
			//��һ����while��Ӧ 
			if(p[i]>0) {ans+=p[i];}//��w=50��i=50ʱ��p[i]=-1 
		}
	}
	cout<<ans<<endl;
	return 0;
 } 
