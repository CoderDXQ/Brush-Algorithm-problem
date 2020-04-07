#include<stdio.h>
#include<string>//string型的输入输出要注意 
#include<iostream>
#include<map>
using namespace std;
int xh;
int fen[5000][4];
map<string,int> mp;
map<string,int> mm;

int chazhao(string str)
{
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
    	if(str==it->first) xh=it->second;
	} 

}
int cha(int ggg)
{
	int s=0;
	
    for(map<string,int>::iterator it=mm.begin();it!=mm.end();it++)
    {
    	if(ggg==it->second) 
		{
		cout<<it->first<<" ";
		for(s=0;s<3;s++)
        {
        	cout<<fen[mp[it->first]][s]<<" ";
		}
		cout<<ggg<<"\n";
		mm.erase(it->first);
		}
	} 
	return 0;

}

int main()
{
	int i,j,k,p,m,n,gp,gm,gf,g,aa,bb,kk;
	bool fs[101]={false};
	char str[20];//一定要定义成字符串数组 
	for(i=0;i<5000;i++)
	{
		for(j=0;j<4;j++)
		    fen[i][j]=-1;
	}
	xh=0;
	
	cin>>p>>m>>n;

	for(i=0;i<p;i++)
	{
		//cin>>str>>gp;
		scanf("%s %d",&str,&gp);
		if(gp>=200)
		{
			mp[str]=xh;
			fen[xh][0]=gp;
			xh++;
		}
	}
	k=xh;
	for(i=0;i<m;i++)
	{
		scanf("%s %d",&str,&gm);
		xh=-1;
		chazhao(str);
		if(xh!=-1) fen[xh][1]=gm;
	}
	for(i=0;i<n;i++)
	{
		scanf("%s %d",&str,&gf);
		xh=-1;
		chazhao(str);
		fen[xh][2]=gf;
		if(fen[xh][1]<=fen[xh][2])
		{
		    fen[xh][3]=fen[xh][2];
		}
		else
		{
		aa=fen[xh][1];bb=fen[xh][2];
		if(fen[xh][1]==-1) aa=0;
        if(fen[xh][2]==-1) bb=0;
		fen[xh][3]=int(0.4*aa+0.6*bb+0.5);
	}
	}
	
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
    {
    	mm[it->first]=fen[it->second][3];//mm中的值是分数 
	}
	
	for(i=0;i<k;i++)
	{
		if(fen[i][3]>=60&&fs[fen[i][3]]==0)fs[fen[i][3]]=1;
	}
	for(i=100;i>=60;i--)
	{
		if(fs[i]==1) cha(i);
	}

}
