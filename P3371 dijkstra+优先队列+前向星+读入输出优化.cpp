//dijkstra+优先队列+前向星+读入输出优化
#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn=10005/*点数的最大值*/,maxm=500005/*边数的最大值*/;
const int inf=2147483647;/*边权值的最大值*/
int n/*点数*/,m/*边数*/,cnt=0/*前向星存边用*/;
bool tag[maxn];/*标记是否已经拓展过*/
int head[maxm],nxt[maxm]/*前向星*/,v[maxm];/*对应边可以到达的点*/
int w[maxm]/*对应边的权值*/,dist[maxn]/*记录源点到每个点的最短距离（一开始默认inf）*/;
//********************
//建议先从main函数看起
//********************
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
    return;
}
struct cmp//比较函数，利用点号的dist数值排序
{
    bool operator()(int x,int y)
    {
        return dist[x]>dist[y];//大于(>)为小根堆（头最小），反之亦然；
    }
};
void addline(int x,int y,int z)//前向星存边
{
    v[cnt]=y;
    w[cnt]=z;
    nxt[cnt]=head[x];
    head[x]=cnt++;
    return;
}
void dijkstra(int s)//dijkstra主程序
{
    priority_queue<int,vector<int>,cmp> Q;//定义一个优先队列，类型为int，使用vector数组，使用cmp（上面的）函数
    //这个队列里面只放点的号码，将点号带入cmp函数即可实现按点的权值大小，进行编号的排序
    while(!Q.empty()) Q.pop();//预防stl有问题，先弹空队列（一般都是空的，以防万一）
    dist[s]=0;//将源点走向自己不需要花费，定义源点为0
    Q.push(s);//现在只知道有源点，默认源点为待拓展的点
    while(!Q.empty())//当队列不为空，也就是还有点没有拓展的时候，继续
    {
        int x=Q.top();//读取最小点的编号
        Q.pop();//弹出该点
        if(!tag[x])//如果这个点没有被拓展过才进行，防止兜圈
        {
            tag[x]=true;//将该点标记为已拓展
            for(int i=head[x];i!=-1;i=nxt[i])//前向星找该点所连接的边
            {
            int y=v[i];//为了方便理解，用y表示所连的某点的编号
            dist[y]=min(dist[y],dist[x]+w[i]);//如果从x点出发经过i这条边比这个点的权值小，替换它
            Q.push(y);//这个点可能可以进行拓展，将这个点压进队列
            }
        }
    }
    return;//一个好习惯
}
int main()
{
    int s;//s为起始点
    n=read(),m=read(),s=read();//读取
    memset(head,-1,sizeof(head));//初始化
    memset(tag,0,sizeof(tag));//初始化，默认全部点都没有被拓展过
    for(int i=1;i<=m;i++)//读边（前向星）
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        addline(x,y,z);
    }
    for(int j=1;j<=n;j++)//默认每个点的权值都为inf，即最大值
        dist[j]=inf;
    dijkstra(s);//将起始点带入函数
    for(int i=1;i<=n;i++)//输出dist数组
      write(dist[i]),putchar(' ');
    return 0;//一个好习惯
}
