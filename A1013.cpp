#include<stdio.h>
#include<vector>
#include<cstring>
using namespace std;

const int maxv=1111;
vector<int>G[maxv];
bool vis[maxv];
int n,m,k,currentpoint,block;
void DFS(int v)//定义成无返回值的形式 
{
//	if (v==currentpoint) return;
	vis[v]=true;
	for(int i=0;i<G[v].size();i++)
	{
		if(vis[G[v][i]]==false&&G[v][i]!=currentpoint){//注意格式 
		DFS(G[v][i]);} 
	}	
}

int main()
{
	int u,v;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i=0;i<k;i++)
	{
		
		scanf("%d",&currentpoint);
		memset(vis,false,sizeof(vis));//记住 
		block=0;
		for(int j=1;j<=n;j++)
		{
			if (vis[j]==false&&j!=currentpoint)
			{
				DFS(j);
				block++;
			}
		}
		printf("%d\n",block-1);
	}

	return 0;
}
