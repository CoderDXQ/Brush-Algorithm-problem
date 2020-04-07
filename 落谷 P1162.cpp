#include<bits/stdc++.h>
using namespace std;
const int M=31;
#define map mapp//避免因为使用了万能头文件而出现的重名的情况 
bool vis[M][M];
int n,m,a,b,c,map[M][M];
queue <int> q;
void bfs(int x,int y){//固定格式 
	vis[x][y]=1;q.push(x);q.push(y);//首次进入bfs 
	while(!q.empty()){
		int w=q.front();q.pop();
		int e=q.front();q.pop();//下面是四向寻找 
		if(map[w+1][e]==0&&w!=n&&!vis[w+1][e]) vis[w+1][e]=1,q.push(w+1),q.push(e);
		if(map[w-1][e]==0&&w!=1&&!vis[w-1][e]) vis[w-1][e]=1,q.push(w-1),q.push(e);
		if(map[w][e+1]==0&&e!=n&&!vis[w][e+1]) vis[w][e+1]=1,q.push(w),q.push(e+1);
		if(map[w][e-1]==0&&e!=1&&!vis[w][e-1]) vis[w][e-1]=1,q.push(w),q.push(e-1);
	}
}
int main()
{//把圈外的0全部标记为1，在输出时剩下的0就是圈内的 
	cin>>n;
	for(int i=1;i<=n;i++){
	   for(int j=1;j<=n;j++){
	   	cin>>map[i][j];
	   	if(map[i][j]==1) vis[i][j]=1;//标记圈的边界 
	   } }
    for(int i=1;i<=n;i=i+n-1){//i只能是1和n，即用for循环找到左上和右上圈外的0 
	   for(int j=1;j<=n;j++){
	   	  if(vis[i][j])continue;
	   	  bfs(i,j);//横向寻找圈外的0 
	   }}
    for(int i=1;i<=n;i=i+n-1){//i只能是1和n，即用for循环找到左下和右下圈外的0
	   for(int j=1;j<=n;j++){
	   	  if(vis[j][i])continue;
	   	  bfs(j,i); //纵向寻找圈外的0 
	   }}
    for(int i=1;i<=n;i++){
	   for(int j=1;j<=n;j++){if(!vis[i][j]) cout<<'2'<<' ';else cout<<map[i][j]<<' ';}
	   cout<<endl;
	   }
    return 0;
}
