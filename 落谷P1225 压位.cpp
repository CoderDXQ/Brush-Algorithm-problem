#include<bits/stdc++.h>
using namespace std;
int n,i,ans[5001][1000]={{1,0},{1,1},{1,2}};//对前三行初始化，每行第0列是长度，f0=0,f1=1;f2=2; 
                                           //ans数组中，每行代表一个数 
int main()
{
	cin>>n;
	for(i=3;i<=n;i++)
	{
		ans[i][0]=ans[i-1][0];//继承上一个数的长度 
		int x=0;
		for(int j=1;j<=ans[i-1][0];j++)
		{//每一行的第0列存储该数的长度 
		    ans[i][j]=ans[i-1][j]+ans[i-2][j]+x;
			x=ans[i][j]/10000;//x是进位 
			ans[i][j]%=10000;//压位：将原来的10进制变为10000进制，使计算时间变为原来的1/3 
        } 
		while(x) 
		{
		    ans[i][++ans[i][0]]=x%10000;
			x/=10000;
		}
	}
	printf("%d",ans[n][ans[n][0]]);//第一位不用处理0的问题 
	for(i=ans[n][0]-1;i;i--) printf("%04d",ans[n][i]);//每次输出4位，左侧用0填充 
	return 0;
}

