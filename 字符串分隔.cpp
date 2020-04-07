#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	
	while(cin>>str){
		if(str.empty()) continue;
		int j;
	//	len=str.length();
		j=8-(str.length()%8);
		if(j!=8) for(int i=1;i<=j;i++) str.insert(str.end(),'0');
		for(int i=1;i<=str.length();i++){
			cout<<str[i-1];
			if(i%8==0) cout<<endl;
		}	
	} 
} 
