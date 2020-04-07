#include<bits/stdc++.h>
using namespace std;

int main(){
	string x1,x2,xx1,xx2;
	x1="";x2="";
	int k1,k2;
	while(cin>>xx1>>k1>>xx2>>k2){
		for(int i=1;i<=k1;i++){x1+=xx1;}
		for(int i=1;i<=k2;i++){x2+=xx2;}
	//	cout<<x1<<endl;
	//	cout<<x2<<endl; 
		
		if(x1.length()<x2.length()) cout<<"Less"<<endl;
		if(x1.length()>x2.length()) cout<<"Greater"<<endl;
		if(x1.length()==x2.length()){
			if(x1<x2) cout<<"Less"<<endl;
			if(x1==x2) cout<<"Equal"<<endl;
			if(x1>x2) cout<<"Greater"<<endl;
		} 
	}
	return 0;
} 
