// 克鲁斯卡尔+堆优化 
#include <bits/stdc++.h>
using namespace std;
const int maxm=4000005;
const int maxn=5005;
struct Edge{
    int u,v,w;
    bool operator <(const Edge a) const {return w>a.w;}//重载运算符，这个是为了优先队列排序
}edge[maxm];
priority_queue<Edge>q;//优先队列
int n,m;
int fa[maxn];
inline int read() {//读入优化，不要问我这是怎么写的，自己百度
    int X=0,w=0;char ch=0;
    while (!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while (isdigit(ch)) {X=(X<<1)+(X<<3)+(ch^48);ch=getchar();}
    return w?-X:X;
}
inline int gf(int x) {return fa[x]==x?fa[x]:fa[x]=gf(fa[x]);}//路径压缩
int main() {
    n=read(),m=read();
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++) q.push((Edge){read(),read(),read()});//骚气的读入
    int ans=0,cnt=0;
    while (!q.empty()) {
        Edge kkk=q.top(); q.pop();//直接取出队首就是最小的，是不是很神奇，我解释不了，可以去问开发c++的大佬们。
        int ance1=gf(kkk.u),ance2=gf(kkk.v);//判联通
        if (ance1!=ance2) ans+=kkk.w,cnt++,fa[ance1]=ance2;
        if (cnt==n-1) break;
    }
    if (cnt<n-1) printf("orz\n");
    printf("%d\n",ans);
    return 0;
}

//简化 
#include <cstdio>
#include <algorithm>
using namespace std;
int f[2000002],n,x,pp,qq,xian,bian,ans,m;
struct node {       //结构体不多说
    int u,v,w;
} p[2000002];
bool cmp(node a,node b) {return a.w<b.w;}   //比较函数（sort）
int find(int x) {
    if(f[x]==0)return x;            //并查集模板
    else return f[x]=find(f[x]);
}
int main() {
    scanf("%d %d",&m,&n);
    for(int i=1; i<=n; i++) 
	scanf("%d %d %d",&pp,&qq,&x),p[xian].u=pp,p[xian].v=qq,p[xian++].w=x;
    sort(p,p+xian,cmp);         //直接进行排序
    for(int i=0; i<xian; i++) {
        int u=p[i].u,v=p[i].v,w=p[i].w,t1=find(p[i].u),t2=find(p[i].v);
        if(t1!=t2)ans+=w,f[t1]=t2,bian++;
        //判断是否需要进行合并
        if(bian==n-1)break;
    }
    printf("%d",ans);
}
