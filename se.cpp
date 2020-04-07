#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=500005,inf=2147483647;
//maxn是点的最大个数，maxm是边的最大个数 
int n,m,cnt;
bool  tag[maxn];//访问标记 
int head[maxm],nxt[maxm],v[maxm];//v是对应边可以到达的点 
int w[maxm],dist[maxn];//w是权值，dist是源点到每个点的最短距离 
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
struct cmp//优先队列排序的一种固定格式 
{
	bool operator()(int x,int y)//重载操作符
    {
    	return dist[x]>dist[y];//>表示越往下越大即小根堆，故<是大根堆 
		}	
};
void addline(int x,int y,int z)//前向星就是邻接表 
{
	v[cnt]=y;//v存后驱 
	w[cnt]=z;//w存权值 
	nxt[cnt]=head[x];//nxt存前驱 
	head[x]=cnt++;
	return;
}
void dijkstra(int s)
{
	priority_queue<int,vector<int>,cmp>Q;//固定格式  Q存放点号 
	//Q中存的是点号，但是比较的是dist[]的值 
	while(!Q.empty()) Q.pop();//队列清空 初始化 
    dist[s]=0;//记录花费
	Q.push(s); //源点入队 
    while(!Q.empty())
    {
    	int x=Q.top();
    	Q.pop();
    	if(!tag[x])
    	{
    		tag[x]=true;
    		for(int i=head[x];i!=-1;i=nxt[i])
    		{
    			int y=v[i];//y代表对应边可以到达的点
    			dist[y]=min(dist[y],dist[x]+w[i]);
    			Q.push(y);//类似于层序遍历 
			}
		}
    	
	}
}
int main()
{
	int s;
	n=read(),m=read(),s=read();
	memset(head,-1,sizeof(head));//重要的初始化 
	memset(tag,0,sizeof(tag));
	for(int i=1;i<=m;i++)//链式前向星 
	{
		int x,y,z;
		x=read(),y=read(),z=read();
		addline(x,y,z);
	}
	for(int j=1;j<=n;j++)dist[j]=inf;//重要赋值 
	dijkstra(s);
	for(int i=1;i<=n;i++) write(dist[i]),putchar(' ');
	return 0;
}


























































