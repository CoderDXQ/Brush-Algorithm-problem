#include<bits/stdc++.h> 
using namespace std;
int n,m;//DFS����Ҫ�������
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};//��� 
int a[401][401];
void dfs(int x,int y,int step)
{
	if(step>200) return;
//������һ�䣬����������ﲻͣ��תȦ ,bfs�б�����鲻������������ 
    a[x][y]=step;
	for(int i=0;i<8;i++)
	{
		int newx=x+dx[i],newy=y+dy[i];//�ж���������д�� 
		if((newx>0&&newx<=n&&newy>0&&newy<=m)&&(a[newx][newy]>step+1||a[newx][newy]==-1))
			dfs(newx,newy,step+1);
	}
}
int main()
{
	int x,y;
    cin>>n>>m>>x>>y;
    memset(a,-1,sizeof(a));
    dfs(x,y,0);	
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=m;j++) printf("%-5d",a[i][j]);
		cout<<endl;
    }
}
