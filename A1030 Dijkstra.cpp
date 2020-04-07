//Dijkstra算法 ——单源最短路径的算法 
#include<stdio.h> 
#include<cstring>
#include<algorithm>
using namespace std;
const int maxv=510;
const int INF=100000000;

int n,m,st,ed,G[maxv][maxv],cost[maxv][maxv];
int d[maxv],c[maxv],pre[maxv];//记录单源到每个目标的计算结果 
bool vis[maxv]={false};//标识是否访问过 

void Dijkstra(int s)
{
	fill(d,d+maxv,INF);
	fill(c,c+maxv,INF); 
	for(int i=0;i<n;i++) pre[i]=i;
	d[s]=0;
	c[s]=0;//初始化 
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if (vis[j]==false&&d[j]<min)//条件（1未被访问 2所有路径中权值最小的） 
            {//TIPS：d[s]=0,故找到的第一个点一定是s (第一次进入） 
            	u=j;// 第二次进入时，只有第一次访问的点的的d[s]和第一个d[v]不是INF 
            	min=d[j];//但d[s]被标记为false 
			}
		}//找出要访问的下一个点 
		if (u==-1) return;//全部访问过 
		vis[u]=true;//标记为访问使该顶点在下一次大循环执行上面的小循环时不会被找到 
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;//对d[v] 
				}else if(d[u]+G[u][v]==d[v])
				{
					if(c[u]+cost[u][v]<c[v])
					{
						c[v]=c[u]+cost[u][v];
						pre[v]=u;
					}	
				}	
			}
		}//连接上u，v之间的最短路径 
	}
}
void DFS(int v)
{
	if(v==st)
	{
		printf("%d ",v);
		return;
	}
	DFS(pre[v]);//下层函数返回之后本句就算执行完毕 
	printf("%d ",v);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	int u,v;
	fill(G[0],G[0]+maxv*maxv,INF);//初始化 
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];//完善图的数据 
	}
	Dijkstra(st);//查找目标路径 
	DFS(ed);//输出 
	printf("%d %d\n",d[ed],c[ed]);
	return 0;
}
