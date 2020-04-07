#include<bits/stdc++.h>
using namespace std;
int f[30001],s[30001],b[30001];
//s[]存储点到根的距离，b[]存储集合大小 
int find(int z){
	if(f[z]==z) return z;
	int last=f[z];
	f[z]=find(f[z]);//路径压缩 
	s[z]+=s[last];//更新当前节点到根的距离 
	b[z]=b[f[z]];//更新所在集合的大小 
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
			f[dx]=dy;//把x放在y的后面 
			s[dx]+=b[dy];//更新x的根到新的根的距离 
			b[dx]+=b[dy];//更新集合大小 
			b[dy]=b[dx];//更新集合大小 
		}
		if(ch=='C'){
			dx=find(x);dy=find(y);
			if(dx!=dy){cout<<-1<<endl;continue;}
			cout<<abs(s[x]-s[y])-1<<endl;
		}
	}
	return 0;
}
