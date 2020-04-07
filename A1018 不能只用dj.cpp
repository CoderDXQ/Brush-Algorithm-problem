#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxv=510;
const int INF=100000000;
int c,n,m,s,G[maxv][maxv];
int bike[maxv];
bool vis[maxv]={false};
int cost[maxv],d[maxv],pre[maxv];//d为距离，cost为获得的车辆数 ,pre记录路径 
void Dijkstra(int st)
{
	fill(vis,vis+maxv,false);
	fill(cost,cost+maxv,INF);
	fill(d,d+maxv,INF);
	for (int i=0;i<=n;i++) pre[i]=-1;
	d[st]=0;cost[st]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1;int min=INF;
		for(int j=0;j<=n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			//	printf("u=%d min=%d\n",u,min);
			}
		}
		if (u==-1) return;//等号是两个等于号 
		vis[u]=true;
		for(int v=0;v<=n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[v]>d[u]+G[u][v])
				{
					d[v]=d[u]+G[u][v];
					cost[v]=cost[u]+bike[v];
					pre[v]=u;
				//	printf("v=%d d[v]=%d\n",v,d[v]);
				}
				else if(d[v]==d[u]+G[u][v])
				{
					if(cost[v]>c&&cost[u]+bike[v]>c&&cost[v]>cost[u]+bike[v])
					{
						cost[v]=cost[u]+bike[v];
						pre[v]=u;
					}
				//	else {
					if(cost[v]>c&&cost[u]+bike[v]<c)
					{
						cost[v]=cost[u]+bike[v];
						pre[v]=u;
					}
					  if(cost[v]<c&&cost[u]+bike[v]<c&&cost[v]<cost[u]+bike[v])
					{
						cost[v]=cost[u]+bike[v];
						pre[v]=u;
					}
				//	}//要用else if 否则if语句间会互相影响 
				}
			}
		}
	}
} 
 void DFS(int v)
{
	if(v==0) 
	{
		printf("0->");
		return;
	}
	DFS(pre[v]);
	if(v!=s) printf("%d->",v);
	else printf("%d ",v);
}
 
 int main()
 {
 	scanf("%d%d%d%d",&c,&n,&s,&m);
 	for(int i=1;i<=n;i++)//一定要注意结合题意 
 	{
 		scanf("%d",&bike[i]);
	}
	int a,b,x;
	fill(G[0],G[0]+maxv*maxv,INF);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&x);
		G[a][b]=x;
		G[b][a]=x;
	}
 	Dijkstra(0);
 	
 	
 	if(cost[s]<=c)
 	{
 		printf("%d ",c-cost[s]);
 		DFS(s);
 		printf("0\n");
	}
	else
	{
		printf("0 ");
 		DFS(s);
 		printf("%d\n",cost[s]-c);
	}
 	return 0;
 }
