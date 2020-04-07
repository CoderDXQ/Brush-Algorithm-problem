#include<bits/stdc++.h>
using namespace std;
const int MAXV=510;
const int INF=1000000000;
int n,m,st,ed,G[MAXV][MAXV],weight[MAXV];//G是邻接矩阵，weight存储每个节点的权值
int d[MAXV],w[MAXV],num[MAXV];
//d存储起点到某点的最短路径，w存储起点到某点的总权值，num存储起点到某点的路径条数
int vis[MAXV]={false};//标记某点是否被访问过
void Dijkstra(int s)//s是传入的起点
{
	//重要初始化
    fill(d,d+MAXV,INF);
    fill(w,w+MAXV,0);
    fill(num,num+MAXV,0);//fill对一维数组的初始化与二维数组的不同 
    d[s]=0; num[s]=1;w[s]=weight[s];//重要初始化 ,注意是对起点s赋值，而不是对顶点0赋值 
    for(int i=0;i<n;i++){//确保遍历过连通图中所有的点
	    int u=-1,MIN=INF;//重要初始化
		for(int j=0;j<n;j++){if(vis[j]==false&&d[j]<MIN){u=j;MIN=d[j];}} //寻找路径最短的点 
		 if(u==-1) return;//连通图中所有的点都便利过了
		 vis[u]=true;//标记访问 
		 for(int v=0;v<n;v++){
		 	if(vis[v]==false&&G[u][v]!=INF)//v未被访问过且此路存在 
		 	{
		 	    if(d[u]+G[u][v]<d[v]){//全换 
		 	    	 d[v]=d[u]+G[u][v];//更新 
		 	    	 w[v]=w[u]+weight[v];
		 	    	 num[v]=num[u];
				 }
				 else if(d[u]+G[u][v]==d[v]){ //路径累加
				     if(w[u]+weight[v]>w[v])//注意是">" 
					 {
					 	w[v]=w[u]+weight[v];
					 	num[v]=num[v]+num[u];//也要计数最短路径的条数 
					  }
					  else//if(w[u]+weight[v]==w[v])可能等于，也可能小于 
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
 	//理论上所有的数组在用到的时候都要进行初始化 
 	fill(G[0],G[0]+MAXV*MAXV,INF);//INF代表此路不通 
 	for(int i=0;i<m;i++)
 	{
 		cin>>u>>v;
 		cin>>G[u][v];
 		G[v][u]=G[u][v];//路是无向图的模型 
	 }
	 Dijkstra(st);
	 //输出
	 cout<<num[ed]<<' '<<w[ed]<<endl;
 	return 0;
 }
