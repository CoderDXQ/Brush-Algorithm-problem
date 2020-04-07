#include<bits/stdc++.h>
using namespace std;
int f[1000005],h[1000005],n;
char s[2][1005];//滚动数组
int find(int x) {return f[x]==x?x:f[x]=find(f[x]);}
void unionn(int x,int y){
	int r1=find(x),r2=find(y);
	if(r1!=r2) h[r1]+=h[r2],f[r2]=f[r1];
 } 
int main(){
	int t;
	cin>>n>>t;
	for(int i=0;i<n;i++){
		cin>>s[i&1];//滚动数组 当i是偶数时i&1=0，奇数时i&1=1
		for(int j=0;j<n;j++){
			f[i*n+j]=i*n+j,h[i*n+j]=1;
			if(i!=0&&s[(i-1)&1][j]!=s[i&1][j]) unionn((i-1)*n+j,i*n+j);//检查上下是否连通 
			if(j!=0&&s[i&1][j-1]!=s[i&1][j]) unionn(i*n+j,i*n+j-1);//检查左右是否连通 
		} 
	}
	int i,j;
	while(t--){
		cin>>i>>j;
		cout<<h[find((i-1)*n+j-1)]<<endl;
	} 
	return 0;
}
