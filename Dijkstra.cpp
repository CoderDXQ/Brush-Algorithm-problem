#include<cstdio>
#include<algorithm>

void Dijkstra(int s)//ÁÚ½Ó¾ØÕó 
{
	fill(d,d+maxv,INF);
	d[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1;min=INF;
		for(int j=0;j<n;j++)
		{
			if(vis[j==false&&d[j]<min])
			{
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v])
			{
				d[v]=d[u]+G[u][v];
			}
		}
	}
}

int main()
{
	int n,G[maxv][maxv];
	int a[maxv];
	bool vis[maxv];
	
	
	
	
}
