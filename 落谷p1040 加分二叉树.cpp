//在树形（区间）动态规划的运行过程中生成树，用递归输出前序 
#include<bits/stdc++.h>
using namespace std;
int n,v[39],f[47][47],i,j,k,root[49][49];
void print(int l,int r)
{
	if(l>r) return;//防止栈溢出 
	if(l==r) 
	{
	    cout<<l<<' ';
		return;
	}
	cout<<root[l][r]<<' ';
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);//题目规定中序遍历就是123456...n 
 } 
 int main()
 {
 	cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];
	for(i=1;i<=n;i++) 
	{
	    f[i][i]=v[i];
		f[i][i-1]=1;
	}//树形DP权值数组的初始化
	for(i=n;i>=1;i--)//i必须是倒序，保证区间越来越大 
	   for(j=i+1;j<=n;j++)	
	      for(k=i;k<=j;k++){//k在区间中游荡 
	      	if(f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k]){
	      		f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
	      		root[i][j]=k;//建树 
			  }
		  } 
	cout<<f[1][n]<<endl;
	print(1,n);
	return 0;
 }
