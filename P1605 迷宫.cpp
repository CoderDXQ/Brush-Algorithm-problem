#include<bits/stdc++.h>
using namespace std;
int mapp[6][6];//map�����ܿ��е�ĳЩ���������ˣ��ĳ�mapp 
bool temp[6][6];
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};//·����� 
int total=0,fx,fy,sx,sy,T,n,m,l,r;
void walk(int x,int y){
	if(x==fx&&y==fy){
		total++;
		return;
	}
	else{
		for(int i=0;i<=3;i++)//����ʵʵд�ж����� 
			if((mapp[x+dx[i]][y+dy[i]])&&(temp[x+dx[i]][y+dy[i]]==0)){//������û�߹� 
			    temp[x][y]=1;//���߹��ĵط����� 
			    walk(x+dx[i],y+dy[i]);
			    temp[x][y]=0;//���� 
			}
	}
}
int main()
{
	cin>>n>>m>>T;
//	fill(mapp[0],mapp[0]+6*6,0);
//	fill(temp[0],temp[0]+6*6,0);//��ʼ�� 
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=m;j++)
	        mapp[i][j]=1;//1�������� 
	cin>>sx>>sy;cin>>fx>>fy;	
	for(int i=1;i<=T;i++){
        cin>>l>>r;
		mapp[l][r]=0;//1�������ߣ�0��������		
	}
	walk(sx,sy);
	cout<<total;
	return 0;
}
