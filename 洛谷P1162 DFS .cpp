#include<bits/stdc++.h>
using namespace std;
int a[32][32];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,i,j;
void dfs(int p,int q)
{//将圈外的0染色成2
	if(p<0||q>n+1||q<0||p>n+1||a[p][q]!=0) return;//设置返回条件，越界或该点已经走过 
	a[p][q]=2;//将圈外的0染色成2
	for(int i=0;i<4;i++)//注意for循环的终止条件 
		dfs(p+dx[i],q+dy[i]);
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) cin>>a[i][j]; 
	}
	dfs(0,0);//用dfs遍历所有圈外的0 
//图形外面的一圈是0，这是一个人为设置的外连通圈，可以借助此遍历所有圈外的0，达到染色的目的 
    for(i=1;i<=n;i++){
    	for(j=1;j<=n;j++){
    		if(a[i][j]==0) cout<<'2'<<' ';
			if(a[i][j]==2) cout<<'0'<<' ';
			if (a[i][j]==1)cout<<'1'<<' ';   
		}
		cout<<endl;
	}
	return 0;
}
