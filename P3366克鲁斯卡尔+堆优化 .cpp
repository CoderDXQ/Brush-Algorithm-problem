// ��³˹����+���Ż� 
#include <bits/stdc++.h>
using namespace std;
const int maxm=4000005;
const int maxn=5005;
struct Edge{
    int u,v,w;
    bool operator <(const Edge a) const {return w>a.w;}//����������������Ϊ�����ȶ�������
}edge[maxm];
priority_queue<Edge>q;//���ȶ���
int n,m;
int fa[maxn];
inline int read() {//�����Ż�����Ҫ����������ôд�ģ��Լ��ٶ�
    int X=0,w=0;char ch=0;
    while (!isdigit(ch)) {w|=ch=='-';ch=getchar();}
    while (isdigit(ch)) {X=(X<<1)+(X<<3)+(ch^48);ch=getchar();}
    return w?-X:X;
}
inline int gf(int x) {return fa[x]==x?fa[x]:fa[x]=gf(fa[x]);}//·��ѹ��
int main() {
    n=read(),m=read();
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=1;i<=m;i++) q.push((Edge){read(),read(),read()});//ɧ���Ķ���
    int ans=0,cnt=0;
    while (!q.empty()) {
        Edge kkk=q.top(); q.pop();//ֱ��ȡ�����׾�����С�ģ��ǲ��Ǻ����棬�ҽ��Ͳ��ˣ�����ȥ�ʿ���c++�Ĵ����ǡ�
        int ance1=gf(kkk.u),ance2=gf(kkk.v);//����ͨ
        if (ance1!=ance2) ans+=kkk.w,cnt++,fa[ance1]=ance2;
        if (cnt==n-1) break;
    }
    if (cnt<n-1) printf("orz\n");
    printf("%d\n",ans);
    return 0;
}

//�� 
#include <cstdio>
#include <algorithm>
using namespace std;
int f[2000002],n,x,pp,qq,xian,bian,ans,m;
struct node {       //�ṹ�岻��˵
    int u,v,w;
} p[2000002];
bool cmp(node a,node b) {return a.w<b.w;}   //�ȽϺ�����sort��
int find(int x) {
    if(f[x]==0)return x;            //���鼯ģ��
    else return f[x]=find(f[x]);
}
int main() {
    scanf("%d %d",&m,&n);
    for(int i=1; i<=n; i++) 
	scanf("%d %d %d",&pp,&qq,&x),p[xian].u=pp,p[xian].v=qq,p[xian++].w=x;
    sort(p,p+xian,cmp);         //ֱ�ӽ�������
    for(int i=0; i<xian; i++) {
        int u=p[i].u,v=p[i].v,w=p[i].w,t1=find(p[i].u),t2=find(p[i].v);
        if(t1!=t2)ans+=w,f[t1]=t2,bian++;
        //�ж��Ƿ���Ҫ���кϲ�
        if(bian==n-1)break;
    }
    printf("%d",ans);
}
