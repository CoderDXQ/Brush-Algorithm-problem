#include <bits/stdc++.h>
using namespace std;
int f[1001],p,res[1001],sav[1001],s;//save[]是暂存计算过程的结果的数组 
void result_1(){//单乘
	memset(sav,0,sizeof(sav));
	for(int i=1;i<=500;i++)//乘法无倒正 
	    for(int j=1;j<=500;j++) sav[i+j-1]+=res[i]*f[j];
	for(int i=1;i<=1000;i++){//处理进位 
		sav[i+1]+=sav[i]/10;
		sav[i]=sav[i]%10;
	}
	//memcpy(res,sav,sizeof(res));//复制函数 
	for(int i=0;i<=1000;i++) res[i]=sav[i]; //存储结果 
 } 
void result_2(){//自乘 
	memset(sav,0,sizeof(sav));
	for(int i=1;i<=500;i++)//循环到500即可，不用到1000 
	    for(int j=1;j<=500;j++) sav[i+j-1]+=f[i]*f[j];//乘法无倒正 
	for(int i=1;i<=1000;i++){
		sav[i+1]+=sav[i]/10;
		sav[i]=sav[i]%10;
	}
	for(int i=0;i<=1000;i++) f[i]=sav[i];//存储结果 
 } 
int main(){
	cin>>p;
	s=(int)(log10(2)*p)+1;//log10是自带函数 
	res[1]=1;//初始化应该是1 
	f[1]=2;//重要初始化 f[]是2的p次方的结果，初始化应该是2而不是1 
	cout<<s<<endl;
	while(p) {//计算2的p次方
		if(p&1) result_1();//单乘 
		p>>=1;
		result_2();//自乘 
	}
	res[1]-=1;//2的p次方-1
	for(int i=500;i>=1;i--){//输出 
	        if(i<500&&i%50==0) cout<<endl;
	    	cout<<res[i];
		 } 
	return 0;
}  
