#include <bits/stdc++.h>
using namespace std;
struct xy{int x,y;}Top;
int dx[8]={1,1,-1,-1,2,2,-2,-2};//��� 
int dy[8]={-2,2,-2,2,1,-1,1,-1};//һ���а˸����� 
int a[401][401];//�洢���� 
bool b[401][401];//����Ƿ񱻷��ʹ� 
int n,m;
void bfs(int x,int y,int step){
    a[x][y]=step;b[x][y]=false;
	queue<xy> Q;
	Q.push((xy){x,y});//ɧ����
	while(!Q.empty()){//ģ�� 
		Top=Q.front();Q.pop();//������front��ջ��top�����ȶ�����top 
    	for(int i=0;i<8;i++){
	    	    int newx=Top.x+dx[i],newy=Top.y+dy[i];
	    	    if(newx>=1&&newx<=n&&newy>=1&&newy<=m&&b[newx][newy]){
	    	        	Q.push((xy){newx,newy});
	    	        	b[newx][newy]=false;//��� 
	    	        	a[newx][newy]=a[Top.x][Top.y]+1;//���� 
					}
		    }
   }
 } 
int main(){
	memset(b,true,sizeof(b));//��Ҫ��ʼ�� 
	memset(a,-1,sizeof(a));
	int x,y;
	cin>>n>>m>>x>>y;
	bfs(x,y,0);
	for(int i=1;i<=n;i++){//������� 
	    for(int j=1;j<=m;j++)
	        printf("%-5d",a[i][j]);
	    cout<<endl;    
    }
	return 0;
 } 
