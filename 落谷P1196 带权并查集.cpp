#include<bits/stdc++.h>
using namespace std;
int f[30001],s[30001],b[30001];
//s[]�洢�㵽���ľ��룬b[]�洢���ϴ�С 
int find(int z){
	if(f[z]==z) return z;
	int last=f[z];
	f[z]=find(f[z]);//·��ѹ�� 
	s[z]+=s[last];//���µ�ǰ�ڵ㵽���ľ��� 
	b[z]=b[f[z]];//�������ڼ��ϵĴ�С 
	return f[z];
} 
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=30000;i++){f[i]=i;s[i]=0;b[i]=1;}
	for(int i=1;i<=n;i++)
	{
		char ch;
		int x,y,dx,dy;
		cin>>ch>>dx>>dy;
		if(ch=='M'){
			dx=find(x);dy=find(y);
			f[dx]=dy;//��x����y�ĺ��� 
			s[dx]+=b[dy];//����x�ĸ����µĸ��ľ��� 
			b[dx]+=b[dy];//���¼��ϴ�С 
			b[dy]=b[dx];//���¼��ϴ�С 
		}
		if(ch=='C'){
			dx=find(x);dy=find(y);
			if(dx!=dy){cout<<-1<<endl;continue;}
			cout<<abs(s[x]-s[y])-1<<endl;
		}
	}
	return 0;
}
