#include<bits/stdc++.h>
using namespace std;
int n,m,ans[100002],x,y,f[1002][1002];
char s[1002][1002];
void dfs(int l,int r,int z,int lll){//z是走步后的点应该有的值 
	if(r<0||r>=n||l<0||l>=n||f[l][r]!=-1||s[l][r]-'0'!=z) return;
	//f[l][r]=-1（未被搜索过）且符合走步原则且不超界时的操作 
	f[l][r]=lll;ans[lll]++;//下面是四向dfs 
	dfs(l-1,r,!z,lll);dfs(l+1,r,!z,lll);dfs(l,r+1,!z,lll);dfs(l,r-1,!z,lll);
	//lll是这个连通块中第一个被询问的元素 
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    memset(f,-1,sizeof(f));//f数组初始化  
    for(int i=0;i<m;i++){
    	cin>>x>>y;x--;y--;//在s[][]中，行和列的下标都是从零开始的 
    	if(f[x][y]==-1) dfs(x,y,s[x][y]-'0',i);//找到一个新的连通块 
    	else ans[i]=ans[f[x][y]];//f[][]存的是这个连通块中第一个被询问的元素 
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<endl;
	return 0;
}
