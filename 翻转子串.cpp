#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	

    s1=s1+s1;
    cout<<s1<<endl;
    cout<<s2<<endl;
    if(s1.find(s2)!=-1) cout<<"yes";
    else cout<<"no";
        //return b;
	
}
