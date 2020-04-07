#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//邻接表
struct Node
{
	int v,dis;
 } ;
vector<Node> Adj[maxv];
int n;
int d[maxv];
bool vis[maxv]={false};//必须要定义成全局变量 
void Dijkstra(int s)
{
	fill(d,d+maxv,INF);
	d[s]=0;
	for(int i=0;i<n;i++;)
	{
		int u=-1;min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int j=0;j<adj[u].size();j++)
		{
			int v=adj[u][j].v;
			if(vis[v]==false&&d[u]+adj[u][j]<d[v])
			{
	            d[v]=d[u]+adj[u][j].dis;			
			}
		}
	}
}

int main()
{
	
	
	
	
	
	
}
