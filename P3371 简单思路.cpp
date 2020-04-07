#include<iostream>
using namespace std;
long long dis[10100];
int u[500100],v[500100],w[500100],n,m,s,check;//���Ƕ���һ��check���Ż��� 
const int inf=2147483647;
int main()
{
    cin>>n>>m>>s;//���� 
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];//����� 
    for(int i=1;i<=n;i++)
        dis[i]=inf;//dis�����ʼ�� 
    dis[s]=0;
    for(int k=1;k<=n-1;k++)
    {
        check=0;//check���� 
        for(int i=1;i<=m;i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
            {
                dis[v[i]]=dis[u[i]]+w[i];
                check=1;//���dis��ֵ�ı䣬check��ֵΪ1 
            }   
        }
        if(check==0)
            break;//���û�䣬ֱ������ѭ������Ҫ�˷�ʱ�� 
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";//��� 
    return 0;//��ϰ��
}


#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=j;i<=n;i++) 
using namespace std;
const int N=10010,M=500010;
inline int read(){  //�����Ż�
    int x; char ch; 
    while(ch=getchar(),ch>'9'||ch<'0') ; x=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0';     return x;
}
int head[N],dis[N],n,m,s,x,y,w,cnt;  //head[x]Ϊ��x���ӵĵ�һ���ߣ�dis[i]Ϊ������룬cntΪ������
struct edge{  //�ڽӱ���
    int next,to,w;  //nextΪ��e[i]����һ���� , toΪ��e[i]���յ�
}e[M];
inline void ins(int x, int y, int v) { 
    cnt++; e[cnt]=edge{head[x],y,v} ; head[x]=cnt;
}
queue<int> q;
bool inq[N];  //�Ƿ��ڶ���
int main(){
    n=read() ; m=read() ; s=read();
    rep(i,1,m) {
        x=read() ; y=read() ; w=read();
        ins(x,y,w);}
    rep(i,1,n) dis[i]=2147483647;  //�����������ܻ������⣬��ý��ʵ��ѡ��
    dis[s]=0;    
    q.push(s); dis[s]=0; inq[s]=true;  //Դ�����
    while(!q.empty()) {
        int x=q.front() ; q.pop(); inq[x]=false;
        for(int i=head[x]; i; i=e[i].next){   //�����������������б�
            int v=e[i].to;
            if( dis[v]>dis[x]+e[i].w) {  //�ɳ�
                dis[v]=dis[x]+e[i].w;
                if(!inq[v]) inq[v]=true,q.push(v); //�µ����
            }
        }
    }
    rep(i,1,n) printf("%d ",dis[i]) ;
    return 0;
}
