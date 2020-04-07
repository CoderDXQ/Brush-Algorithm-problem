#include<bits/stdc++.h>
using namespace std;
int main(){
	string str;
	int num;
	while(cin>>str){
		int sum1=0,jian1=0,jian2=0,num=0;
		for(int i=0;i<str.length();i++){
			if(str[i]=='C') {
				num++;
				sum1+=i;//坐标之和 
			}
		}
		jian1=(0+num-1)*num/2;//C都挪到左边后的下标和 
		jian2=(str.length()-1+str.length()-num)*num/2;//C都挪到右边后的下标和 
		sum1=min(jian2-sum1,sum1-jian1);//下标和之差的最小值 
		cout<<sum1<<endl; 
	}
	return 0;
	
} 
