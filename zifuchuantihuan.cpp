#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	string str;
	getline(cin,str);
	cout<<str<<endl;
	
	string st1;

	for(int i=0;i<str.length();i++){
		if(str[i]==' ') st1+="%20";
		else st1+=str[i];
	} 
	
	str=st1;
	
	cout<<str<<endl;
	
 } 
