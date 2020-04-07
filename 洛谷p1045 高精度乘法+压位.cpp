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
		    a[i]=(a[i]<<20)+k;//数组每个元素放10位数 
		    k=a[i]/10000000000;
		    a[i]%=10000000000;
		    if(top<50&&k&&i==top) top++;
//上一句要写在for循环里面，当第二次进入时，
//满足条件top+1之后还能再进行一次循环，若放在外面则不能，这样就会出错 
	    }
	    p-=20;
	}
	while(p){
		k=0;
		for(i=1;i<=50&&i<=top;i++){
			a[i]=(a[i]<<1)+k;
//注意位运算的优先级 ：算术运算-> 移位运算->位运算 （逻辑运算） 
		    k=a[i]/10000000000;
		    a[i]%=10000000000;
		if(top<50&&k&&i==top) top++;//进位的充分必要条件
		}
		p--;
	}
	a[1]--;
	for(i=50;i>=1;i--){
		if(i%5==0&&i!=50) cout<<endl;
		k=1000000000;//输出技巧 
	    for(j=1;j<=10;j++){
	        	cout<<(a[i]/k);
	        	a[i]%=k;
	        	k=k/10;
			}
	}
	return 0;
}  
