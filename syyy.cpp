#include<bits/stdc++.h>
using namespace std;
int n,i,ans[5001][100000]={{1,0},{1,1},{1,2}};//对前三行初始化，每行第0列是长度，f0=0,f1=1;f2=2; 
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
			x=ans[i][j]/10;//x是进位 
			ans[i][j]%=10;//压位：将原来的10进制变为10000进制，使计算时间变为原来的1/3 
        } 
		while(x) 
		{
		    ans[i][++ans[i][0]]=x%10;
			x/=10;
		}
	}
	 while(ans[n][ans[n][0]]==0&&ans[n][0]!=1) ans[n][0]--;//第一位不用处理0的问题 
	for(i=ans[n][0];i;i--) printf("%d",ans[n][i]);//每次输出4位，左侧用0填充 
	return 0;
}
