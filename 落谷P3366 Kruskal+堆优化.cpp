#include<bits/stdc++.h>
using namespace std;
const int maxm=4000005;
const int maxn=5005;
struct Edge{
	int u,v,w;
	bool operator<(const Edge a) const{
		return w>a.w;//优先队列设置为小根堆,优先级高的数字小 
	}
}edge[maxm];
priority_queue<Edge>q;//优先队列 ,堆优化 
int n,m;
int fa[maxn];
inline int read()//读入优化 
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}
inline int gf(int x){return fa[x]==x?fa[x]:fa[x]=gf(fa[x]);}//并查集 
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) fa[i]=i;//并查集初始化
	for(int i=1;i<=m;i++) q.push((Edge){read(),read(),read()});//真骚
	int ans=0,cnt=0;
	while(!q.empty()){ //挨个边来 
		Edge kkk=q.top();q.pop();
		int ance1=gf(kkk.u),ance2=gf(kkk.v);//ancestor祖先
		if(ance1!=ance2) ans+=kkk.w,cnt++,fa[ance1]=ance2;
		if(cnt==n-1) break; //最小生成树最多有n-1条边 
	} 
	if(cnt<n-1) cout<<"orz"<<endl;
	cout<<ans<<endl;
	return 0;
}
