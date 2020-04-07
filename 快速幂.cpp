// a*b%k=(a%k)*(b%k);
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long b,p,k,ans=1;
	cin>>b>>p>>k;
	cout<<b<<'^'<<p<<" mod "<<k<<'=';
    while(p>0)
    {
    	if(p&1)//按位与，按二进制的每一位进行与运算
		    ans=(ans*b)%k;//一定要有括号，不然*与%两种运算是同级运算， 
		b=(b*b)%k;       // 不一定严格从左到右进行计算
		p>>=1; 
	}
    cout<<ans%k<<endl;
	return 0;
}
