#include<cstdio>
#include<algorithm>
using namespace std;
const int maxv=510;
const int INF=99999999;
int n,m,s,f,G[maxv][maxv];//n���� m�� s��� f�յ� 
int d[maxv],num[maxv],w[maxv];
int hand[maxv];
bool vis[maxv]={false};//������ȫ�ֱ��� 
void Dijkstra(int s)//�ڽӾ��� 
{
	fill(d,d+maxv,INF);
	d[s]=0;num[s]=1;w[s]=hand[s];//����ֵ�ǳ���Ҫ 
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
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++)
		{
			if(vis[v]==false&&G[u][v]!=INF)
			{
			
			if(d[u]+G[u][v]<d[v])
			{
				d[v]=d[u]+G[u][v];
				w[v]=w[u]+hand[v];
				num[v]=num[u];
			}
			else if(d[u]+G[u][v]==d[v])
			{
				num[v]=num[u]+num[v];
				if(w[u]+hand[v]>w[v]) w[v]=w[u]+hand[v];
			}
		}
		}
	}
}
int main()
{
	int u,v,ww,i;
	scanf("%d%d%d%d",&m,&n,&s,&f);
	for(i=0;i<m;++i) scanf("%d",&hand[i]);
	fill(G[0],G[0]+maxv*maxv,INF);//��ʼ��֮����ܶ����ڽӾ�������ݣ�˳���ܵ��� 
	for(i=0;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&ww);
		G[u][v]=ww;G[v][u]=ww;
	}
	Dijkstra(s);
    printf("%d ",num[f]);	
    printf("%d\n",w[f]);
	return 0;
}
