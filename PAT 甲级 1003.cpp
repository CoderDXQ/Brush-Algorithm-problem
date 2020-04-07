#include<bits/stdc++.h>
using namespace std;
const int MAXV=510;
const int INF=1000000000;
int n,m,st,ed,G[MAXV][MAXV],weight[MAXV];//G���ڽӾ���weight�洢ÿ���ڵ��Ȩֵ
int d[MAXV],w[MAXV],num[MAXV];
//d�洢��㵽ĳ������·����w�洢��㵽ĳ�����Ȩֵ��num�洢��㵽ĳ���·������
int vis[MAXV]={false};//���ĳ���Ƿ񱻷��ʹ�
void Dijkstra(int s)//s�Ǵ�������
{
	//��Ҫ��ʼ��
    fill(d,d+MAXV,INF);
    fill(w,w+MAXV,0);
    fill(num,num+MAXV,0);//fill��һά����ĳ�ʼ�����ά����Ĳ�ͬ 
    d[s]=0; num[s]=1;w[s]=weight[s];//��Ҫ��ʼ�� ,ע���Ƕ����s��ֵ�������ǶԶ���0��ֵ 
    for(int i=0;i<n;i++){//ȷ����������ͨͼ�����еĵ�
	    int u=-1,MIN=INF;//��Ҫ��ʼ��
		for(int j=0;j<n;j++){if(vis[j]==false&&d[j]<MIN){u=j;MIN=d[j];}} //Ѱ��·����̵ĵ� 
		 if(u==-1) return;//��ͨͼ�����еĵ㶼��������
		 vis[u]=true;//��Ƿ��� 
		 for(int v=0;v<n;v++){
		 	if(vis[v]==false&&G[u][v]!=INF)//vδ�����ʹ��Ҵ�·���� 
		 	{
		 	    if(d[u]+G[u][v]<d[v]){//ȫ�� 
		 	    	 d[v]=d[u]+G[u][v];//���� 
		 	    	 w[v]=w[u]+weight[v];
		 	    	 num[v]=num[u];
				 }
				 else if(d[u]+G[u][v]==d[v]){ //·���ۼ�
				     if(w[u]+weight[v]>w[v])//ע����">" 
					 {
					 	w[v]=w[u]+weight[v];
					 	num[v]=num[v]+num[u];//ҲҪ�������·�������� 
					  }
					  else//if(w[u]+weight[v]==w[v])���ܵ��ڣ�Ҳ����С�� 
					      num[v]=num[v]+num[u];
				 } 
		     }
		  } 
	}
 }
 int main()
 {
 	cin>>n>>m>>st>>ed;
 	for(int i=0;i<n;i++) cin>>weight[i];
 	int u,v;
 	//���������е��������õ���ʱ��Ҫ���г�ʼ�� 
 	fill(G[0],G[0]+MAXV*MAXV,INF);//INF�����·��ͨ 
 	for(int i=0;i<m;i++)
 	{
 		cin>>u>>v;
 		cin>>G[u][v];
 		G[v][u]=G[u][v];//·������ͼ��ģ�� 
	 }
	 Dijkstra(st);
	 //���
	 cout<<num[ed]<<' '<<w[ed]<<endl;
 	return 0;
 }
