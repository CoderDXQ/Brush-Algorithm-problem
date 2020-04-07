//���Ż�dijkstra
#include<bits/stdc++.h>
using namespace std;
#define maxn 10005
#define maxm 500005
#define INF  1234567890
inline int read()
{
    int x=0,k=1; char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')k=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*k;
}
struct Edge
{
    int u,v,w,next;
}e[maxm];
int head[maxn],cnt,n,m,s,vis[maxn],dis[maxn];
struct node
{
    int w,now;
    inline bool operator <(const node &x)const
    //�������������С��Ԫ�ط��ڶѶ�������ѣ�
    {
        return w>x.w;//����ע�����ҪΪ'>'
    }
};
priority_queue<node>q;
//���ȶ��У���ʵ����һ��ʹ��һ��pair����Ϊ�˷�����������õĽṹ��
inline void add(int u,int v,int w)
{
    e[++cnt].u=u;
    //��仰���ڴ��ⲻ��Ҫ����������֮������⻹�����õ�
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    //�洢�õ����һ����
    head[u]=cnt;
    //����Ŀǰ�õ�����һ���ߣ�������һ���ߣ�
}
//��ʽǰ���Ǽӱ�
void dijkstra()
{
    for(int i=1;i<=n;i++){dis[i]=INF;}
    dis[s]=0;//����ֵ
    q.push((node){0,s});
    while(!q.empty())//��Ϊ�ռ�Ϊ���е㶼����
    {
        node x=q.top();
        q.pop();
        int u=x.now;//��¼�Ѷ���������С�ıߣ������䵯��
        if(vis[u]) continue; //û�б���������Ҫ����
        vis[u]=1;
        for(int i=head[u];i;i=e[i].next;//�����Ѷ���������
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w; //�ɳڲ���
                q.push((node){dis[v],v});//���±������ĵ�������
            }
        }
    }
}
int main()
{
    n=read(),m=read(),s=read();
    for(int i=1,x,y,z;i<=m;i++)
    {
        x=read(),y=read(),z=read();
        add(x,y,z);
    }
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        printf("%d ",dis[i]);
    }
    return 0;
}
