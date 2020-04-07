#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXI=4e5+4;
int f[MAXI],head[MAXI],h[MAXI],ans[MAXI],En=0;//fΪ���鼯��hΪ�����洢�����飬ansΪÿ�δ����Ĵ� 
bool e[MAXI];            //e���ж��Ƿ񱻴���� 
int find(int x){
    if(x!=f[x]) f[x]=find(f[x]); //���鼯�������� 
    return f[x];
}
struct edge{
    int from;
    int to;                 //����һ���ṹ�����洢�ڽӱ� 
    int next;
}a[MAXI];
void insert(int u,int v){                             //�ڽӱ�洢���� 
    a[En].from=u;
    a[En].next=head[u];    
    a[En].to=v;
    head[u]=En;
    En++;
}
int main(){
    int n,m,k,x,y,tot,i,u;
    cin>>n>>m;
    for(i=0;i<n;++i) {
        f[i]=i;
        head[i]=-1;
    }
    for(i=0;i<m;++i){
        cin>>x>>y;
        insert(x,y);insert(y,x);         //˫��洢����
    }
    cin>>k;
    tot=n-k;    //���k�κ���ʣ�µĵ� 
    for(i=1;i<=k;i++){
        cin>>x;
        e[x]=true;    //����������true�����Ѵ���ĵ�洢��h�� 
        h[i]=x;
    }
    for(i=0;i<2*m;i++){
        if(e[a[i].from]==false&&e[a[i].to]==false) //�����û�б���� 
        {
            if(find(a[i].from)!=find(a[i].to))    //��֮ǰû����ͨ 
            {
                tot--;            //�ϲ��������㲢��������ȥһ�� 
                f[find(a[i].from)]=f[find(a[i].to)];
            }
        }
    }
    ans[k+1]=tot;  //��ʱΪ���k��֮����ʣ�µ���ͨ�� 
    for(int t=k;t>=1;t--)  //�Ӻ���ǰ���޸��� 
    {
        u=h[t]; 
        tot++;   //��Ϊ���޸�����������Զ���һ���㣬���������� 1 
        e[u]=false;  //false��ʾ�����û�б���� 
        for(i=head[u];i!=-1;i=a[i].next) //�ڽӱ�����������ŵĵ� 
        {
            if(e[a[i].to]==false&&f[find(u)]!=f[find(a[i].to)]) //�������ͨ�ĵ�û�б��������֮ǰû����ͨ 
            {
                tot--;  //�ϲ� 
                f[find(a[i].to)]=f[find(u)];  //ע�⾡����Ҫ��������ֵ�������᲻�ϸı�father 
            }
        }
        ans[t]=tot; //ÿ���޸���һ�������е���ͨ�� 
    }
    for(i=1;i<=k+1;++i) cout<<ans[i]<<endl;
    return 0;
}
