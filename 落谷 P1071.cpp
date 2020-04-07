//22:56
#include<bits/stdc++.h>
using namespace std;
map<char,char>m0,m1;
char miwen[10000],mingwen[10000],target[10000];

int main()
{
	cin>>miwen>>mingwen>>target;//也可以用gets（）；
	//cout<<miwen<<'\n'<<mingwen<<'\n'<<target; 
	for(int i=0;i<strlen(miwen);i++)//字符串就是字符数组
	{
		if((m0.count(miwen[i])&&m0[miwen[i]]!=mingwen[i])||(m1.count(mingwen[i])&&m1[mingwen[i]]!=miwen[i]))
		{
			cout<<"Failed";return 0;
		}
		else
		{
			m0[miwen[i]]=mingwen[i];
			m1[mingwen[i]]=miwen[i];
		}
	}
	char temp='A';
	for(int i=1;i<26;i++)
	{
		if(!m0.count(temp+i))
		{
			cout<<"Failed";return 0;
		}
		}
	for(int i=0;i<strlen(target);i++)
	{
		if(target[i]!=' ') cout<<m0[target[i]];
		}	
	return 0;
 } 
