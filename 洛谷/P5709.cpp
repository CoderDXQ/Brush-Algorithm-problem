#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long  m,t,s,r;
    //int m,t,s;
    cin>>m>>t>>s;
    if(s<=0)
    {
        cout<<m<<endl;
        return 0;
    }
    if(t<=0)
    {
        cout<<0<<endl;
        return 0;
    }
    r=m-ceil((double)s/t);//ceil处理的是double数据，s/t必须经过转换才行
    if(r<0)
        cout<<0<<endl;
    else
        cout<<r<<endl;

    return 0;
}