#include<bits/stdc++.h>
using namespace std;
int f[200002],d[200002],n,minn,last;
int find(int x){//带权路径并查集模板 
	if(f[x]==x) return x;
	else
	{
		int last=f[x];//记录父节点 
		f[x]=find(f[x]);//更新祖先（开国太祖）节点 
		d[x]+=d[last];//更新路径长 
		return f[x];//不理解可以手推一遍并查集 
	}
}
void check(int a,int b){
	int x=find(a),y=find(b);
	if(x==y) minn=min(minn,d[a]+d[b]+1);
//新加入的一条边的两个端点在并查集中同祖先，则一定成环 
//d[]保存该点到其祖先（开国太祖）的路径长度 
	else{
		f[x]=y;//合并 
		d[a]=d[b]+1;//更新路径长度 
	}
	
}
int main(){
	int i,t;
	cin>>n;
	for(i=1;i<=n;i++) f[i]=i;//并查集初始化
	minn=0x7777777;//重要初始化
	for(i=1;i<=n;i++){
		cin>>t;
		check(i,t);
	 } 
    cout<<minn<<endl;
	return 0;	
}

