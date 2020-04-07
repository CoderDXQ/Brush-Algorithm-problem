#include<bits/stdc++.h>
using namespace std;
int fa[300005];
int n,k,ans;
inline int read(){
	int sum=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') sum=sum*10+ch-48,ch=getchar();
	return sum;
}
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
int unity(int x,int y){
	int r1=find(fa[x]),r2=find(fa[y]);
	fa[r1]=r2;
}
int main()
{
	int x,y,z;
	n=read(),k=read();
	for(int i=1;i<=3*n;i++) fa[i]=i;
	for(int i=1;i<=k;i++){
		z=read(),x=read(),y=read();
		if(x>n||y>n){ans++;continue;}
		if(z==1){
			if(find(x+n)==find(y)||find(x+2*n)==find(y)){ans++;continue;}
			unity(x,y);unity(x+n,y+n);unity(x+n+n,y+n+n);
			}
		else if(z==2){
			if(x==y) {ans++;continue;}
			if(find(x)==find(y)||find(x+2*n)==find(y)){ans++;continue;}
			unity(x,y+2*n);unity(x+n,y);unity(x+2*n,y+n);
		}
		
	}
	cout<<ans<<endl;
	return 0;
}
