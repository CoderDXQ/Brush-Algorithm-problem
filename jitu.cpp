#include<stdio.h>
using namespace std;
int main()
{
	int n,m;//mÍ· n½Å 
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int sheng;
		sheng=n-i*2;
		if(sheng%4==0&&sheng/4==m-i) {
			cout<<i<<' ';
			sheng=sheng/4;
			cout<<sheng<<endl;
		}
		
	}
 } 
