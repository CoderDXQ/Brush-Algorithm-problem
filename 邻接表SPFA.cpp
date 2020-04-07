//�ڽӱ�SPFA
#include<bits/stdc++.h>
const long long inf=2147483647;
const int maxn=10005;
const int maxm=500005;
using namespace std;
int n,m,s,num_edge=0;
int dis[maxn],vis[maxn],head[maxm];
struct Edge
{
  int next,to,dis;
}edge[maxm]; //�ṹ���ʾ��̬�ڽӱ�
void addedge(int from,int to,int dis) //�ڽӱ�ͼ
{ //���������ݽṹ���ϵı�׼���룬�������鿴����
  edge[++num_edge].next=head[from]; //��ʽ�洢��һ������
  edge[num_edge].to=to; //��ǰ�ڵ���
  edge[num_edge].dis=dis; //�����ߵľ���
  head[from]=num_edge; //��¼��һ�εĳ������
}
void spfa()
{
  queue<int> q; //spfa�ö��У���������STL�ı�׼����
  for(int i=1; i<=n; i++) 
  {
    dis[i]=inf; //��Ȩͼ��ʼ��
    vis[i]=0; //��¼��i�Ƿ��ڶ����У�ͬdijkstra�㷨�е�visited����
  }
  q.push(s); dis[s]=0; vis[s]=1; //��һ��������ӣ����б��
  while(!q.empty())
  {
    int u=q.front(); //ȡ������
    q.pop(); vis[u]=0; //���ӱ��
    for(int i=head[u]; i; i=edge[i].next) //�ڽӱ��������������ˣ�Ҳ����vector���棩
    {
      int v=edge[i].to; 
      if(dis[v]>dis[u]+edge[i].dis) //��������·�͸���
      {
        dis[v]=dis[u]+edge[i].dis;
        if(vis[v]==0) //δ��������
        {
          vis[v]=1; //������
          q.push(v);
        }
      }
    }
  }
}
int main()
{
  cin>>n>>m>>s;
  for(int i=1; i<=m; i++)
  {
    int f,g,w;
    cin>>f>>g>>w; 
    addedge(f,g,w); //��ͼ������ͼ��һ�α߾Ϳ�����
  }
  spfa(); //��ʼ��spfa
  for(int i=1; i<=n; i++)
    if(s==i) cout<<0<<" "; //����ǻص��Լ���ֱ�����0
      else cout<<dis[i]<<" "; //�����ӡ��̾���
  return 0;
} //���� 
