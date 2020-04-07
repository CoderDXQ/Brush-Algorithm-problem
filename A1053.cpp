#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=110;
struct node{
	int weight;
	vector<int> child;
}Node[maxn];

bool cmp(int a,int b)
{
	return Node[a].weight>Node[b].weight;
	
}
int n,m,s;
int path[maxn];


void DFS(int index,int nu,int sum)
{
	if(sum>s) return;
	if(sum==s)
	{
		if(Node[index].child.size()!=0) return;
		for(int i=0;i<nu;i++)
		{
			printf("%d",Node[path[i]].weight);
			if(i<nu-1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i=0;i<Node[index].child.size();i++)
	{
		int child=Node[index].child[i];
		path[nu]=child;
		DFS(child,nu+1,sum+Node[child].weight);
	}
	
	
}

int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&Node[i].weight);
	}
	int id,k,child;
	for(int i=0;i<m;i++)
	{
	    scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++)
		{
			scanf("%d",&child);
			Node[id].child.push_back(child);
			}
			sort(Node[id].child.begin(),Node[id].child.end(),cmp);	
	}
	path[0]=0;
	DFS(0,1,Node[0].weight);
	return 0;
}
