/*#include<bits/stdc++.h>
using namespace std;
string s[111],ans[111];
const int a[8]={0,-1,-1,-1,0,1,1,1},b[8]={1,1,0,-1,-1,-1,0,1};
int t1,t2,kk,k,i,j,n;
bool bb;
int main() {
	cin>>n;
	for(i=1;i<=n;i++) cin>>s[i];
	for(i=1;i<=n;i++)
	    for(j=0;j<n;j++) //ans[i]+='0';string型的初始化方法，不能用a[i][j]='0' 
	        ans[i]+='0';
    for(i=1;i<=n;i++)//行 
        for(j=0;j<=n-1;j++)//列 
    if(s[i][j]=='y'){
    	for(k=0;k<=7;k++){//在八个方向上移动 
    	t1=i;t2=j;bb=1;
    	for(kk=1;kk<=6;kk++){
    		t1+=a[k];t2+=b[k];
    		if(t1<1||t1>n||t2<0||t2>n-1) {bb=0;break;}
    		if(kk==1&&s[t1][t2]!='i') {bb=0;break;}
    		if(kk==2&&s[t1][t2]!='z') {bb=0;break;}
    		if(kk==3&&s[t1][t2]!='h') {bb=0;break;}
    		if(kk==4&&s[t1][t2]!='o') {bb=0;break;}
    		if(kk==5&&s[t1][t2]!='n') {bb=0;break;}
    		if(kk==6&&s[t1][t2]!='g') {bb=0;break;}
		}
		t1=i;t2=j;
	if(bb)//在这个方向重新走一次并存储 
	    for(kk=0;kk<=6;kk++) ans[t1][t2]=s[t1][t2],t1+=a[k],t2+=b[k];//
	}
    }
    for(i=1;i<=n;i++)
        for(j=0;j<n;j++)
           if(ans[i][j]=='0') ans[i][j]='*';
    for(i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
struct node{
	int x,y;
}c[maxn];
char fz[maxn][maxn],stand[]="yizhong";
int vis[maxn][maxn];
int dir[][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,-1},{1,0},{1,1},{0,-1}};
void dfs(int x,int y,node c[],int k,int cur){
	if(cur==7){
		for(int i=0;i<7;i++) vis[c[i].x][c[i].y]=1;//标记 
		}
	else{
		int dx=x+dir[k][0];int dy=y+dir[k][1];
		if(cur==6||fz[dx][dy]==stand[cur+1]){
			c[cur].x=x;c[cur].y=y;
			dfs(dx,dy,c,k,cur+1);
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>fz[i];
	memset(vis,0,sizeof(vis));//初始化 
	for(int i=0;i<n;i++)
	    for(int j=0;j<n;j++)
	    	if(fz[i][j]=='y')
	    	    for(int k=0;k<8;k++){
	    	    	int x=i+dir[k][0];
	    	    	int y=j+dir[k][1];//在某一方向上移动 
	    	    	if(fz[x][y]=='i') dfs(i,j,c,k,0);
				}
    for(int i=0;i<n;i++){//输出 
	    for(int j=0;j<n;j++) 
			if(vis[i][j])cout<<fz[i][j];
				else cout<<'*';
		cout<<endl;
	}
	return 0;
}




























