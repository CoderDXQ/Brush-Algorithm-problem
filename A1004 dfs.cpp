#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v[100];

int book[100];
int maxdepth=-1;

void dfs(int index,int depth)
{
	if(v[index].size()==0)
	{
		book[depth]++;
		maxdepth=max(depth,maxdepth);
		return;
	}
	for(int i=0;i<v[index].size();i++)
	    dfs(v[index][i],depth+1);
	
}


int main()
{
	int i,j,k,l,m,n,node,c;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&node,&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&c);
			v[node].push_back(c);
		}
	}
	dfs(1,0);
	printf("%d",book[0]);
	for(i=1;i<=maxdepth;i++)
	    printf(" %d",book[i]);
	return 0;
}
