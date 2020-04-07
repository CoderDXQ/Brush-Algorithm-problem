#include<bits/stdc++.h>
using namespace std;
const long long INF=2147483647;
const int maxn=100005;
const int maxm=500005;
int n,m,s,w,num_edge=0;
int dis[maxn],vis[maxn],head[maxm];
struct Edge
{
	int next,to,dis;
}edge[maxm];
inline int read()//读入优化 
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x; 
}
inline void write(int x)//输出优化 
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void addedge(int from,int to,int dis)
{//前向星 
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
inline void spfa()
{//spfa核心就是不停地入队出队 ，不止遍历一次邻接表 
	queue<int>q;
	for(register int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
	}//初始化 
	q.push(s);dis[s]=0;vis[s]=1;//重要初始化
	while(!q.empty()){
		int u=q.front();
		q.pop();vis[u]=0;//出队标记 
		for(register int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].dis)
			{
				dis[v]=dis[u]+edge[i].dis;
				if(vis[v]==0)//未入队 
				{
					vis[v]=1;//入队标记 
					q.push(v);
			}
		 } 
	 } 
}}
int main()
{
	n=read();m=read();s=read(); 
	for(register int i=1;i<=m;i++){
		int f,g,w;
		f=read();g=read();w=read();
		addedge(f,g,w);}
	spfa();
	for(register int i=1;i<=n;i++)
	    if(s==i) write(0),putchar(' ');
	    else write(dis[i]),putchar(' ');
	return 0;
}
