#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int p=n,c=0;//p代表第一个非原始序列的位置 
	for(int s=1;m>0;s++,p--)
	{//找p的位置 
		c=min(s,m);//m代表一共还需要凑出多少逆序对 c代表本次p左移可以凑出多少逆序对 
		m-=c;//s代表p左移以为最多增加的逆序对个数 
	}
	for(int i=1;i<p;i++){
		cout<<i<<' ';
	}//输出顺序     
	cout<<p+c<<' ';//输出第一个非原始序列位置上的数
//找到P的位置后，这个位置上的数每增加一逆序对就增加一 
	for(int i=n;i>=p;i--){
		if(i!=p+c){
			cout<<i<<' ';
		}
	}
	return 0;
}

