//任何三条对角线不交于一点的意思是只有两条对角线交于一点，即四个顶点就可以确定一个对角线的交点
#include<stdio.h>
#include<iostream>
//#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    if(n<=3)
    {
        cout<<0<<endl;
    }
    else
    {
        unsigned long long s=0;
        s=(n-3)*(n-2)/2*(n-1)/3*n/4;//前三个数中一定有一个3的倍数和2的倍数，先除了防止超界
        cout<<s<<endl;   
    }
    
    //cout<<"dfgds";
    return 0;
}
