#include<bits/stdc++.h>
using namespace std;
const long long INF=2147483647;
const int maxn=100005;
const int maxm=500005;
int n,m,s,w,num_edge=0;
int dis[maxn],vis[maxn],head[maxm];
struct Edge
{
	int next,to,dis;
}edge[maxm];
inline int read()//�����Ż� 
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x; 
}
inline void write(int x)//����Ż� 
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void addedge(int from,int to,int dis)
{//ǰ���� 
	edge[++num_edge].next=head[from];
	edge[num_edge].to=to;
	edge[num_edge].dis=dis;
	head[from]=num_edge;
}
inline void spfa()
{//spfa���ľ��ǲ�ͣ����ӳ��� ����ֹ����һ���ڽӱ� 
	queue<int>q;
	for(register int i=1;i<=n;i++){
		dis[i]=INF;
		vis[i]=0;
	}//��ʼ�� 
	q.push(s);dis[s]=0;vis[s]=1;//��Ҫ��ʼ��
	while(!q.empty()){
		int u=q.front();
		q.pop();vis[u]=0;//���ӱ�� 
		for(register int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[v]>dis[u]+edge[i].dis)
			{
				dis[v]=dis[u]+edge[i].dis;
				if(vis[v]==0)//δ��� 
				{
					vis[v]=1;//��ӱ�� 
					q.push(v);
			}
		 } 
	 } 
}}
int main()
{
	n=read();m=read();s=read(); 
	for(register int i=1;i<=m;i++){
		int f,g,w;
		f=read();g=read();w=read();
		addedge(f,g,w);}
	spfa();
	for(register int i=1;i<=n;i++)
	    if(s==i) write(0),putchar(' ');
	    else write(dis[i]),putchar(' ');
	return 0;
}
