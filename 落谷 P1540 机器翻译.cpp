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
		if (a[shu]==0)//���+���� 
		{             //�ڴ�δ�� 
			j++; 
			ans++;
			a[shu]=1;
			b[j]=shu;
			if(j>m)//ģ�⻻��ʵ�ʣ�����ģ����� 
		    {
				k++;
			    a[b[k]]=0;
		    }
		}
	}
	cout<<ans<<endl;
}
