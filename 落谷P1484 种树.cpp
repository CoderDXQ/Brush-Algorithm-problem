#include<bits/stdc++.h>
using namespace std;
#define N 500007
#define int long long//一劳永逸 
struct Place{int val,l,r;}p[N];
struct Node{//往堆中放的元素 
	int val,id;
	bool operator<(Node it) const
	{
		return val<it.val; 
	}//利用重载进行排序，大根堆 
};
int n,m,ans;
bool vis[N];//标记数组 
priority_queue<Node> q;
void Del(int x){
	p[x].l=p[p[x].l].l;p[x].r=p[p[x].r].r;
	p[p[x].l].r=x;p[p[x].r].l=x;//删除节点 
}
signed main(){//int在上面被替换掉了，这里用无符号数代替 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].val;
		p[i].l=i-1;p[i].r=i+1;
		q.push((Node){p[i].val,i});//入队 
	}
	for(int i=1;i<=m;i++){//最多种m棵树 
	    while(vis[q.top().id]) q.pop();//排除优先队列中已经被访问的点
		Node now=q.top();q.pop();
		if(now.val<=0) break;//大根堆中最大的不是正的，那么就没有再种的必要
		ans+=now.val;//计算总收益 
		vis[p[now.id].l]=vis[p[now.id].r]=1;//标记 
		p[now.id].val=p[p[now.id].l].val+p[p[now.id].r].val-p[now.id].val;
		//以上这个是反悔策略的权值公式 
		q.push((Node){p[now.id].val,now.id});
		Del(now.id);//反悔策略的操作 
	}
	cout<<ans;
	return 0;
 } 
