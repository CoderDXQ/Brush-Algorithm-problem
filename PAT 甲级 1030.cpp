#include<bits/stdc++.h>
using namespace std;
const int MAXV=510;
const int INF=1000000000;
int n,m,st,ed,G[MAXV][MAXV],cost[MAXV][MAXV];//G是邻接矩阵，weight存储每个节点的权值
int d[MAXV],c[MAXV],pre[MAXV];
//d存储起点到某点的最短路径
int vis[MAXV]={false};//标记某点是否被访问过
void Dijkstra(int s)//s是传入的起点
{
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF);//c数组也要进行比较，且要赋值为最大值，因为在下面的松弛时，要取小的 
	for(int i=0;i<n;i++) pre[i]=i;//路径数组初始化 
	d[s]=0;c[s]=0;//重要初始化
	for(int i=0;i<n;i++)
	{int u=-1,MIN=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<MIN)
			{
			    u=j;MIN=d[j];
			}
		}
		if(u==-1)return;
		vis[u]=true;//标记访问
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
			    if(d[v]>d[u]+G[u][v])
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
					}
				else if(d[v]==d[u]+G[u][v])
				{
					if(c[v]>c[u]+cost[u][v])
					{
						c[v]=c[u]+cost[u][v];
						pre[v]=u;
					}
					}	
			}	
		 } 
	 } 
 } 
 void DFS(int v)
 {
 	if(v==st)
 	{
 		cout<<st<<' ';return;
	 }
	DFS(pre[v]);
	cout<<v<<' ';
 }
 int main()
 {
 	int u,v;
 	cin>>n>>m>>st>>ed;
 	fill(G[0],G[0]+MAXV*MAXV,INF);//cost数组不必初始化 
 	for(int i=0;i<m;i++)
 	{
 		cin>>u>>v;
 		cin>>G[u][v];
		cin>>cost[u][v];
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];//无向图
	 }
	 Dijkstra(st);
	 DFS(ed);//打印路径,注意是输入终点进行打印 
	 cout<<d[ed]<<' '<<c[ed]<<endl;
	 return 0; 
 }
