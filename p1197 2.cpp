#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAXN 200005
using namespace std;
int n,m,fa[MAXN*2],K,D[MAXN*2],vis[MAXN*2],ans[2*MAXN],num;
//num��ʾ����ͨ��ĸ�����ans[]��ס�� ��vis[]������ ��D[]����ռ�ĵ� 
struct xcw{
    int x,y,c;//x,y��ʾ�����ߵ����˵㣬c��ʾ�����ߵ���� 
    bool operator <(const xcw b)const{return c<b.c;}//����Ŵ�С�������� 
}a[MAXN];
int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
    while(ch>='0'&&ch<='9') ret=ret*10+ch-48,ch=getchar();
    return ret*f;
}
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
void mer(int x,int y){
    int fx=get(x),fy=get(y);
    if(fx!=fy) fa[fx]=fy,num--;//����ͨ��ϲ�������ͨ��num-- 
}
int main(){
    n=read();m=read();num=n;
    for(int i=0;i<n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) a[i]=(xcw){read(),read(),0};
    K=read();
    for(int i=1;i<=K;i++) vis[D[i]=read()]=K-i+1;//�����ţ��Ӵ�С 
    for(int i=1;i<=m;i++) a[i].c=max(vis[a[i].x],vis[a[i].y]);//��ǰ�ߵ�������������������Ǹ� 
    sort(a+1,a+1+m);//���㰴��Ŵ�С���򣬷��㴦���Ż�Ч�� 
    for(int i=0,j=1;i<=K;i++){//ö�ٱ���ռ��������� 
        for(;a[j].c==i;j++) mer(a[j].x,a[j].y);//����ǰ���ȫ���ϲ� 
        ans[i]=num-(K-i);//K-i�ǵ۹���ռ�������������Ϊ��������ģ� 
    }
    for(int i=K;i>=0;i--) printf("%d\n",ans[i]);//������� 
    return 0;
}
