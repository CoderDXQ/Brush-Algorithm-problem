#include<bits/stdc++.h>
#define R register int
using namespace std;
const int INF=2147483647;
int k,n,m,cnt,sum,ai,bi,ci,head[5005],vis[5005]={0};
int dis[5005];
 //cnt是最小生成树中已经包含的点的个数 
 //dis[]存的是到某点的一条边的已知最小权值 
 struct Edge{
 	int v,w,next;
 }e[400005];
 void add(int u,int v,int w)
 {//前向星 
 	e[++k].v=v;
 	e[k].w=w;
 	e[k].next=head[u];
 	head[u]=k;
 }//其他程序中，k通常写为cnt，是边的编号 
 typedef pair<int,int>pii;//定义别名，也可以用结构体代替pair 
 priority_queue<pii,vector<pii>,greater<pii> >q;//固定格式 
 //设置为小根堆 ，排序的关键字是pii.first 
 void prim()
 {
 	dis[1]=0;//设置根节点为1 
 	q.push(make_pair(0,1));//重要初始化 
 	while(!q.empty()&&cnt<n){//cnt代表最小生成树中点的个数 
 		int d=q.top().first,u=q.top().second;
 		//弹出权值最小的边 
 		//d是权值，u是边上另一个点 
		q.pop();
		if(vis[u]) continue;//u已经在最小生成树中 
		cnt++;sum+=d;vis[u]=1;
		for(R i=head[u];i!=-1;i=e[i].next) //以点找边的过程 
		{//i!=-1与主程序中对head[]数组的赋值有关
			if(e[i].w<dis[e[i].v])
			    dis[e[i].v]=e[i].w;
			    q.push(make_pair(dis[e[i].v],e[i].v));
		 } 
	 }
 }
 int main()
 {
 	//memset(dis,127,sizeof(dis));
	 //memset只能用来赋值为0，-1，其他数字用fill
	 fill(dis,dis+5005,INF); 
 	//for(int i=0;i<=5005;i++) cout<<i<<' '<<dis[i]<<endl;; 
 	memset(head,-1,sizeof(head));
 	scanf("%d%d",&n,&m);
 	for(R i=1;i<=m;i++){
 		scanf("%d%d%d",&ai,&bi,&ci);
 		add(ai,bi,ci);add(bi,ai,ci);
//无向图  Kruskal中无此步骤，因为是直接添边 ，Prim中以点找边就要这么处理 
	 }
	 prim();
	 if(cnt==n) printf("%d",sum);
	 else printf("orz");
	 return 0;
 }
