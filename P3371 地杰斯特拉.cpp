#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read()//��� 
{
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')w=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*w;
}
struct Edge{
	int v,w,nxt;
}e[500010];
int head[100010],cnt=0;
inline void addedge(int u,int v,int w){
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
//nxt��¼����ͬ����֮ǰһ���ߵ�cntֵ��cntΨһ��ʶһ���� 
	head[u]=cnt;//cnt�൱���ڽӱ���±� 
}
int n,m,s;
int dis[100010];
struct node{
	int u,d;//���� 
	bool operator<(const node&rhs) const{
	//�̶���ʽ �õ�ַ���в��� rhs����ڶ������ұߵģ����� 
	return d>rhs.d;}//�Ӵ�С����ֵ������ȼ��ͣ����ȼ��ߵ�ֵС
	//�Ѷ����ȼ���ߣ������п�ǰ���󣩵����ȼ��� 
};

inline void Dijkstra(){
	for(re int i=1;i<=n;i++) dis[i]=2147483647;//��Ҫ�ĳ�ʼ�� 
	dis[s]=0;//��Ҫ�ĳ�ʼ�� 
	priority_queue<node> Q;//���ȶ��� ��С���ѣ� 
	Q.push((node){s,0});// �����Q��ѹ��node��Ԫ��,��Ԫ����u=s,d=0 
	while(!Q.empty()){
		node fr=Q.top();Q.pop();
		int u=fr.u,d=fr.d;
		if(d!=dis[u]) continue;//����һ�ּ�֦ 
//�����u���·�����Ż�����d(fr.d,������dis[d]�����ڵ�dis[d]ֵ����ͬ)
//������������м��� 
		for(re int i=head[u];i;i=e[i].nxt){ 
	//nxt��¼����ͬ����֮ǰһ���ߵ�cntֵ����һ�����ݵĹ��� 
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;//�ɳ� 
				Q.push((node){v,dis[v]});//��� 
			}
		}
	}
}
int main()
{
	n=read(),m=read(),s=read();
	for(re int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		addedge(x,y,z);//ǰ���� 
	}
	Dijkstra();
	for(re int i=1;i<=n;i++) printf("%d ",dis[i]);
	return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=500005,INF=2147483647;
long long dis[maxn];
int u[maxm],v[maxm],w[maxm],n,m,s,check;
//maxn�ǵ����������maxm�Ǳߵ������� 
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
}
int main()
{
	int s,check;
	int x,y,z;
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
	}
	memset(dis,INF,sizeof(dis);
	//for(int j=1;j<=n;j++)dis[j]=INF;//��Ҫ��ֵ 
	dis[s]=0;
	for(int k=1;k<=n-1;k++)//k-1���� 
	{
		check=0;
		for(int i=1;i<=m;i++)//�������б� 
		{
			if(dis[v[i]]>dis[u[i]]+w[i])
			{
				dis[v[i]]=dis[u[i]]+w[i];
				check=1;
			}
		}
		if(check==0) break;//û�б��ˣ��ߵĸ���С��n-1 
	}
	for(int i=1;i<=n;i++) write(dis[i]),putchar(' ');
	return 0;
}
*/ 
