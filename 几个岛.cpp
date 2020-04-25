//https://www.nowcoder.com/questionTerminal/1ecd3d9e09664cde94919b65ea06b47c?f=discussion
//动态求连通量问题 1.DFS、BFS均可 2.并查集

//Solution 1：DFS、BFS

/*
#include<bits/stdc++.h>
using namespace std;

int arr[101][101]={0};
int m,n,k;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int K=1;//岛的编号

void dfs(int x,int y,int flag)
{
    arr[x][y]=flag;//给某个格子更改所属于连通块的编号
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(xx>=0 && xx<m && yy>=0 && yy<n && arr[xx][yy]!=0 && arr[xx][yy]!=flag)
        {
            dfs(xx,yy,flag);
        }
    }
}
int check(int x,int y)
{
    int ret=1;//岛屿个数的变化量 第一次进入点这个格子为岛屿 岛屿数量变化量为1
    int flag=0;
    for(int i=0;i<4;i++)
    {//先对(x,y)周围环境进行检测 看看是否有岛屿存在
        int xx=x+dx[i];
        int yy=y+dy[i];//四向变化
        
        if(xx>=0 && xx<m && yy>=0 && yy<n && arr[xx][yy]!=0)
        {
            if(flag==0)
            {//新的岛屿与旧的岛屿可以连接 arr[xx][yy]!=0
                flag=arr[xx][yy];
                ret--;
            }
            else
            {
                if(arr[xx][yy]!=flag)
                {//与之前的岛屿不连通
                    dfs(xx,yy,flag);
                    ret--;
                }
            }
        }
    }
    //flag=0说明(x,y)周围全是水 这个点是个新岛
    //flag!=0就把(x,y)这个点标记成他周围岛的编号
    arr[x][y]= flag!=0 ? flag:K++;
    return ret;//返回岛屿数量的变化量
}
int main()
{
    cin>>m>>n>>k;

    int cnt=0;//现存岛屿的数量

    for(int i=0;i<k;i++)
    {
        int x,y;
        cin>>x>>y;

        if(x>=0 && x<m && y>=0 && y<n && arr[x][y]==0)
        {//cnt代表连通块的编号 
            cnt+=check(x,y);
        }
        cout<<cnt<<' ';
    }
    return 0;
}

*/

//Solution 2:并查集
#include<bits/stdc++.h>
using namespace std;

int a[101][101];
int flag[10001];
int b[10001];
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int n,m,sum;

//并查集找爹函数的三目运算符写法
//int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int tt(int x)
{
    return flag[x]==x ? x:flag[x]=tt(flag[x]);
}//:后的东西必须有 并查集下的所有元素的爹都是相同的

void check(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int dx=xx[i]+x;
        int dy=yy[i]+y;//四向移动
        if(dx<0 || dx>=n || dy<0 || dy>=m || a[dx][dy]==0 )
            continue;//过滤(x,y)的四周不合法的情况和是海水的情况
        int t=tt(a[dx][dy]);
        int u=tt(a[x][y]);//找爹
        if(t!=u)
        {//合并岛屿
            sum--;//合并岛屿会造成岛屿个数减少 第一次a[x][y]与其他岛屿合并并不会造成数量减少 解决在第138行
            flag[u]=flag[t];//u并到t上
        }
    }
}

int main()
{
    int k,x,y;
    while(cin>>n>>m>>k)
    {
        memset(a,0,sizeof(a));//初始化
        sum=0;//岛屿总数
        for(int i=1;i<=k;i++)
        {
            cin>>x>>y;
            if(x<0 || x>=n || y<0 || y>=m || a[x][y]!=0)
            {//输入不合法或者输入的格子已经变成岛屿
                b[i]=sum;//b数组存的是第几次输入是岛屿的个数
                continue;
            }
            a[x][y]=i;
            flag[i]=i;//这个并查集下只有一个元素 即自己是自己的爹
            check(x,y);
            b[i]=++sum;//a[x][y]周围都是水则需要先加1 再赋值
        }

        for(int i=1;i<=k;i++)
        {
            if(i==k)
                cout<<b[i]<<endl;
            else
                cout<<b[i]<<' ';
        }
    }
    return 0;
}









