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
    	if(p&1)//��λ�룬�������Ƶ�ÿһλ����������
		    ans=(ans*b)%k;//һ��Ҫ�����ţ���Ȼ*��%����������ͬ�����㣬 
		b=(b*b)%k;       // ��һ���ϸ�����ҽ��м���
		p>>=1; 
	}
    cout<<ans%k<<endl;
	return 0;
}
