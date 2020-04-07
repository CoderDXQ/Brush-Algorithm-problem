//堆优化+Prime+邻接表
#include<bits/stdc++.h>
#define R register int
using namespace std;
int k,n,m,cnt,sum,ai,bi,ci,head[5005],dis[5005],vis[5005];
struct Edge{int v,w,next;}e[400005];
void add(int u,int v,int w){
    e[++k].v=v;
    e[k].w=w;
    e[k].next=head[u];
    head[u]=k;
}
typedef pair <int,int> pii;
priority_queue <pii,vector<pii>,greater<pii> > q;
void prim(){
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty()&&cnt<n) {
        int d=q.top().first,u=q.top().second;
        q.pop();
        if(vis[u]) continue;
        cnt++;
        sum+=d;
        vis[u]=1;
        for(R i=head[u];i!=-1;i=e[i].next)
            if(e[i].w<dis[e[i].v])
                dis[e[i].v]=e[i].w,q.push(make_pair(dis[e[i].v],e[i].v));
    }
}
int main(){
    memset(dis,127,sizeof(dis));memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(R i=1;i<=m;i++){
        scanf("%d%d%d",&ai,&bi,&ci);
        add(ai,bi,ci);add(bi,ai,ci);
    }
    prim();
    if (cnt==n)printf("%d",sum);
    else printf("orz");
} 
