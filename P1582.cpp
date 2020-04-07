#include<bits/stdc++.h>
using namespace std;
//本题实质上是用不超过k个1和无数个0生成一个最接近且大于n的二进制数 
int main()
{
	long long n,k,s=0,mi=2000000000;
	long long a[32];
	bool b[32];
	memset(b,false,sizeof(b));
	a[0]=1;
	for(int i=1;i<=31;i++) a[i]=a[i-1]<<1;
	cin>>n>>k;
	while(n>0&&s<k)
	{
		for(int i=0;i<=31;i++)
		    if(n<a[i]&&b[i]==false) 
		    {
		    	mi=min(mi,a[i]-n);//记录在将第i位设置为1时需要购买的瓶子数 
		    	s++;
		    	int k=i-1;
		    	while (b[k]==true&&k>=0) k--;
				//检索第i位标记为零时，应该将哪一位标记为1才能更接近n 
		    	if(k==-1)
		    	{
		    		cout<<mi;
					return 0;
				}
				n-=a[k];//更新n 
				b[k]=true;//标记用过的那一位 
				break;
			}
			else if(n==a[i]&&b[i]==false)
			{
				cout<<0;
				return 0;	
			}
	}
	cout<<mi;
	return 0;
}
