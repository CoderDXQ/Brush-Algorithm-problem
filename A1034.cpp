#include<iostream>
#include<stdio.h>
#include<string>
#include<map>
using namespace std;
const int maxn=2010;
const int INF=100000000;

map<int,string>intTostring;
map<string,int>stringToint;
map<string,int>Gang;
int G[maxn][maxn]={0};
int weight[maxn]={0};
int n,k,numperson=0;
bool vis[maxn]={false};

void DFS(int nowvisit,int &head,int &nummember,int &totalvalue)//y要修改原值，引用型 
{
	nummember++;
	vis[nowvisit]=true;
	if(weight[nowvisit]>weight[head]){
		head=nowvisit;
	}//更新头目 
	for(int i=0;i<numperson;i++)//现用现定义，只在区段内有效  
	{
		if (G[nowvisit][i]>0)//两点之间存在路径 
        {
            totalvalue+=G[nowvisit][i];
			G[nowvisit][i]=G[i][nowvisit]=0;//删除往返路径 
        	if(vis[i]==false)
        	{
        		DFS(i,head,nummember,totalvalue);//用的引用型，打通系统栈所有同名变量 
			}
		}		
	}
}
void DFSTrave()
{
	for(int i=0;i<numperson;i++)
	{
		if (vis[i]==false)
		{
			int head=i,nummember=0,totalvalue=0;
			DFS(i,head,nummember,totalvalue);
			if(nummember>2&&totalvalue>k)
			{
				Gang[intTostring[head]]=nummember;//将head转化为字符（head的真实名字）
			}// ，字符与 与成员数配对成map 
		}
	 } 
}
int change(string str)
{
	if(stringToint.find(str)!=stringToint.end())
	{
		return stringToint[str];
	}else
	{
		stringToint[str]=numperson;
		intTostring[numperson]=str;//mao自动有序且可以用迭代器控制 
		return numperson++;//先用再自增1 	
	}
}
int main()
{
	int w;
	string str1,str2;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>str1>>str2>>w;
		int id1=change(str1);
		int id2=change(str2);//map配对 
		weight[id1]+=w;//记录数组，简化问题 ，用于寻找头目 
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;//打电话时是有向图，这里转化为无向图 
	}
	DFSTrave();
	cout<<Gang.size()<<endl;
	map<string,int>:: iterator it;
	for(it=Gang.begin();it!=Gang.end();it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
		
	}
	return 0;
}
