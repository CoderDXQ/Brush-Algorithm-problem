#include<bits/stdc++.h>
using namespace std;

int main(){
	double m;
	int n;
	vector<double> res;
	
	cin>>m>>n;//m元分n个红包 
	
	srand(time(NULL));//设置随机生成种子，否则每次rand生成的随机数列都相同 
	for(int i=1;i<n-1;i++){
		double dt=rand()%10;//0-9之间的随机数 
		double dt1=(double)dt*m/10;//本次分出的红包大小 

		res.push_back(dt1);
		m-=dt1;//剩余的奖金池 
	} 

    double sum=0;	
	res.push_back(m);
	//vector数组的下标也是从0开始 
	for(int i=0;i<n;i++)
	{
	     cout<<res[i]<<endl;
	     sum+=res[i];
	 } 
	 cout<<sum<<endl;
	return 0;
	
	
} 
