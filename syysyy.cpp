#include<bits/stdc++.h>
using namespace std;
#define map mapp
bool map[51][51]; //���ͼ ,����Ƿ�Խ�� 
int vis[51][51];  //����ʹ������Ž� 
struct yyy{int x,y,dir,st;}top;//��������е�Ԫ�� 
int ffx;//��ͷ����β
int ans[5001]={-1},tot,minl=0x7fffff; //��Ҫ��ʼ�� 
int fx[5][2]={{0,0},{0,1},{0,-1},{1,0},{-1,0}}; //������ 
int main(){//����+Ԥ�����ͼ 
    int n,m;
    memset(map,0,sizeof(map));
    memset(vis,1,sizeof(vis));//memset������ֵ�ļ��� 
    cin>>n>>m;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++){
       	bool a;
       	cin>>a;
       	if(a){//����ת���ɵ� 
       		map[i][j]=1;map[i-1][j-1]=1;map[i][j-1]=1;map[i-1][j]=1;
		   }
	   }
	for(int i=1;i<=n;i++){map[n][i]=1;map[i][m]=1;}//�߽紦��,ע�����n��m������������ 
	int sx,sy,ex,ey;
	char sfx;
	cin>>sx>>sy>>ex>>ey>>sfx;
	//Ԥ������������Ҫ�Ƿ���
	queue<yyy>qq; 
	if(sfx=='E')ffx=1;
	if(sfx=='W')ffx=2;
	if(sfx=='S')ffx=3;
	if(sfx=='N')ffx=4;//�ϱ����������Ҷ� 
	//bfs
	queue<yyy> Q;
	Q.push((yyy){sx,sy,ffx,0});
	while(!Q.empty()){
		top=Q.front();Q.pop();
		if(top.x==ex&&top.y==ey){ans[++tot]=top.st;}//�����Ż� 
		for(int i=1;i<=4;i++){//��������
		    int step=top.st;
			if(i!=top.dir){//ת��
			    step=top.st+1;//תһ�� 
				if((i==1&&top.dir==2)||(i==2&&top.dir==1)||(i==3&&top.dir==4)||(i==4&&top.dir==3))
				     step=top.st+2;//ת���� 
			} 
	       for(int j=1;j<=3;j++)//ö�ٲ���
	       {
		        int xx,yy;
		        xx=top.x+j*fx[i][0];yy=top.y+j*fx[i][1];//ע�����m��n������������ 
		       if(xx>n||xx<1||yy>m||yy<1||map[xx][yy]) break;
			//��֦��ͬ���������ϰ�����Խ��͵û����� 
				if(vis[xx][yy]>step){
	//if(xx<n&&xx>=1&&yy<m&&yy>=1&&map[xx][yy]==0&&vis[xx][yy]>step)
	//��������д�Ǵ���ģ�������ĳ������һ��ʱ������ĳ���ϰ���
	//�����������Ϳ��������ϰ��������˲��������ϰ�����ʵ�ʲ���	
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
