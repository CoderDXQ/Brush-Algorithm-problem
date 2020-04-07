#include<bits/stdc++.h>
using namespace std;
const int MAXV=510;
const int INF=1000000000;
int n,m,st,ed,G[MAXV][MAXV],cost[MAXV][MAXV];//G���ڽӾ���weight�洢ÿ���ڵ��Ȩֵ
int d[MAXV],c[MAXV],pre[MAXV];
//d�洢��㵽ĳ������·��
int vis[MAXV]={false};//���ĳ���Ƿ񱻷��ʹ�
void Dijkstra(int s)//s�Ǵ�������
{
	fill(d,d+MAXV,INF);
	fill(c,c+MAXV,INF);//c����ҲҪ���бȽϣ���Ҫ��ֵΪ���ֵ����Ϊ��������ɳ�ʱ��ҪȡС�� 
	for(int i=0;i<n;i++) pre[i]=i;//·�������ʼ�� 
	d[s]=0;c[s]=0;//��Ҫ��ʼ��
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
		vis[u]=true;//��Ƿ���
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
 	fill(G[0],G[0]+MAXV*MAXV,INF);//cost���鲻�س�ʼ�� 
 	for(int i=0;i<m;i++)
 	{
 		cin>>u>>v;
 		cin>>G[u][v];
		cin>>cost[u][v];
		G[v][u]=G[u][v];
		cost[v][u]=cost[u][v];//����ͼ
	 }
	 Dijkstra(st);
	 DFS(ed);//��ӡ·��,ע���������յ���д�ӡ 
	 cout<<d[ed]<<' '<<c[ed]<<endl;
	 return 0; 
 }
