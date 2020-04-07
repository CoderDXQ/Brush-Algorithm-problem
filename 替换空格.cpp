#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	int jishu[128];
	memset(jishu,0,sizeof(jishu));
	for(int i=0;i<=str.length();i++){
		jishu[str[i]]++;
	}
	for(int i=0;i<str.length();i++){
		if(jishu[str[i]]==1) {
			return i;
			//cout<<i<<endl;
		}
	}
	return -1;
} 
