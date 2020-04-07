#include <bits/stdc++.h>
using namespace std;
long long a[51]={0,1},p,i,j,s,k,top=1; 
int main(){
	cin>>p;
	s=p*log10(2)+1;
	cout<<s<<endl;
	while(p>=20){
		k=0;
		for(i=1;i<=50&&i<=top;i++){
		    a[i]=(a[i]<<20)+k;
		    k=a[i]/10000000000;
		    a[i]%=10000000000;
		    if(top<50&&k&&i==top) top++;
	    }
	    p-=20;
	}
	while(p){
		k=0;
		for(i=1;i<=50&&i<=top;i++){
			a[i]=(a[i]<<1)+k;//??????????注意位运算的优先级？？？？？ 
		    k=a[i]/10000000000;
		    a[i]%=10000000000;
		if(top<50&&k&&i==top) top++;//????????????//
		}
		p--;
	}
	a[1]--;
	for(i=50;i>=1;i--){
		if(i%5==0&&i!=50) cout<<endl;
		k=1000000000;
	    for(j=1;j<=10;j++){
	        	cout<<(a[i]/k);
	        	a[i]%=k;
	        	k=k/10;
			}
	}
	return 0;
}  
