/*#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,ans=0,tmp=0,now=0;
	cin>>n;
	cin>>now;
	ans=now;
	if(now>0) tmp=now;
	for(register int i=2;i<=n;i++)
	{
		cin>>now;
		tmp=tmp+now;//tmp是当前子序列 
		if(tmp>ans) ans=tmp;//ans保存最大的子序列 
		if(tmp<0) tmp=0;//断开 舍弃tmp代表的子序列 
	}
	printf("%d",ans);
 }*/
 
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	int n[200001],p,ans[200001]={0};
 	int sum=-9999999;
 	cin>>p;
 	for(int i=1;i<=p;i++)
 	{
 		cin>>n[i];
 		ans[i]=max(ans[i-1]+n[i],n[i]);//DP
 		//若ans[i-1]+n[i]<0 则ans[i]为 n[i]，表示连续子序列断开 
 		//ans[i]存储当前位置当前子序列的连续和
        sum=max(sum,ans[i]); 		
        // sum存储最大连续子序列和，与每个ans[i]比较后得出结果，
		//sum的赋初值非常重要，必须是一个极小的数
	 }
	 cout<<sum;
	 return 0;
  } 
 
