#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
 int n,m,fa[MAXN*2],K,D[MAXN*2],vis[2*MAXN],ans[2*MAXN],num;
 //vis[]�����ţ�D[]�洢����ռ�ĵ� 
 struct xcw{
 	int x,y,c;//c���������ߵ���� 
 	bool operator<(const xcw b) const{return c<b.c;}//��Ŵ�С�������� ,sort()��ʹ�� 
 }a[MAXN];
 int read()
 {
 	int ret=0,f=1;char ch=getchar();
 	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
 	while(ch>='0'&&ch<='9') ret=ret*10+ch-48,ch=getchar();
 	return ret*f;
 }
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void mer(int x,int y){//�ϲ� 
	int fx=get(x),fy=get(y);
	if(fx!=fy) fa[fx]=fy,num--;
}
int main(){
	n=read();m=read();num=n;
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) a[i]=(xcw){read(),read(),0};//�ṹ�����ص����븳ֵ���� 
	K=read();
	for(int i=1;i<=K;i++) vis[D[i]=read()]=K-i+1;//vis[]�洢���ݻٵ�ĳ���޸����� 
	for(int i=1;i<=m;i++) a[i].c=max(vis[a[i].x],vis[a[i].y]);
//��ǰ�ߵ�������������еĽϴ�ֵ�����Խ��Խ���ƻ���Խ���޸� 
	sort(a+1,a+1+m);//��������е������ط� ����С��������ԽСԽ���޸� 
	for(int i=0,j=1;i<=K;i++){//i�����޸����� ,a[j].c=0����δ���ݻٵĵ㣬����i=0 
		for(;a[j].c==i;j++) mer(a[j].x,a[j].y);
		ans[i]=(num-K)+i;//K-i�Ǳ���ռ����ĸ��� 
	} 
	for(int i=K;i>=0;i--) cout<<ans[i]<<endl;
	return 0;
}

