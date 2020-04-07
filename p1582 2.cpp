#include<bits/stdc++.h>//妙甚的万能头
using namespace std;//妙甚的命名空间
unsigned long long n,k,sum;//妙甚的变量定义
int main()
{
	
    cin>>n>>k;//妙甚的输入
    if(k>32) k=32;//本句可以无视
    while(k>1&&n>0)//n>0不加的话程序会卡死于此
    for(int i=63;i>=0;i--)
    if(pow(2,i)<=n){n-=pow(2,i);k--;cout<<'A'<<i<<endl;break;}
	//任何一个自然数都可以拆分成若干个2的幂的和
    if(n==0){cout<<"0";return 0;}//特判
    for(int i=0;;i++)
    {
        if(pow(2,i)>=n)
        {
        	cout<<'B'<<i<<endl;
          //  cout<<(unsigned long long)pow(2,i)-n;//妙甚的输出
            break;//看看for循环后边的括号里
        }
    }
    return 0;
}
