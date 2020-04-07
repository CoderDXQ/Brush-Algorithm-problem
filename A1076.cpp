#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxv=1010;

struct node{
	int id;
	int layer;
};
vector<node>adj[maxv];//�����ڽӱ�ķ��� 
bool inq[maxv]={false};//�����BFS�������Ƿ������ 


int BFS(int s,int L)
{
	int numForward=0;
	queue<node>q;
	node start;
	start.id=s;
	start.layer=0;
	q.push(start);//������push���䳤������push_back 
	inq[start.id]=true;
	while(!q.empty())
	{
		node topnode=q.front();
		q.pop();
		int u=topnode.id;
		for(int i=0;i<adj[u].size();i++)
		{
			node next=adj[u][i];
			next.layer=topnode.layer+1;
			if(inq[next.id]==false&&next.layer<=L)
			{
				q.push(next);
				inq[next.id]=true;
				numForward++;
			}
		}
	}
	return numForward;//һ����Ҫ���Ƿ���ֵ 
}
int main()
{
	node user;
	int n,L,numfollow,idfollow;
	scanf("%d%d",&n,&L);//L->���� 
	for(int i=1;i<=n;i++)
	{
		user.id=i;
		scanf("%d",&numfollow);
		for(int j=0;j<numfollow;j++)
		{
			scanf("%d",&idfollow);
			adj[idfollow].push_back(user);
		}//�������� follow�Ǻ���˼ 
	}
	int numquery,s;
	scanf("%d",&numquery);
	for(int i=0;i<numquery;i++)
	{
		memset(inq,false,sizeof(inq));//��ʼ������memset(inq,false,sizeof(inq)); 
		scanf("%d",&s);
		int numForward=BFS(s,L);
		printf("%d\n",numForward);
	}
	return 0;
}
