#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct dd
{
	int s;
	float r;
}aa;
int main()
{
	int i,j,k,n,l;
	vector <dd> a;
	float d;
	float ss[2008];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>aa.s;cin>>aa.r;
		a.push_back(aa);
	}
	cin>>n;
	for(i=0;i<2008;i++) ss[i]=0;
	vector <dd> ::iterator it;//stl����������Ҫ��������ָ��ĵ����������� 
	for(i=0;i<n;i++)
	{
		cin>>l;cin>>d;//ע������ֵ�ڳ���ִ�й����еı仯 
		
		for(it=a.begin();it!=a.end();it++)
		{
			k=l+(*it).s;ss[k]=ss[k]+d*(*it).r;
		}
	}
	k=0;
	for(i=0;i<2008;i++)
	{
		if(ss[i]!=0) k++;
	}
	cout<<k;
	for(i=2007;i>=0;i--)
	{
		if(ss[i]!=0) printf(" %d %.1f",i,ss[i]);
	}
	printf("\n");
}
