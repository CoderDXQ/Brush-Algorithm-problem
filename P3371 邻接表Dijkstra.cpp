#include<bits/stdc++.h>
using namespace std;
const int maxv=100010;//������ֵ 
const int INF=2147483647;
struct Node{
	int v,dis;
};
vector<Node>Adj[maxv];//�ñ䳤������ʵ���ڽӱ�
int n,m,s;
int d[maxv];//��㵽��������̾���
bool vis[maxv]={false};//���ĳ���Ƿ񱻷��ʹ�
inline int read()//�����Ż� 
{
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x; 
}
inline void write(int x)//����Ż� 
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void Dijkstra(int s)//ʱ�临�Ӷ�0(n*n),̫�� ���������������������� 
{
	//fill(d,d+maxv,INF);
	memset(d,INF,sizeof(d));
	d[s]=0;//��Ҫ��ʼ�� 
	for(register int i=1;i<=n;i++){
		int u=-1,MIN=INF;
		for(register int j=1;j<=n;j++){//�ҵ�δ���ʵĶ�����d[u]��С�� 
			if(vis[j]==false&&d[j]<MIN){
				u=j;MIN=d[j];//�˴����������ȶ����Ż� 
			}//�������Ǵ�1��ʼ�� **********����Ҫ��һ�� 
		}
		if(u==-1) return;//�Ҳ���С��INF�Ķ��㣬˵��ʣ�µĶ�������s����ͨ 
		vis[u]=true;
		for(register int j=0;j<Adj[u].size();j++){//vector�����±��Ǵ�0��ʼ�� 
			int v=Adj[u][j].v;
			if(vis[v]==false&&d[u]+Adj[u][j].dis<d[v]){
				d[v]=d[u]+Adj[u][j].dis;
			}
		}
	}
 } 
int main()
{
	int x;
	Node xx;
     cin>>n>>m>>s;
	 for(register int i=1;i<=m;i++)
	 {
	 	x=read();xx.v=read();xx.dis=read();
	 	Adj[x].push_back(xx);//Adj[]�����Ԫ�ر�������ΪNode 
	 }	
	 /*for(i=1;i<=3;i++)
 	{
 		for(j=0;j<Adj[i].size();j++)//vector�±��Ǵ�0��ʼ�� 
 		cout<<i<<Adj[i][j].v<<Adj[i][j].dis<<endl;
	 }
 	*/
    Dijkstra(s);
    for(register int i=1;i<=n;i++) write(d[i]),putchar(' ');//��� 
    return 0;
}
