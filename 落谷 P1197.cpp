#include<bits/stdc++.h>
using namespace std;
const int MAXI=4e5+4;
int f[MAXI],head[MAXI],h[MAXI],ans[MAXI],En=0;
bool e[MAXI];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
   /* if(x!=f[x]) f[x]=find(f[x]);
    return f[x];*/
}
struct edge{
	int from,to,next;//next为前向星而设置 
}a[MAXI];//a[]存边 
void insert(int u,int v){//链式前向星 
	a[En].from=u;
	a[En].to=v;
	a[En].next=head[u];
	head[u]=En;
	En++;
}
int main(){
	int n,m,k,x,y,tot,i,u;
	cin>>n>>m;
	for(i=0;i<n;++i){
		f[i]=i;//并查集初始化 
		head[i]=-1;//前向星初始化 
	}
	for(i=0;i<m;++i)
	{//读入图 
		cin>>x>>y;
		insert(x,y);insert(y,x);//无向图 
	}
	cin>>k;
	tot=n-k;//打击后剩余的点 
	for(i=1;i<=k;i++){
		cin>>x;
		e[x]=true;
		h[i]=x;//存储依次被打击的点 
	}//读入打击点
	//接下来刨除所有被打击的点建立并查集，求连通块个数 
	for(i=0;i<2*m;i++){//边的两点都没被打击 
		if(e[a[i].from]==false&&e[a[i].to]==false)
		{//En是从0开始的 
			if(find(a[i].from)!=find(a[i].to))//不在同一并查集即不连通
			{
				tot--;
				f[find(a[i].from)]=find(a[i].to);//开国太祖的爹是自己 
			 } 
		}
	} 
	ans[k+1]=tot;//k次打击后剩下的连通块的数目，接下来逐渐修复 
	for(int t=k;t>=1;t--){
	    u=h[t];
	    tot++;
	    e[u]=false;//恢复该点 
	    for(i=head[u];i!=-1;i=a[i].next)//前向星遍历 
	    {
	    	if(e[a[i].to]==false&&find(u)!=find(a[i].to))
	    	{//u的某条边的对点未被打击且两点不在同一并查集 
	    		tot--;
	    		f[find(a[i].to)]=find(u);//合并 
			}
		 } 
		 ans[t]=tot;
	}
	for(i=1;i<=k+1;++i) cout<<ans[i]<<endl;
	return 0;
} 
