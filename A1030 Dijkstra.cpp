//Dijkstra�㷨 ������Դ���·�����㷨 
#include<stdio.h> 
#include<cstring>
#include<algorithm>
using namespace std;
const int maxv=510;
const int INF=100000000;

int n,m,st,ed,G[maxv][maxv],cost[maxv][maxv];
int d[maxv],c[maxv],pre[maxv];//��¼��Դ��ÿ��Ŀ��ļ����� 
bool vis[maxv]={false};//��ʶ�Ƿ���ʹ� 

void Dijkstra(int s)
{
	fill(d,d+maxv,INF);
	fill(c,c+maxv,INF); 
	for(int i=0;i<n;i++) pre[i]=i;
	d[s]=0;
	c[s]=0;//��ʼ�� 
	for(int i=0;i<n;i++)
	{
		int u=-1,min=INF;
		for(int j=0;j<n;j++)
		{
			if (vis[j]==false&&d[j]<min)//������1δ������ 2����·����Ȩֵ��С�ģ� 
            {//TIPS��d[s]=0,���ҵ��ĵ�һ����һ����s (��һ�ν��룩 
            	u=j;// �ڶ��ν���ʱ��ֻ�е�һ�η��ʵĵ�ĵ�d[s]�͵�һ��d[v]����INF 
            	min=d[j];//��d[s]�����Ϊfalse 
			}
		}//�ҳ�Ҫ���ʵ���һ���� 
		if (u==-1) return;//ȫ�����ʹ� 
		vis[u]=true;//���Ϊ����ʹ�ö�������һ�δ�ѭ��ִ�������Сѭ��ʱ���ᱻ�ҵ� 
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
				if(d[u]+G[u][v]<d[v])
				{
					d[v]=d[u]+G[u][v];
					c[v]=c[u]+cost[u][v];
					pre[v]=u;//��d[v] 
				}else if(d[u]+G[u][v]==d[v])
				{
					if(c[u]+cost[u][v]<c[v])
					{
						c[v]=c[u]+cost[u][v];
						pre[v]=u;
					}	
				}	
			}
		}//������u��v֮������·�� 
	}
}
void DFS(int v)
{
	if(v==st)
	{
		printf("%d ",v);
		return;
	}
	DFS(pre[v]);//�²㺯������֮�󱾾����ִ����� 
	printf("%d ",v);
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	int u,v;
	fill(G[0],G[0]+maxv*maxv,INF);//��ʼ�� 
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];//����ͼ������ 
	}
	Dijkstra(st);//����Ŀ��·�� 
	DFS(ed);//��� 
	printf("%d %d\n",d[ed],c[ed]);
	return 0;
}
