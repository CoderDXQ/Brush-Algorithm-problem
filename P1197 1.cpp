#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXI=4e5+4;
int f[MAXI],head[MAXI],h[MAXI],ans[MAXI],En=0;//f为并查集，h为打击点存储的数组，ans为每次打击后的答案 
bool e[MAXI];            //e来判断是否被打击掉 
int find(int x){
    if(x!=f[x]) f[x]=find(f[x]); //并查集基本函数 
    return f[x];
}
struct edge{
    int from;
    int to;                 //定义一个结构体来存储邻接表 
    int next;
}a[MAXI];
void insert(int u,int v){                             //邻接表存储数据 
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
        insert(x,y);insert(y,x);         //双向存储数据
    }
    cin>>k;
    tot=n-k;    //打击k次后所剩下的点 
    for(i=1;i<=k;i++){
        cin>>x;
        e[x]=true;    //被打击掉后就true，并把打击的点存储到h中 
        h[i]=x;
    }
    for(i=0;i<2*m;i++){
        if(e[a[i].from]==false&&e[a[i].to]==false) //如果都没有被打击 
        {
            if(find(a[i].from)!=find(a[i].to))    //且之前没有连通 
            {
                tot--;            //合并这两个点并在总数减去一个 
                f[find(a[i].from)]=f[find(a[i].to)];
            }
        }
    }
    ans[k+1]=tot;  //这时为打击k次之后所剩下的连通块 
    for(int t=k;t>=1;t--)  //从后往前“修复” 
    {
        u=h[t]; 
        tot++;   //因为“修复”这个点所以多了一个点，现在总数加 1 
        e[u]=false;  //false表示这个点没有被打击 
        for(i=head[u];i!=-1;i=a[i].next) //邻接表遍历它所连着的点 
        {
            if(e[a[i].to]==false&&f[find(u)]!=f[find(a[i].to)]) //如果被连通的点没有被打击并且之前没有连通 
            {
                tot--;  //合并 
                f[find(a[i].to)]=f[find(u)];  //注意尽量不要到过来赋值，这样会不断改变father 
            }
        }
        ans[t]=tot; //每“修复”一个点后的有的连通块 
    }
    for(i=1;i<=k+1;++i) cout<<ans[i]<<endl;
    return 0;
}
