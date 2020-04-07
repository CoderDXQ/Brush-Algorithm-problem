#include<bits/stdc++.h>
using namespace std;
struct NODE
{
	int score;
	int sl;
	int bh;
}; 
int n;
NODE xuan[200005];
NODE win[100005];
NODE lose[100005];
bool cmp(NODE x,NODE y)
{
	if(x.score!=y.score) return x.score>y.score;
	else return x.bh<y.bh;
}
void merge()
{
	int i=1,j=1,k=1;
	while(i<=n&&j<=n)
	{//结构体赋值可以直接来 
	    if(win[i].score>lose[j].score) xuan[k++]=win[i++];	
		if(win[i].score<lose[j].score) xuan[k++]=lose[j++];
		if(win[i].score==lose[j].score&&win[i].bh<lose[j].bh) xuan[k++]=win[i++];
		if(win[i].score==lose[j].score&&win[i].bh>lose[j].bh) xuan[k++]=lose[j++];
	}	
	while(i<=n) {xuan[k++]=win[i++];}
	while(j<=n) {xuan[k++]=lose[j++];}
}
int main()
{
	int k,i,r,q,nn;
	cin>>n>>r>>q;
	nn=n<<1;
	for(i=1;i<=nn;i++) cin>>xuan[i].score;
	for(i=1;i<=nn;i++) {cin>>xuan[i].sl;xuan[i].bh=i;}
	sort(xuan+1,xuan+nn+1,cmp);
	for(k=0;k<r;k++)
	{
	    for(i=1;i<=n;i++)
		{
			if(xuan[i*2-1].sl>xuan[2*i].sl) 
			{
			    win[i]=xuan[i*2-1];lose[i]=xuan[2*i];win[i].score++;
			}
			else
			{
				win[i]=xuan[2*i];lose[i]=xuan[i*2-1];win[i].score++;
			}
		}
		merge();	
	}
	cout<<xuan[q].bh<<endl;
//	for(i=1;i<=nn;i++) cout<<xuan[i].bh<<' '<<xuan[i].score<<' '<<xuan[i].sl<<endl;	
  }  
