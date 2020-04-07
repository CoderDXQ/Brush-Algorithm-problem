#include<bits/stdc++.h>
using namespace std;
int n,f,i,k,cnt=0,ans=0x3f3f3f3f;//重要初始化 
int fa[200005];
inline int find(int x,int &cnt)//找爹函数改进版 
{//cnt要用地址来操作，因为是在递归中计数用的
    cnt++;//层数更新 
	if(fa[x]==x) return x;
	else return find(fa[x],cnt);
} 
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) fa[i]=i;//并查集的初始化
	for(i=1;i<=n;i++)
	{
		cin>>f;//在本题中，这条路径是i->f 
		cnt=0;//重要的初始化 
		if(find(f,cnt)==i)//存在环路，可能=不止有一个环路 
		{
			ans=min(cnt,ans);//维护最小的环的长度 
			//在使用min或max时，要注意维护变量的初始化 
		}
		else
		  fa[i]=f;
	 } 
	 cout<<ans<<endl;
	 return 0;
}
