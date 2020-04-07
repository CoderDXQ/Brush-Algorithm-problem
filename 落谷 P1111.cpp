//0:44
#include<bits/stdc++.h>
using namespace std;
const int maxn=1050;
const int maxm=100050;
int fa[maxn];
int n,m;
struct node{
	int x,y,z;
}e[maxm];
int cmp(node a,node b) {return a.z<b.z;}
int find(int x){return fa[x]==x?x:find(fa[x]);};
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) cin>>e[i].x>>e[i].y>>e[i].z;
	sort(e+1,e+1+m,cmp);
	int num=0,tot=0;
	for(int i=1;i<=m;i++)
	{
	    int	u=find(e[i].x),v=find(e[i].y);
	    if(u!=v){
	    	fa[u]=v;
	    	num++;
			tot=max(tot,e[i].z);
		}
	}
	if(num>=n-1) cout<<tot<<endl;
	else cout<<-1<<endl;
	return 0; 
}
