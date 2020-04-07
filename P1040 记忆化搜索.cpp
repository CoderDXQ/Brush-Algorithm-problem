#include<bits/stdc++.h>
using namespace std;
int i,n,v[49],dp[49][49],root[49][49];
int ser(int l,int r){
	if(dp[l][r]>0) return dp[l][r];// dp[l][r]已经是最优子结构 
	//if(l==r) return v[l];//针对叶子节点的情况，仅有加速作用 
	if(r<l) return 1;//针对区间左右端点的情况 
	for(int i=l;i<=r;i++){
		int p=ser(l,i-1)*ser(i+1,r)+dp[i][i];
//逐渐向二叉树的下方递归，求出最优子结构之后再往上计算 
		if(p>dp[l][r]){//记忆 
		    dp[l][r]=p;
		    root[l][r]=i;
	}
	}
	return dp[l][r];
//返回之前未计算出的最优子结构的值（首次计算出结果的最优子结构的值） 
} 
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
	for(i=1;i<=n;i++) dp[i][i]=v[i];
	printf("%d\n",ser(1,n));
	print(1,n);
	return 0;
}
