#include<bits/stdc++.h>
using namespace std;
int v[30],w[30],f[30005];
//f[]������±����Ǯ�� 
int n,m;
int main()
{
	cin>>n>>m;//n����Ǯ����m�Ǹ��� 
	for(int i=1;i<=m;i++)
	{
		cin>>v[i]>>w[i];
		w[i]=w[i]*v[i];
	}
	for(int i=1;i<=m;i++)
	{//ö��������Ʒ 
		for(int j=n;j>=v[i];j--)
		{//j����Ǯ�� 
			f[j]=max(f[j],f[j-v[i]]+w[i]);//�жϷ��뱳�����ǲ����� 
        //j>=v[i]��������� 
		}
	}
	cout<<f[n]<<endl;
	return 0;
 } 
