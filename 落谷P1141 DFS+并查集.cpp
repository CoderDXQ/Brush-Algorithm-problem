#include<bits/stdc++.h>
using namespace std;
#define union unionn
int f[1000005],h[1000005],n;//h[]里面 
int st[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char s[1005][1005];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void union(int x,int y){
	int r1=find(x),r2=find(y);
	if(r1!=r2) h[r1]+=h[r2],f[r2]=f[r1];//
}
int dfs(int fi,int fj){
	if(f[fi*n+fj]!=-1) return find(fi*n+fj);
	f[fi*n+fj]=fi*n+fj,h[fi*n+fj]=1;
	for(int k=0;k<4;k++)
	{
		int i=fi+st[k][0],j=fj+st[k][1];
		if(i>=0&&i<n&&j>=0&&j<n&&s[fi][fj]!=s[i][j]) union(fi*n+fj,dfs(i,j)); 
	}
	return find(fi*n+fj);
}
int main()
{
	int t;
	cin>>n>>t;
	memset(f,-1,sizeof(f));//学习一下
	for(int i=0;i<n;i++) cin>>s[i];//本题只能用字符串来输入，因为数字之间没有空格 
	int i,j;
	while(t--){
		cin>>i>>j;
		cout<<h[dfs(i-1,j-1)]<<endl;//????????
		
	} 
	return 0;
}
