#include<bits/stdc++.h>
using namespace std;

int trans(string str)
{
	int num=0;
	for(int i=0;i<str.length();i++){
		num=num*10+str[i]-'0';
	}
	
	return num;
}

int main(){
	
	string st;
	while(cin>>st){
		string s1,s2,s3,s4;
		int a1,a2,a3,a4,t1=0,t2;
		
		t2=st.find(".",0);
		s1=st.substr(0,t2);
		a1=trans(s1);
		
		t1=t2+1;
		t2=st.find(".",t1);
		s2=st.substr(t1,t2-t1);
		a2=trans(s2);
		
		t1=t2+1;
		t2=st.find(".",t1);
		s3=st.substr(t1,t2-t1);
		a3=trans(s3);
		
		t1=t2+1;
		t2=st.find(".",t1);
		s4=st.substr(t1,t2-t1);
		a4=trans(s4);
		
		
	    if(a1>=0&&a1<=255&&a2>=0&&a2<=255&&a3>=0&&a3<=255&&a4>=0&&a4<=255) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl; 
		
		
	}
	
} 
