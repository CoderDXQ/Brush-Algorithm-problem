#include<bits/stdc++.h>
using namespace std;

string f(int x){
	if(x==1) return "2(0)";
	if(x==2) return "2";
	if(x==3) return "2+2(0)";
    int n=log(x)/log(2);//自动向下取整 
    int t=pow(2,n);
    if(x==t) return "2("+f(n)+")";
    else return "2("+f(n)+")"+"+"+f(x-t);
}

int main()
{ 
    int x;
    cin>>x;
    cout<<f(x)<<endl;
}
