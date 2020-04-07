//克鲁斯卡尔+快排 
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,u,v,total;
struct edge{
    int start,to;long long val;
}bian[2000005];
int f[100000];
long long ans;
int find(int x)//并查集部分
{
    if (f[x]==x) return x; else {
        f[x]=find(f[x]);
        return f[x];}   
}
bool cmp(edge a,edge b){return a.val<b.val;}
inline void kruskal()//最小生成树
{
    for(int i=1;i<=m;i++){
        u=find(bian[i].start);v=find(bian[i].to);
        if(u==v) continue;//判断在不在同一个并查集里面，在就下一个循环
            ans+=bian[i].val;//不在，就加上
            f[u]=v;//连接两个并查集
            total++;
            if(total==n-1) break;//当形成了最小生成树后，退出（之后做的也没用了）
    }
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&bian[i].start,&bian[i].to,&bian[i].val);
    }
    sort(bian+1,bian+m+1,cmp);//快排边长
    kruskal();
    printf("%d",ans);
    return 0;
}


