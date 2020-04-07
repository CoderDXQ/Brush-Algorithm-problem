#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m;
	string str;
	
	string st,st1,st2,st3;
	
	cin>>str;
	
	cin>>n>>m;
	
	st="";
	st1=str.substr(0,n);
	st2=str.substr(n,m-n+1);
	reverse(st2.begin(),st2.end());
	st3=str.substr(m+1,str.length()-m-1);
	
	
	cout<<st3<<endl;
	
	st=st1+st2+st3;
	
	cout<<st;
	
	
	
	
}
