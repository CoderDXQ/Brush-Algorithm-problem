#include<bits/stdc++.h>
using namespace std;
set<int>a;
int main()
{
	int i,n,s;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s;
		a.insert(s);//����֮����Զ������ں��Ǻ���� 
	}
	cout<<a.size()<<endl;
/*	while(!a.empty())
	{
		s=*a.begin();//set��ָ����������Ҫȡֵ 
		cout<<s<<' ';// cout<<*a.begin()<<' ';
		a.erase(a.begin());
	}
	*/
	for(set<int>::iterator it=a.begin();it!=a.end();it++)
	{
		cout<<*it<<' ';
	}
}
