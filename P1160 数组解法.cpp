#include<bits/stdc++.h>
using namespace std;
int n,a,b,k,v[100000]={0};
struct student{
	int l,r;
}d[100000];
int main()
{
	cin>>n;
	d[0].r=1;d[1].l=0��//ͷԪ�� 
	for(int i=2;i<=n;i++){
		cin>>a>>b;
		if(b)
		{   d[d[a].r].l=i;
		    d[i].r=d[a].r;
			d[i].l=a;
			d[a].r=i;//һ��Ҫ���ں��� 
		}
	    else{
	    	d[d[a].l].r=i;
	    	d[i].l=d[a].l;
	    	d[a].l=i;
	    	d[i].r=a;//һ��Ҫ���ں���   	
		}
	}
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(v[a]==1) continue;
		v[a]=1;
		d[d[a].l].r=d[a].r;
		d[d[a].r].l=d[a].l;
	}
	for(int i=0;d[i].r;i=d[i].r)//���� 
	{
		cout<<d[i].r<<' ';
	}
	return 0;
}
