#include<stdio.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv=510;
const int INF=1000000000;

int m,n,c,s,numpath=0,G[maxv][maxv],weight[maxv];
int d[maxv],minneed=INF,minremain=INF;
bool vis[maxv]={false};
vector<int> pre[maxv];
vector<int> temppath,path;

void Dijkstra(int ss)
{
	fill(d,d+maxv,INF);
	for(int i=0;i<=n;i++)
	{
	    pre[i].push_back(i);
	}//对新生成的邻接邻接表进行初始化(由邻接矩阵生成邻接表) 
	d[ss]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1;int min=INF;
		for(int j=0;j<=n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}//找到出发点 
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					pre[v].clear();//更新邻接表 
					pre[v].push_back(u);
				}else if(d[v]==d[u]+G[u][v])
				{
					pre[v].push_back(u);
				}//Dijkstra的任务是生成新的邻接表 
			} 
		}
	 } 
}


void DFS(int v)
{
    if(v==0)
	{
		temppath.push_back(v);
		int need=0,remain=0;
		for(int i=temppath.size()-1;i>=0;i--)
		{
			int id=temppath[i];
			if(weight[id]>0)
			{
				remain+=weight[id];
			}
			else
			{
				if(remain>abs(weight[id]))
				{
					remain-=abs(weight[id]);
				}
				else
				{
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minneed)
		{
			minneed=need;
			minremain=remain;
			path=temppath;//#include<cstring> 
		}
		else if(need==minneed&&remain<minremain)
		{
			minremain=remain;
			path=temppath;
		}
		temppath.pop_back();
		return;
		}	
		temppath.push_back(v);
		for(int i=0;i<pre[v].size();i++)
		{
			DFS(pre[v][i]);
		}
		temppath.pop_back();
}


int main()
{
	scanf("%d%d%d%d",&c,&n,&s,&m);
	int u,v;
	fill(G[0],G[0]+maxv*maxv,INF);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&weight[i]);
		weight[i]-=c/2;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(0);
	DFS(s);
	printf("%d ",minneed);
	for(int i=path.size()-1;i>=0;i--)
	{
		printf("%d",path[i]);
		if(i>0) printf("->");
	}
	printf(" %d",minremain);
	return 0;
 } 
