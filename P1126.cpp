#include<iostream>
#include<cstring>
using namespace std;
bool map[51][51]; //���ͼ ,����Ƿ�Խ�� 
int vis[51][51];  //����ʹ������Ž� 
struct yyy{int x,y,dir,st;}q[5001];//��������е�Ԫ�� 
int h=1,t;//��ͷ����β
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
	q[++t].x=sx,q[t].y=sy,q[t].st=0;
	if(sfx=='E')q[t].dir=1;
	if(sfx=='W')q[t].dir=2;
	if(sfx=='S')q[t].dir=3;
	if(sfx=='N')q[t].dir=4;//�ϱ����������Ҷ� 
	//bfs
	while(h<=t){
		if(q[h].x==ex&&q[h].y==ey){ans[++tot]=q[h].st;}//�����Ż� 
		for(int i=1;i<=4;i++){//��������
		    int step=q[h].st;
			if(i!=q[h].dir){//ת��
			    step=q[h].st+1;//תһ�� 
				if((i==1&&q[h].dir==2)||(i==2&&q[h].dir==1)||(i==3&&q[h].dir==4)||(i==4&&q[h].dir==3))
				     step=q[h].st+2;//ת���� 
			} 
	       for(int j=1;j<=3;j++)//ö�ٲ���
	       {
		        int xx,yy;
		        xx=q[h].x+j*fx[i][0];yy=q[h].y+j*fx[i][1];//ע�����m��n������������ 
		       if(xx>n||xx<1||yy>m||yy<1||map[xx][yy]) break;
			//��֦��ͬ���������ϰ�����Խ��͵û����� 
				if(vis[xx][yy]>step){
	//if(xx<n&&xx>=1&&yy<m&&yy>=1&&map[xx][yy]==0&&vis[xx][yy]>step)
	//��������д�Ǵ���ģ�������ĳ������һ��ʱ������ĳ���ϰ���
	//�����������Ϳ��������ϰ��������˲��������ϰ�����ʵ�ʲ���				
                    q[++t].x=xx;q[t].y=yy;q[t].st=step+1;q[t].dir=i;
					vis[xx][yy]=step;		        	
				} 
		   }
		}
		h++;
	} 
	for(int i=1;i<=tot;i++) if(ans[i]<minl) minl=ans[i];
	if(minl<0x7fffff) cout<<minl;
	else cout<<-1;
    return 0; 
}
