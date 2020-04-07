/*
#include<bits/stdc++.h>
using namespace std;
int n,m; 
int v[105],f[110][10005];
//f[]存储某个花费的方案数 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=0;i<n;i++) f[i][0]=1;//只买第i+1个菜时的方案 
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {//j代表钱数 
       	   f[i][j]=f[i-1][j];//继承前i-1道菜花费为j的方案数 
		   if(j>=v[i]) f[i][j]+=f[i-1][j-v[i]]; 
//在不同花费下点这道菜 
	   }
	cout<<f[n][m]<<endl;
	return 0;
 } 
#include<bits/stdc++.h>
using namespace std;
int n,m; 
int v[105],f[10005];
//f[]存储某个花费的方案数 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	f[0]=1;//重要初始化  j-v[i]=0时，即只点第i道菜 
		for(int i=1;i<=n;i++)//枚举所有菜品 
	    for(int j=m;j>=v[i];j--)
	    {//在点第i道菜的情况下，花费为j的方案数 
	    	f[j]=f[j]+f[j-v[i]]*1;
		}
	cout<<f[m];
	return 0;
 }  
#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,b[105]; 
int v[105]; 
void dfs(int k,int x)
{//k是已经花的钱，x是第几件物品 
	if(k>m) return;
	if(k==m){
		sum++;
		return;
	}
	for(int i=x+1;i<=n;i++)
	if(b[i]==0)
	{
		b[i]=1;
		dfs(k+v[i],i);//选第i件物品 
		b[i]=0;
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	dfs(0,0);//???????????????
	cout<<sum;
	return 0;
 } */ 
#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,b[105]; 
int v[105]; 
void dfs(int k,int x)
{//k是已经花的钱，x是第几件物品 
	if(k==m){sum++;return;}
	for(int i=x+1;i<=n;i++)
//必须是从x+1开始，否则x+1之前的菜没有被点的会被重复考虑，导致结果变大 
		if (k+v[i]<=m) 
		{
			b[i]=1;
		    dfs(k+v[i],i);
		    b[i]=0;
			}//选第i件物品 
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	dfs(0,0);//???????????????
	cout<<sum;
	return 0;
 } 
