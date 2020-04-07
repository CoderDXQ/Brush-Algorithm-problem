#include<bits/stdc++.h>
using namespace std;
const int maxv=100010;//点的最大值 
const int INF=2147483647;
struct Node{
	int v,dis;
};
vector<Node>Adj[maxv];//用变长数组来实现邻接表
int n,m,s;
int d[maxv];//起点到达各点的最短距离
bool vis[maxv]={false};//标记某点是否被访问过
inline int read()//读入优化 
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x; 
}
inline void write(int x)//输出优化 
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void Dijkstra(int s)//时间复杂度0(n*n),太慢 ！！！！！！！！！！！ 
{
	//fill(d,d+maxv,INF);
	memset(d,INF,sizeof(d));
	d[s]=0;//重要初始化 
	for(register int i=1;i<=n;i++){
		int u=-1,MIN=INF;
		for(register int j=1;j<=n;j++){//找到未访问的顶点中d[u]最小的 
			if(vis[j]==false&&d[j]<MIN){
				u=j;MIN=d[j];//此处可以用优先队列优化 
			}//顶点标号是从1开始的 **********很重要的一点 
		}
		if(u==-1) return;//找不到小于INF的顶点，说明剩下的顶点和起点s不连通 
		vis[u]=true;
		for(register int j=0;j<Adj[u].size();j++){//vector数组下标是从0开始的 
			int v=Adj[u][j].v;
			if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v]){
				d[v]=d[u]+Adj[u][j].dis;
			}
		}
	}
 } 
int main()
{
	int x;
	Node xx;
     cin>>n>>m>>s;
	 for(register int i=1;i<=m;i++)
	 {
	 	x=read();xx.v=read();xx.dis=read();
	 	Adj[x].push_back(xx);//Adj[]数组的元素变量类型为Node 
	 }	
	 /*for(i=1;i<=3;i++)
 	{
 		for(j=0;j<Adj[i].size();j++)//vector下标是从0开始的 
 		cout<<i<<Adj[i][j].v<<Adj[i][j].dis<<endl;
	 }
 	*/
    Dijkstra(s);
    for(register int i=1;i<=n;i++) write(d[i]),putchar(' ');//输出 
    return 0;
}
