//ǰ����Dijkstra
 #include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
struct Edge//ǰ���Ǵ��
{
    int z;//�˱ߵ��ӽڵ�
    int val;//�˱ߵ�Ȩֵ
    int nexty;//��������ĸ��ڵ�һ���ıߵı��
}edge[1000000];
int head[20000];//��ĳ��Ϊ���ڵ����������һ����
int cnt=0;//�߱��
inline void add(int a,int b,int c)//���
{
    cnt++;
    edge[cnt].z=b;
    edge[cnt].val=c;
    edge[cnt].nexty=head[a];
    head[a]=cnt;//����head
}
int main()
{
    bool visit[20000]={0};//�Ƿ���Ϊ�����
    long long dis[20000];//����
    int n,m,s;���Ż�dijkstra
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
    while(!visit[curr])//����������ͼ
    {
        visit[curr]=true;//����Ϊ�����
        for(int i=head[curr];i!=0;i=edge[i].nexty)//��ʽǰ�����ѱ�
        {
            if(!visit[edge[i].z]&&dis[edge[i].z]>dis[curr]+edge[i].val)
            dis[edge[i].z]=dis[curr]+edge[i].val;//���²���
        }
        minn=2147483647;
        for(int i=1;i<=n;i++)
        {
            if(!visit[i]&&minn>dis[i])//ȡ�µ���Сֵ
            {
                minn=dis[i];
                curr=i;
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%lld ",dis[i]);
    return 0;
}
