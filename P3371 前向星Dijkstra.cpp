//前向星Dijkstra
 #include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
struct Edge//前向星存边
{
    int z;//此边的子节点
    int val;//此边的权值
    int nexty;//与它最近的父节点一样的边的编号
}edge[1000000];
int head[20000];//以某点为父节点引出的最后一条边
int cnt=0;//边编号
inline void add(int a,int b,int c)//存边
{
    cnt++;
    edge[cnt].z=b;
    edge[cnt].val=c;
    edge[cnt].nexty=head[a];
    head[a]=cnt;//更新head
}
int main()
{
    bool visit[20000]={0};//是否作为过起点
    long long dis[20000];//距离
    int n,m,s;堆优化dijkstra
    int a,b,c;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++)dis[i]=2147483647;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    int curr=s;
    dis[s]=0;
    long long minn;
    while(!visit[curr])//即搜完整张图
    {
        visit[curr]=true;//已做为过起点
        for(int i=head[curr];i!=0;i=edge[i].nexty)//链式前向星搜边
        {
            if(!visit[edge[i].z]&&dis[edge[i].z]>dis[curr]+edge[i].val)
            dis[edge[i].z]=dis[curr]+edge[i].val;//更新操作
        }
        minn=2147483647;
        for(int i=1;i<=n;i++)
        {
            if(!visit[i]&&minn>dis[i])//取新的最小值
            {
                minn=dis[i];
                curr=i;
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
    return 0;
}
