#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int f[1000005];
int main()
{//����������ֻ��1�������� 
	memset(a,true,sizeof(a));
	int l,r,n,m;
	cin>>n>>m;
    a[0]=a[1]=false;
    int t=sqrt(m);
	
	for(register int i=2;i<=t;i++)
	{//һ��������һ�����������ӱ���С 
		if(a[i])//i������ 
		    for(register int j=i+i;j<=m;j+=i)
		        if(a[j]==true) a[j]=false;//�����ı���ȫ���������� 
	}
	int sum=0;
	for(register int i=1;i<=m;i++)
	{
		if(a[i]==true) sum++;
		f[i]=sum;
	}//��ǰ׺�� 
	
	for(register int i=1;i<=n;i++)
	{
		cin>>l>>r;
		int num;
		if(a[l]==true)num=f[r]-f[l]+1;
		else num=f[r]-f[l];
		if(l<1||r>m) cout<<"Crossing the line"<<endl;
		else cout<<num<<endl;
	}
	
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
bool a[1000005];
int f[1000005];
int main()
{//����������ֻ��1�������� 
	memset(a,true,sizeof(a));
	int l,r,n,m;
	cin>>n>>m;
    a[0]=a[1]=false;
    int t=sqrt(m);
	
	for(register int i=2;i<=t;i++)
	{//һ��������һ�����������ӱ���С 
		if(a[i])
		    for(register int j=i+i;j<=m;j+=i)
		        if(a[j]==true) a[j]=false;
	}
	int sum=0;
	for(register int i=1;i<=m;i++)
	{
		if(a[i]==true) sum++;
		f[i]=sum;
	}
	
	for(register int i=1;i<=n;i++)
	{
		cin>>l>>r;
		if(l<1||r>m) cout<<"Crossing the line"<<endl;
		else cout<<f[r]-f[l-1]<<endl;
	}
	//f[l-1]����l�ǲ�������һ��������l 
	
	return 0;
}
