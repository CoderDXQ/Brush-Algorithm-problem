#include<bits/stdc++.h>
using namespace std;
int n,m;
struct dunc{
	int a,b,c;
}f[10004];
struct value{
	int num,x,val;
	friend bool operator < (value a,value b){
		return a.val>b.val;
	}
};
priority_queue<value>q;

int main()
{
	value s;
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
	    cin>>f[i].a>>f[i].b>>f[i].c;
	    q.push((value){i,1,f[i].a+f[i].b+f[i].c});
	}
	for(int i=1;i<=m;i++)
	{
		s=q.top();q.pop();
		cout<<s.val<<' ';
		q.push((value){s.num,s.x+1,f[s.num].a*(s.x+1)*(s.x+1)+f[s.num].b*(s.x+1)+f[s.num].c});
	}
	return 0;
}
