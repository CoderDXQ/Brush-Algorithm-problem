#include<stdio.h>
using namespace std;
int n,cnt=1;
void func(int x)
{
	for(int i=1;i<=x/2;i++)
	{
		cnt++;
		func(i);
	}
 } 
 int main()
 {
 	scanf("%d",&n);
 	func(n);
 	printf("%d\n",cnt);
 }//用递归会超时，原因是重复计算，因此可用递推*/
#include<stdio.h>//第一种递推 
using namespace std;
int N,Ans[1005],Sum[1005];
int main()
{
	scanf("%d",&N);
	for(register int i=1;i<=N;i++)//register int使int i在cpu内部寄存器中
	//存储而不是内存，从而大幅度提高运算符度，大于三倍以上常用于循环中 
	    Sum[i]=Sum[i-1]+(Ans[i]=Sum[i>>1]+1);//位运算 
	return not printf("%d\n",Ans[N]);
}
#include<iostream>//第二种递推 
using namespace std;
int f[1001];
int main()
{
	int n;	cin>>n;f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		if(i%2==0) f[i]+=f[i/2];
	}
	cout<<f[n];
}
