#include<bits/stdc++.h>
using namespace std;
#define map mapp
bool map[51][51]; //存地图 ,检查是否越界 
int vis[51][51];  //存访问过的最优解 
struct yyy{int x,y,dir,st;}top;//定义队列中的元素 
int ffx;//队头、队尾
int ans[5001]={-1},tot,minl=0x7fffff; //重要初始化 
int fx[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}}; //方向打表 
int main(){//输入+预处理地图 
    int n,m;
    memset(map,0,sizeof(map));
    memset(vis,1,sizeof(vis));//memset赋极大值的技巧 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++){
       	bool a;
       	cin>>a;
       	if(a){//将块转化成点 
       		map[i][j]=1;map[i-1][j-1]=1;map[i][j-1]=1;map[i-1][j]=1;
		   }
	   }
	for(int i=1;i<=n;i++){map[n][i]=1;map[i][m]=1;}//边界处理,注意分清n和m！！！！！！ 
	int sx,sy,ex,ey;
	char sfx;
	cin>>sx>>sy>>ex>>ey>>sfx;
	//预处理搜索（主要是方向）
	queue<yyy>qq; 
	if(sfx=='E')ffx=1;
	if(sfx=='W')ffx=2;
	if(sfx=='S')ffx=3;
	if(sfx=='N')ffx=4;//上北下南左西右东 
	//bfs
	queue<yyy> Q;
	Q.push((yyy){sx,sy,ffx,0});
	while(!Q.empty()){
		top=Q.front();Q.pop();
		if(top.x==ex&&top.y==ey){ans[++tot]=top.st;}//可以优化 
		for(int i=1;i<=4;i++){//四向搜索
		    int step=top.st;
			if(i!=top.dir){//转弯
			    step=top.st+1;//转一次 
				if((i==1&&top.dir==2)||(i==2&&top.dir==1)||(i==3&&top.dir==4)||(i==4&&top.dir==3))
				     step=top.st+2;//转两次 
			} 
	       for(int j=1;j<=3;j++)//枚举步数
	       {
		        int xx,yy;
		        xx=top.x+j*fx[i][0];yy=top.y+j*fx[i][1];//注意分清m和n！！！！！！ 
		       if(xx>n||xx<1||yy>m||yy<1||map[xx][yy]) break;
			//剪枝，同方向上有障碍或者越界就得换方向 
				if(vis[xx][yy]>step){
	//if(xx<n&&xx>=1&&yy<m&&yy>=1&&map[xx][yy]==0&&vis[xx][yy]>step)
	//上面这样写是错误的，比如向某方向走一步时，到达某个障碍，
	//但是走三步就可能跳过障碍，机器人不能跳过障碍，与实际不符	
	               Q.push((yyy){xx,yy,i,step+1});
					vis[xx][yy]=step;		        	
				} 
		   }
		}
	} 
	for(int i=1;i<=tot;i++) if(ans[i]<minl) minl=ans[i];
	if(minl<0x7fffff) cout<<minl;
	else cout<<-1;
    return 0; 
}
