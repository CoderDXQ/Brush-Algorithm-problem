#include<bits/stdc++.h>
using namespace std;
int n,m,ans[100002],x,y,f[1002][1002];
char s[1002][1002];
void dfs(int l,int r,int z,int lll){//z���߲���ĵ�Ӧ���е�ֵ 
	if(r<0||r>=n||l<0||l>=n||f[l][r]!=-1||s[l][r]-'0'!=z) return;
	//f[l][r]=-1��δ�����������ҷ����߲�ԭ���Ҳ�����ʱ�Ĳ��� 
	f[l][r]=lll;ans[lll]++;//����������dfs 
	dfs(l-1,r,!z,lll);dfs(l+1,r,!z,lll);dfs(l,r+1,!z,lll);dfs(l,r-1,!z,lll);
	//lll�������ͨ���е�һ����ѯ�ʵ�Ԫ�� 
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>s[i];
    memset(f,-1,sizeof(f));//f�����ʼ��  
    for(int i=0;i<m;i++){
    	cin>>x>>y;x--;y--;//��s[][]�У��к��е��±궼�Ǵ��㿪ʼ�� 
    	if(f[x][y]==-1) dfs(x,y,s[x][y]-'0',i);//�ҵ�һ���µ���ͨ�� 
    	else ans[i]=ans[f[x][y]];//f[][]����������ͨ���е�һ����ѯ�ʵ�Ԫ�� 
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<endl;
	return 0;
}
