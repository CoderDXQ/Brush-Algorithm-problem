#include<bits/stdc++.h>
using namespace std;
int main()//����ʵ�����ڴ���ȵ��Ƚ��ȳ�ԭ�� 
{
	bool a[1005]={0};
	int b[1005];
	int i,j=0,m,n,k=0,shu,ans=0;
	cin>>m>>n;
	for(i=1;i<=n;i++)
	{
		cin>>shu;
		if(a[shu]==0)
		{
			a[shu]=1;
		    j++;
		    if(j<=m)
		    {
			    ans++;
			    b[j]=shu;
		    }
		    else
		    {
		    	k++;
		    	ans++;
		    	b[j]=shu;
		    	a[b[k]]=0;
			}
	    }
		
	}
	cout<<ans<<endl;
}

