/*
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	bool live[42];
	memset(live,1, sizeof(live));
	//41个人，每次数到3就被杀死 
	int killed=0,k=0,flag=1;
	cout<<"Death Order:\n";
	while(killed<39){
	    while(k<3){
	    	if(live[flag]==1) {
			    k++;
			    if(k==3) {
			    	killed++;
				    live[flag]=0;
				    cout<<flag<<' ';
			    }
			}
			flag++;
			if(flag==42) flag=1;
		}
	    if(k==3) k=0;
	} 
	cout<<'\n';
	cout<<"Survivor Number:";
	for(int i=1;i<=41;i++){
		if(live[i]==1) cout<<i<<' '; 
	} 
}
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int people=41;
	int k=3;
	//从0开始编号，那么剩下的最后一个人的编号一定为0
	//若从1开始编号，那么取余操作会比较麻烦 
	int result=0;
	for(int i=2;i<=41;i++)
	{
		//cout<<result+1<<' ';
		//如果在这里输出序号，那么输出的不是初始序号，而是各步重新标定的序号 
		result=(result+k)%i;
	}
    //只能输出最后一个自杀的人 
	cout<<result+1<<'\n'; 
}

















