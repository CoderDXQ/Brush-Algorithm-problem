#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	while(cin>>str){
		int shuzi[10];
		int zimu[26];
		memset(shuzi,0,sizeof(shuzi));
		memset(zimu,0,sizeof(zimu));
		//for(int i=0;i<10;i++) shuzi[i]=0;
	//	for(int i=0;i<26;i++) zimu[i]=0;
		
		for(int i=0;i<str.length();i++)
		{
			if(str[i]>='0'&&str[i]<='9'){
				shuzi[str[i]-'0']++; 
			}
			else{
				zimu[str[i]-'a']++;
			}
		 } 
		
		for(int i=0;i<26;i++){
			while(zimu[i]>0){
				//cout<<zimu[i];
				cout<<char('a'+i);
				zimu[i]--;
			}
		}
		for(int i=0;i<10;i++){
			while(shuzi[i]>0){
				cout<<char('0'+i);
				shuzi[i]--;
			}
		}
		
		cout<<endl;
	}
	
	
} 
