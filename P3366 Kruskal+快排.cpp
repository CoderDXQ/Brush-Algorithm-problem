#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,u,v,total;
struct edge{int start,to;long long val;}bian[2000005];
int f[100000];
long long ans;//找爹函数 
int find(int x){return (f[x]==x)?x:f[x]=find(f[x]);}
bool cmp(edge a,edge b){return a.val<b.val;}
inline void kruskal()
{
	for(int i=1;i<=m;i++)//遍历所有边 
	{
		u=find(bian[i].start);v=find(bian[i].to);
		if(u==v) continue;
		ans+=bian[i].val;
		f[u]=v;//并查集u、v的爹变成同一个爹操作 
		total++;
		if(total==n-1) break;
	} 
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) f[i]=i;//并查集赋初值
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d",&bian[i].start,&bian[i].to,&bian[i].val);
	 } 
	 sort(bian+1,bian+m+1,cmp);
	 kruskal();
	 printf("%d",ans);
	 return 0;
}
