#include<cstdio>
#include<cmath>
int ans=0,n,k,x,a[21],num=0;
bool prime(int q)
{
    int i;
	if(q==2) return true;
	for(i=2;i<=ceil(sqrt(q));i++)
	{
		if(q%i==0) return false;
		}	
	return true;
}
void dfs(int x,int y)
{
	int i,j;
	if(x>=k)//向下递归的结束条件 //">="这个地方比较玄 
	{      //x用于计数所选数字的个数 
		if(prime(num)) ans++;
		return;//返回 
	}
	for(i=y+1;i<=n;i++)
	{
		num+=a[i];
		dfs(x+1,i);//x代表个数 
		num-=a[i];//回溯 此上三句是递归通用结构 
	 } 
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);//此处a[0]不存放数字 
	dfs(0,0);
	printf("%d",ans);
}
