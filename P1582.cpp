#include<bits/stdc++.h>
using namespace std;
//����ʵ�������ò�����k��1��������0����һ����ӽ��Ҵ���n�Ķ������� 
int main()
{
	long long n,k,s=0,mi=2000000000;
	long long a[32];
	bool b[32];
	memset(b,false,sizeof(b));
	a[0]=1;
	for(int i=1;i<=31;i++) a[i]=a[i-1]<<1;
	cin>>n>>k;
	while(n>0&&s<k)
	{
		for(int i=0;i<=31;i++)
		    if(n<a[i]&&b[i]==false) 
		    {
		    	mi=min(mi,a[i]-n);//��¼�ڽ���iλ����Ϊ1ʱ��Ҫ�����ƿ���� 
		    	s++;
		    	int k=i-1;
		    	while (b[k]==true&&k>=0) k--;
				//������iλ���Ϊ��ʱ��Ӧ�ý���һλ���Ϊ1���ܸ��ӽ�n 
		    	if(k==-1)
		    	{
		    		cout<<mi;
					return 0;
				}
				n-=a[k];//����n 
				b[k]=true;//����ù�����һλ 
				break;
			}
			else if(n==a[i]&&b[i]==false)
			{
				cout<<0;
				return 0;	
			}
	}
	cout<<mi;
	return 0;
}
