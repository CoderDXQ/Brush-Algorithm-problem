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

void DFS(int nowvisit,int &head,int &nummember,int &totalvalue)//yҪ�޸�ԭֵ�������� 
{
	nummember++;
	vis[nowvisit]=true;
	if(weight[nowvisit]>weight[head]){
		head=nowvisit;
	}//����ͷĿ 
	for(int i=0;i<numperson;i++)//�����ֶ��壬ֻ����������Ч  
	{
		if (G[nowvisit][i]>0)//����֮�����·�� 
        {
            totalvalue+=G[nowvisit][i];
			G[nowvisit][i]=G[i][nowvisit]=0;//ɾ������·�� 
        	if(vis[i]==false)
        	{
        		DFS(i,head,nummember,totalvalue);//�õ������ͣ���ͨϵͳջ����ͬ������ 
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
				Gang[intTostring[head]]=nummember;//��headת��Ϊ�ַ���head����ʵ���֣�
			}// ���ַ��� ���Ա����Գ�map 
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
		intTostring[numperson]=str;//mao�Զ������ҿ����õ��������� 
		return numperson++;//����������1 	
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
		int id2=change(str2);//map��� 
		weight[id1]+=w;//��¼���飬������ ������Ѱ��ͷĿ 
		weight[id2]+=w;
		G[id1][id2]+=w;
		G[id2][id1]+=w;//��绰ʱ������ͼ������ת��Ϊ����ͼ 
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
