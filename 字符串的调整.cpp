#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	
	int num=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='*'){
			num++;
			str.erase(i,1);
			str.insert(0,"*");
	//		i--;//连续的*情况下，删除第一个后原下标之下仍然是一个*，但是下标已经自增1 
		}
	}
	cout<<str;
} 
