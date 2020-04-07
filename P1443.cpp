#include <bits/stdc++.h>
using namespace std;
struct xy{int x,y;}Top;
int dx[8]={1,1,-1,-1,2,2,-2,-2};//打表 
int dy[8]={-2,2,-2,2,1,-1,1,-1};//一共有八个方向 
int a[401][401];//存储步数 
bool b[401][401];//标记是否被访问过 
int n,m;
void bfs(int x,int y,int step){
    a[x][y]=step;b[x][y]=false;
	queue<xy> Q;
	Q.push((xy){x,y});//骚操作
	while(!Q.empty()){//模板 
		Top=Q.front();Q.pop();//队列用front，栈用top，优先队列用top 
    	for(int i=0;i<8;i++){
	    	    int newx=Top.x+dx[i],newy=Top.y+dy[i];
	    	    if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&b[newx][newy]){
	    	        	Q.push((xy){newx,newy});
	    	        	b[newx][newy]=false;//标记 
	    	        	a[newx][newy]=a[Top.x][Top.y]+1;//计算 
					}
		    }
   }
 } 
int main(){
	memset(b,true,sizeof(b));//重要初始化 
	memset(a,-1,sizeof(a));
	int x,y;
	cin>>n>>m>>x>>y;
	bfs(x,y,0);
	for(int i=1;i<=n;i++){//输出技巧 
	    for(int j=1;j<=m;j++)
	        printf("%-5d",a[i][j]);
	    cout<<endl;    
    }
	return 0;
 } 
