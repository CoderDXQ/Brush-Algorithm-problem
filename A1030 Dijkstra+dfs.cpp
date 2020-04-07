#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxv=510;
const int INF=100000000;
int n,m,st,ed,G[maxv][maxv],cost[maxv][maxv];
int d[maxv],mincost=INF;
bool vis[maxv]={false};
vector<int> pre[maxv];//�ڽӱ� 
vector<int> temppath,path;
void Dijkstra(int s)
{
	fill(d,d+maxv,INF);
	d[s]=0;
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
		    if(vis[j]==false&&d[j]<min)
			{
				u=j;
				min=d[j];
				}	
		}
		if(u==-1) return;//���ж��㶼���ʹ� 
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(d[u]+G[u][v]<d[v])
			{
				d[v]=d[u]+G[u][v];
				pre[v].clear();
				pre[v].push_back(u);
			}else if(d[u]+G[u][v]==d[v])
			{
				pre[v].push_back(u);//�������·�����ڽӱ���DFS�����ҳ���С���� 
			}
		}
	}	
}
void DFS(int v)
{
	if(v==st){
		temppath.push_back(v);
		int tempcost=0;
		for(int i=temppath.size()-1;i>0;i--)
		{
			int id=temppath[i],idnext=temppath[i-1];
			tempcost+=cost[id][idnext];//temppath��ŵ�����ʱ·�� 
		}
		if(tempcost<mincost)
		{
			mincost=tempcost;
			path=temppath;
		}
		temppath.pop_back();//�������һ�����㣬����ѹ����һ�� 
		return;
	}
	
	temppath.push_back(v);
	for(int i=0;i<pre[v].size();i++)
	{
		DFS(pre[v][i]);
	}
	temppath.pop_back();//�������V���㣬����ѹ����һ�� 
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed); 
	int u,v;
	fill(G[0],G[0]+maxv*maxv,INF);
	fill(cost[0],cost[0]+maxv*maxv,INF);//��ʼ�� 
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];
	}//��ȫ��Ϣ 
	Dijkstra(st);
	DFS(ed);
	for(int i=path.size()-1;i>=0;i--)
	{
		printf("%d ",path[i]);
	}
	printf("%d %d\n",d[ed],mincost);
	return 0;
}











