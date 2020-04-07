//dijkstra+���ȶ���+ǰ����+��������Ż�
#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
const int maxn=10005/*���������ֵ*/,maxm=500005/*���������ֵ*/;
const int inf=2147483647;/*��Ȩֵ�����ֵ*/
int n/*����*/,m/*����*/,cnt=0/*ǰ���Ǵ����*/;
bool tag[maxn];/*����Ƿ��Ѿ���չ��*/
int head[maxm],nxt[maxm]/*ǰ����*/,v[maxm];/*��Ӧ�߿��Ե���ĵ�*/
int w[maxm]/*��Ӧ�ߵ�Ȩֵ*/,dist[maxn]/*��¼Դ�㵽ÿ�������̾��루һ��ʼĬ��inf��*/;
//********************
//�����ȴ�main��������
//********************
int read()//�����Ż�
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return x;
}
void write(int x)//����Ż�
{
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
    return;
}
struct cmp//�ȽϺ��������õ�ŵ�dist��ֵ����
{
    bool operator()(int x,int y)
    {
        return dist[x]>dist[y];//����(>)ΪС���ѣ�ͷ��С������֮��Ȼ��
    }
};
void addline(int x,int y,int z)//ǰ���Ǵ��
{
    v[cnt]=y;
    w[cnt]=z;
    nxt[cnt]=head[x];
    head[x]=cnt++;
    return;
}
void dijkstra(int s)//dijkstra������
{
    priority_queue<int,vector<int>,cmp> Q;//����һ�����ȶ��У�����Ϊint��ʹ��vector���飬ʹ��cmp������ģ�����
    //�����������ֻ�ŵ�ĺ��룬����Ŵ���cmp��������ʵ�ְ����Ȩֵ��С�����б�ŵ�����
    while(!Q.empty()) Q.pop();//Ԥ��stl�����⣬�ȵ��ն��У�һ�㶼�ǿյģ��Է���һ��
    dist[s]=0;//��Դ�������Լ�����Ҫ���ѣ�����Դ��Ϊ0
    Q.push(s);//����ֻ֪����Դ�㣬Ĭ��Դ��Ϊ����չ�ĵ�
    while(!Q.empty())//�����в�Ϊ�գ�Ҳ���ǻ��е�û����չ��ʱ�򣬼���
    {
        int x=Q.top();//��ȡ��С��ı��
        Q.pop();//�����õ�
        if(!tag[x])//��������û�б���չ���Ž��У���ֹ��Ȧ
        {
            tag[x]=true;//���õ���Ϊ����չ
            for(int i=head[x];i!=-1;i=nxt[i])//ǰ�����Ҹõ������ӵı�
            {
            int y=v[i];//Ϊ�˷�����⣬��y��ʾ������ĳ��ı��
            dist[y]=min(dist[y],dist[x]+w[i]);//�����x���������i�����߱�������ȨֵС���滻��
            Q.push(y);//�������ܿ��Խ�����չ���������ѹ������
            }
        }
    }
    return;//һ����ϰ��
}
int main()
{
    int s;//sΪ��ʼ��
    n=read(),m=read(),s=read();//��ȡ
    memset(head,-1,sizeof(head));//��ʼ��
    memset(tag,0,sizeof(tag));//��ʼ����Ĭ��ȫ���㶼û�б���չ��
    for(int i=1;i<=m;i++)//���ߣ�ǰ���ǣ�
    {
        int x,y,z;
        x=read(),y=read(),z=read();
        addline(x,y,z);
    }
    for(int j=1;j<=n;j++)//Ĭ��ÿ�����Ȩֵ��Ϊinf�������ֵ
        dist[j]=inf;
    dijkstra(s);//����ʼ����뺯��
    for(int i=1;i<=n;i++)//���dist����
      write(dist[i]),putchar(' ');
    return 0;//һ����ϰ��
}
