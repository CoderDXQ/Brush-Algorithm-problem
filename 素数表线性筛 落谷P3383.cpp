//��ͨɸ����������ǣ� 
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000010;
bool prime[maxn];
int main()
{
	int m,x,n;//64λϵͳ�У�int���Ա�ʾ�����ݷ�Χ�� -2147483648~+2147483647
	cin>>n;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	int t=sqrt(n);
	for(register int i=2;i<=t;i++)//�Ĵ��������Ż� ���ܿ�����֮һ 
	{
		if(prime[i])
		{
			for(register int j=2*i;j<=n;j+=i)
			{
				if(prime[j]==true)prime[j]=false;
			}
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		if(prime[x]==true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
 } 
 
//ŷ��ɸ��  
#include<bits/stdc++.h>
using namespace std;
const int maxn=10000010;
bool prime[maxn];//����Ƿ������� 
int Prime[maxn];//�洢������ 
int num=0;
int main()
{
	int m,x,n;//64λϵͳ�У�int���Ա�ʾ�����ݷ�Χ�� -2147483648~+2147483647
	cin>>n;
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(prime[i]==1) Prime[num++]=i;//i���ѱ���������ɸ���
		for(int j=0;j<num&&Prime[j]*i<=n;j++)//����Prime[j]*i<=n������������һ��ʱ���� 
		{
			prime[i*Prime[j]]=false;//ɸѡ ���
			if(i%Prime[j]==0) break;
			//��֦ i>Prime[j]���� i%Prime[j]==0��i�ı������ѱ� Prime[j]ɸ��� 
		 } 
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
		if(prime[x]==true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
 } 
 
 
 
 
 
 
 
 
 
 
 
 
 
