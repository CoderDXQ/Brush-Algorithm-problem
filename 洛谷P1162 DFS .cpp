#include<bits/stdc++.h>
using namespace std;
int a[32][32];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,i,j;
void dfs(int p,int q)
{//��Ȧ���0Ⱦɫ��2
	if(p<0||q>n+1||q<0||p>n+1||a[p][q]!=0) return;//���÷���������Խ���õ��Ѿ��߹� 
	a[p][q]=2;//��Ȧ���0Ⱦɫ��2
	for(int i=0;i<4;i++)//ע��forѭ������ֹ���� 
		dfs(p+dx[i],q+dy[i]);
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++) cin>>a[i][j]; 
	}
	dfs(0,0);//��dfs��������Ȧ���0 
//ͼ�������һȦ��0������һ����Ϊ���õ�����ͨȦ�����Խ����˱�������Ȧ���0���ﵽȾɫ��Ŀ�� 
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
