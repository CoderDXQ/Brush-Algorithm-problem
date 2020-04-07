#include<cstdio>
#include<string>
#include<iostream>//输入输出整个字符串只能用cin cout 
using namespace std;

int main()
{
	int i,k,j;
	string max,min,name,time1,time2,mint,maxt;
	scanf("%d",&k);
	maxt="00:00:00";
	mint="24:60:60";
	for (i=0;i<k;i++)
    {
    	cin>>name>>time1>>time2;
    	
    	if(mint>time1) {
		min=name;mint=time1;	}
        if(maxt<time2) {
		max=name;maxt=time2;}   	
	}
		cout<<min<<' '<<max<<'\n';
}
