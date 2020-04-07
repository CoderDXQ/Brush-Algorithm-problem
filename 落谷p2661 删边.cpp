#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 200005
int to[N],indegree[N];//记录入度 
bool visit[N];
int n;
void delzero(){
	bool flag=1;
	for(int i=1;i<=n;i++){//仅仅是一轮删除 
		if(indegree[i]==0&&!visit[i]){
//以i为起点的边未被访问过,且i点入度为0，即这是一条废边 
			flag=0;//标志着还有边可以删 
			visit[i]=1;//标记删除的点，在search()中不会被访问 
			indegree[to[i]]--;//删除一条边 
		}
	}
	if(flag) return;//没有废边可以删除了 
	else delzero();//进行下一轮删除 
}
int ans=INF;//重要初始化
void search(int start,int now,int step){
	if(start==now){ans=min(ans,step);return;}//设置返回条件
	visit[now]=1;//标记 
	search(start,to[now],step+1); //利用递归遍历环 
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>to[i];
		indegree[to[i]]++;//计算入度 
	}
	delzero();
	for(int i=1;i<=n;i++){
		if(!visit[i]){//剪枝 
			visit[i]=1;//标记，认为一个连通块中至多有一个环 
			search(i,to[i],1);//遍历所有环 
		}
	}
	cout<<ans<<endl;
	return 0;
}
