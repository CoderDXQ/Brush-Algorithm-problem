#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
 int n,m,fa[MAXN*2],K,D[MAXN*2],vis[2*MAXN],ans[2*MAXN],num;
 //vis[]给点标号，D[]存储被攻占的点 
 struct xcw{
 	int x,y,c;//c代表这条边的序号 
 	bool operator<(const xcw b) const{return c<b.c;}//序号从小到大排序 ,sort()中使用 
 }a[MAXN];
 int read()
 {
 	int ret=0,f=1;char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
 	while(ch>='0'&&ch<='9') ret=ret*10+ch-48,ch=getchar();
 	return ret*f;
 }
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void mer(int x,int y){//合并 
	int fx=get(x),fy=get(y);
	if(fx!=fy) fa[fx]=fy,num--;
}
int main(){
	n=read();m=read();num=n;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) a[i]=(xcw){read(),read(),0};//结构体重载的输入赋值方法 
	K=read();
	for(int i=1;i<=K;i++) vis[D[i]=read()]=K-i+1;//vis[]存储被摧毁的某点修复次序 
	for(int i=1;i<=m;i++) a[i].c=max(vis[a[i].x],vis[a[i].y]);
//当前边的序号是两个点中的较大值，序号越大越早破坏，越晚修复 
	sort(a+1,a+1+m);//排序过程中调用重载符 ，从小到大排序，越小越早修复 
	for(int i=0,j=1;i<=K;i++){//i代表修复次序 ,a[j].c=0代表未被摧毁的点，所以i=0 
		for(;a[j].c==i;j++) mer(a[j].x,a[j].y);
		ans[i]=(num-K)+i;//K-i是被攻占星球的个数 
	} 
	for(int i=K;i>=0;i--) cout<<ans[i]<<endl;
	return 0;
}

