#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n,m,r=1,q;//重要赋值 
	priority_queue<int>A;//默认大顶堆 
	priority_queue<int,vector<int>,greater<int> >B;//小顶堆 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>q;
		for(int j=r;j<=q;j++){//保证两个堆中共有q个数 
			A.push(a[j]);
			if(A.size()==i) B.push(A.top());A.pop();//证A的大小为i-1
		}
		r=q+1;//继续 
		cout<<B.top()<<endl;
		A.push(B.top());B.pop();
//下一次循环i增大1，要保证A的大小为i-1才能保证B的堆顶是第i小的数 
	}
}
