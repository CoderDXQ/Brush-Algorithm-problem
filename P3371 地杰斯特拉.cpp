#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read()//快读 
{
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*w;
}
struct Edge{
	int v,w,nxt;
}e[500010];
int head[100010],cnt=0;
inline void addedge(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
//nxt记录的是同起点的之前一条边的cnt值，cnt唯一标识一条边 
	head[u]=cnt;//cnt相当于邻接表的下标 
}
int n,m,s;
int dis[100010];
struct node{
	int u,d;//重载 
	bool operator<(const node&rhs) const{
	//固定格式 用地址进行操作 rhs代表第二个（右边的）数据 
	return d>rhs.d;}//从大到小排序即值大的优先级低，优先级高的值小
	//堆顶优先级最高，序列中靠前（左）的优先级低 
};

inline void Dijkstra(){
	for(re int i=1;i<=n;i++) dis[i]=2147483647;//重要的初始化 
	dis[s]=0;//重要的初始化 
	priority_queue<node> Q;//优先队列 （小根堆） 
	Q.push((node){s,0});// 向队列Q中压入node型元素,该元素中u=s,d=0 
	while(!Q.empty()){
		node fr=Q.top();Q.pop();
		int u=fr.u,d=fr.d;
		if(d!=dis[u]) continue;//这是一种剪枝 
//到达该u点的路径被优化过，d(fr.d,曾经的dis[d]与现在的dis[d]值不相同)
//不能再用其进行计算 
		for(re int i=head[u];i;i=e[i].nxt){ 
	//nxt记录的是同起点的之前一条边的cnt值，是一个回溯的过程 
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;//松弛 
				Q.push((node){v,dis[v]});//入队 
			}
		}
	}
}
int main()
{
	n=read(),m=read(),s=read();
	for(re int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		addedge(x,y,z);//前向星 
	}
	Dijkstra();
	for(re int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=500005,INF=2147483647;
long long dis[maxn];
int u[maxm],v[maxm],w[maxm],n,m,s,check;
//maxn是点的最大个数，maxm是边的最大个数 
int read()//读入优化 
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x; 
}
void write(int x)//输出优化 
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main()
{
	int s,check;
	int x,y,z;
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
	}
	memset(dis,INF,sizeof(dis);
	//for(int j=1;j<=n;j++)dis[j]=INF;//重要赋值 
	dis[s]=0;
	for(int k=1;k<=n-1;k++)//k-1条边 
	{
		check=0;
		for(int i=1;i<=m;i++)//遍历所有边 
		{
			if(dis[v[i]]>dis[u[i]]+w[i])
			{
				dis[v[i]]=dis[u[i]]+w[i];
				check=1;
			}
		}
		if(check==0) break;//没有边了，边的个数小于n-1 
	}
	for(int i=1;i<=n;i++) write(dis[i]),putchar(' ');
	return 0;
}
*/ 
