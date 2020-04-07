#include<iostream>
using namespace std;
long long dis[10100];
int u[500100],v[500100],w[500100],n,m,s,check;//我们定义一个check，优化用 
const int inf=2147483647;
int main()
{
    cin>>n>>m>>s;//输入 
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];//读入边 
    for(int i=1;i<=n;i++)
        dis[i]=inf;//dis数组初始化 
    dis[s]=0;
    for(int k=1;k<=n-1;k++)
    {
        check=0;//check归零 
        for(int i=1;i<=m;i++)
        {
            if(dis[v[i]]>dis[u[i]]+w[i])
            {
                dis[v[i]]=dis[u[i]]+w[i];
                check=1;//如果dis数值改变，check赋值为1 
            }   
        }
        if(check==0)
            break;//如果没变，直接跳出循环，不要浪费时间 
    }
    for(int i=1;i<=n;i++)
        cout<<dis[i]<<" ";//输出 
    return 0;//好习惯
}


#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=j;i<=n;i++) 
using namespace std;
const int N=10010,M=500010;
inline int read(){  //读入优化
    int x; char ch; 
    while(ch=getchar(),ch>'9'||ch<'0') ; x=ch-'0';
    while(ch=getchar(),ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0';     return x;
}
int head[N],dis[N],n,m,s,x,y,w,cnt;  //head[x]为点x连接的第一条边，dis[i]为所求距离，cnt为边总数
struct edge{  //邻接表插边
    int next,to,w;  //next为边e[i]的下一条边 , to为边e[i]的终点
}e[M];
inline void ins(int x, int y, int v) { 
    cnt++; e[cnt]=edge{head[x],y,v} ; head[x]=cnt;
}
queue<int> q;
bool inq[N];  //是否在队中
int main(){
    n=read() ; m=read() ; s=read();
    rep(i,1,m) {
        x=read() ; y=read() ; w=read();
        ins(x,y,w);}
    rep(i,1,n) dis[i]=2147483647;  //别的题这里可能会有问题，最好结合实际选择
    dis[s]=0;    
    q.push(s); dis[s]=0; inq[s]=true;  //源点入队
    while(!q.empty()) {
        int x=q.front() ; q.pop(); inq[x]=false;
        for(int i=head[x]; i; i=e[i].next){   //遍历队首连出的所有边
            int v=e[i].to;
            if( dis[v]>dis[x]+e[i].w) {  //松驰
                dis[v]=dis[x]+e[i].w;
                if(!inq[v]) inq[v]=true,q.push(v); //新点入队
            }
        }
    }
    rep(i,1,n) printf("%d ",dis[i]) ;
    return 0;
}
