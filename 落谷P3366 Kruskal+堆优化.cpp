#include<bits/stdc++.h>
using namespace std;
const int maxm=4000005;
const int maxn=5005;
struct Edge{
	int u,v,w;
	bool operator<(const Edge a) const{
		return w>a.w;//���ȶ�������ΪС����,���ȼ��ߵ�����С 
	}
}edge[maxm];
priority_queue<Edge>q;//���ȶ��� ,���Ż� 
int n,m;
int fa[maxn];
inline int read()//�����Ż� 
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)) {w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return w?-x:x;
}
inline int gf(int x){return fa[x]==x?fa[x]:fa[x]=gf(fa[x]);}//���鼯 
int main()
{
	n=read(),m=read();
	for(int i=1;i<=n;i++) fa[i]=i;//���鼯��ʼ��
	for(int i=1;i<=m;i++) q.push((Edge){read(),read(),read()});//��ɧ
	int ans=0,cnt=0;
	while(!q.empty()){ //�������� 
		Edge kkk=q.top();q.pop();
		int ance1=gf(kkk.u),ance2=gf(kkk.v);//ancestor����
		if(ance1!=ance2) ans+=kkk.w,cnt++,fa[ance1]=ance2;
		if(cnt==n-1) break; //��С�����������n-1���� 
	} 
	if(cnt<n-1) cout<<"orz"<<endl;
	cout<<ans<<endl;
	return 0;
}
