#include<bits/stdc++.h>
using namespace std;
const int maxn=100005,maxm=500005,inf=2147483647;
//maxn�ǵ����������maxm�Ǳߵ������� 
int n,m,cnt;
bool  tag[maxn];//���ʱ�� 
int head[maxm],nxt[maxm],v[maxm];//v�Ƕ�Ӧ�߿��Ե���ĵ� 
int w[maxm],dist[maxn];//w��Ȩֵ��dist��Դ�㵽ÿ�������̾��� 
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
struct cmp//���ȶ��������һ�̶ֹ���ʽ 
{
	bool operator()(int x,int y)//���ز�����
    {
    	return dist[x]>dist[y];//>��ʾԽ����Խ��С���ѣ���<�Ǵ���� 
		}	
};
void addline(int x,int y,int z)//ǰ���Ǿ����ڽӱ� 
{
	v[cnt]=y;//v����� 
	w[cnt]=z;//w��Ȩֵ 
	nxt[cnt]=head[x];//nxt��ǰ�� 
	head[x]=cnt++;
	return;
}
void dijkstra(int s)
{
	priority_queue<int,vector<int>,cmp>Q;//�̶���ʽ  Q��ŵ�� 
	//Q�д���ǵ�ţ����ǱȽϵ���dist[]��ֵ 
	while(!Q.empty()) Q.pop();//������� ��ʼ�� 
    dist[s]=0;//��¼����
	Q.push(s); //Դ����� 
    while(!Q.empty())
    {
    	int x=Q.top();
    	Q.pop();
    	if(!tag[x])
    	{
    		tag[x]=true;
    		for(int i=head[x];i!=-1;i=nxt[i])
    		{
    			int y=v[i];//y�����Ӧ�߿��Ե���ĵ�
    			dist[y]=min(dist[y],dist[x]+w[i]);
    			Q.push(y);//�����ڲ������ 
			}
		}
    	
	}
}
int main()
{
	int s;
	n=read(),m=read(),s=read();
	memset(head,-1,sizeof(head));//��Ҫ�ĳ�ʼ�� 
	memset(tag,0,sizeof(tag));
	for(int i=1;i<=m;i++)//��ʽǰ���� 
	{
		int x,y,z;
		x=read(),y=read(),z=read();
		addline(x,y,z);
	}
	for(int j=1;j<=n;j++)dist[j]=inf;//��Ҫ��ֵ 
	dijkstra(s);
	for(int i=1;i<=n;i++) write(dist[i]),putchar(' ');
	return 0;
}


























































