#include<bits/stdc++.h>
#define R register int
using namespace std;
const int INF=2147483647;
int k,n,m,cnt,sum,ai,bi,ci,head[5005],vis[5005]={0};
int dis[5005];
 //cnt����С���������Ѿ������ĵ�ĸ��� 
 //dis[]����ǵ�ĳ���һ���ߵ���֪��СȨֵ 
 struct Edge{
 	int v,w,next;
 }e[400005];
 void add(int u,int v,int w)
 {//ǰ���� 
 	e[++k].v=v;
 	e[k].w=w;
 	e[k].next=head[u];
 	head[u]=k;
 }//���������У�kͨ��дΪcnt���Ǳߵı�� 
 typedef pair<int,int>pii;//���������Ҳ�����ýṹ�����pair 
 priority_queue<pii,vector<pii>,greater<pii> >q;//�̶���ʽ 
 //����ΪС���� ������Ĺؼ�����pii.first 
 void prim()
 {
 	dis[1]=0;//���ø��ڵ�Ϊ1 
 	q.push(make_pair(0,1));//��Ҫ��ʼ�� 
 	while(!q.empty()&&cnt<n){//cnt������С�������е�ĸ��� 
 		int d=q.top().first,u=q.top().second;
 		//����Ȩֵ��С�ı� 
 		//d��Ȩֵ��u�Ǳ�����һ���� 
		q.pop();
		if(vis[u]) continue;//u�Ѿ�����С�������� 
		cnt++;sum+=d;vis[u]=1;
		for(R i=head[u];i!=-1;i=e[i].next) //�Ե��ұߵĹ��� 
		{//i!=-1���������ж�head[]����ĸ�ֵ�й�
			if(e[i].w<dis[e[i].v])
			    dis[e[i].v]=e[i].w;
			    q.push(make_pair(dis[e[i].v],e[i].v));
		 } 
	 }
 }
 int main()
 {
 	//memset(dis,127,sizeof(dis));
	 //memsetֻ��������ֵΪ0��-1������������fill
	 fill(dis,dis+5005,INF); 
 	//for(int i=0;i<=5005;i++) cout<<i<<' '<<dis[i]<<endl;; 
 	memset(head,-1,sizeof(head));
 	scanf("%d%d",&n,&m);
 	for(R i=1;i<=m;i++){
 		scanf("%d%d%d",&ai,&bi,&ci);
 		add(ai,bi,ci);add(bi,ai,ci);
//����ͼ  Kruskal���޴˲��裬��Ϊ��ֱ����� ��Prim���Ե��ұ߾�Ҫ��ô���� 
	 }
	 prim();
	 if(cnt==n) printf("%d",sum);
	 else printf("orz");
	 return 0;
 }
