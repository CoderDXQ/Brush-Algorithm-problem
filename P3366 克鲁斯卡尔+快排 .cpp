//��³˹����+���� 
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,u,v,total;
struct edge{
    int start,to;long long val;
}bian[2000005];
int f[100000];
long long ans;
int find(int x)//���鼯����
{
    if (f[x]==x) return x; else {
        f[x]=find(f[x]);
        return f[x];}   
}
bool cmp(edge a,edge b){return a.val<b.val;}
inline void kruskal()//��С������
{
    for(int i=1;i<=m;i++){
        u=find(bian[i].start);v=find(bian[i].to);
        if(u==v) continue;//�ж��ڲ���ͬһ�����鼯���棬�ھ���һ��ѭ��
            ans+=bian[i].val;//���ڣ��ͼ���
            f[u]=v;//�����������鼯
            total++;
            if(total==n-1) break;//���γ�����С���������˳���֮������Ҳû���ˣ�
    }
} 
int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) f[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&bian[i].start,&bian[i].to,&bian[i].val);
    }
    sort(bian+1,bian+m+1,cmp);//���ű߳�
    kruskal();
    printf("%d",ans);
    return 0;
}


