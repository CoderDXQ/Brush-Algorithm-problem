#include<bits/stdc++.h>
using namespace std;
const int M=31;
#define map mapp//������Ϊʹ��������ͷ�ļ������ֵ���������� 
bool vis[M][M];
int n,m,a,b,c,map[M][M];
queue <int> q;
void bfs(int x,int y){//�̶���ʽ 
	vis[x][y]=1;q.push(x);q.push(y);//�״ν���bfs 
	while(!q.empty()){
		int w=q.front();q.pop();
		int e=q.front();q.pop();//����������Ѱ�� 
		if(map[w+1][e]==0&&w!=n&&!vis[w+1][e]) vis[w+1][e]=1,q.push(w+1),q.push(e);
		if(map[w-1][e]==0&&w!=1&&!vis[w-1][e]) vis[w-1][e]=1,q.push(w-1),q.push(e);
		if(map[w][e+1]==0&&e!=n&&!vis[w][e+1]) vis[w][e+1]=1,q.push(w),q.push(e+1);
		if(map[w][e-1]==0&&e!=1&&!vis[w][e-1]) vis[w][e-1]=1,q.push(w),q.push(e-1);
	}
}
int main()
{//��Ȧ���0ȫ�����Ϊ1�������ʱʣ�µ�0����Ȧ�ڵ� 
	cin>>n;
	for(int i=1;i<=n;i++){
	   for(int j=1;j<=n;j++){
	   	cin>>map[i][j];
	   	if(map[i][j]==1) vis[i][j]=1;//���Ȧ�ı߽� 
	   } }
    for(int i=1;i<=n;i=i+n-1){//iֻ����1��n������forѭ���ҵ����Ϻ�����Ȧ���0 
	   for(int j=1;j<=n;j++){
	   	  if(vis[i][j])continue;
	   	  bfs(i,j);//����Ѱ��Ȧ���0 
	   }}
    for(int i=1;i<=n;i=i+n-1){//iֻ����1��n������forѭ���ҵ����º�����Ȧ���0
	   for(int j=1;j<=n;j++){
	   	  if(vis[j][i])continue;
	   	  bfs(j,i); //����Ѱ��Ȧ���0 
	   }}
    for(int i=1;i<=n;i++){
	   for(int j=1;j<=n;j++){if(!vis[i][j]) cout<<'2'<<' ';else cout<<map[i][j]<<' ';}
	   cout<<endl;
	   }
    return 0;
}
