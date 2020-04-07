#include<bits/stdc++.h>
using namespace std;
struct peanuts{
	int x,y,time,w;
};peanuts p[1000001];
int main()
{
	int k=1,t,u,ans,m,n,i,j; 
	int a[1010][1010];
	cin>>m>>n>>t;
	for(i=1;i<=m;i++)
       for(j=1;j<=n;j++){
       	cin>>a[i][j];
       	if(a[i][j]>0)
       	{                   
       		p[k].w=a[i][j]; 
       		p[k].x=i;       
       		p[k].y=j;      
       		k++;
		   }
	   }
	for(i=1;i<k;i++)
	   for(j=i+1;j<=k;j++){
	   	    if(p[i].w<p[j].w) swap(p[i],p[j]);
	   }  //选择排序 注意swap的用法 
	for(i=1;i<=k;i++)
	{
		u=p[i].x;//返回路边的耗时 
		if(i==1) p[i].time=p[i].x+1;
		else p[i].time=p[i-1].time+abs(p[i].x-p[i-1].x)+abs(p[i].y-p[i-1].y)+1;
		if (p[i].time+u<=t) {
		ans=ans+p[i].w;}
		else {
		break;}
	}
	cout<<ans;
	return 0;
}
