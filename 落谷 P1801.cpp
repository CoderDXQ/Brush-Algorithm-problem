#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	int n,m,r=1,q;//��Ҫ��ֵ 
	priority_queue<int>A;//Ĭ�ϴ󶥶� 
	priority_queue<int,vector<int>,greater<int> >B;//С���� 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		cin>>q;
		for(int j=r;j<=q;j++){//��֤�������й���q���� 
			A.push(a[j]);
			if(A.size()==i) B.push(A.top());A.pop();//֤A�Ĵ�СΪi-1
		}
		r=q+1;//���� 
		cout<<B.top()<<endl;
		A.push(B.top());B.pop();
//��һ��ѭ��i����1��Ҫ��֤A�Ĵ�СΪi-1���ܱ�֤B�ĶѶ��ǵ�iС���� 
	}
}
