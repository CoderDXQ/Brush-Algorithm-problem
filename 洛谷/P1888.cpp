
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int gcd(int x,int y);
int main()
{
    long long minn,maxx,a,b,c,g;
    cin>>a>>b>>c;
    minn=min(a,b);
    minn=min(minn,c);
    maxx=max(a,b);
    maxx=max(maxx,c);
    g=gcd(maxx,minn);
    cout<<minn/g<<"/"<<maxx/g<<endl;
    return 0;
}


//更相减损法
int gcd(int x,int y)
{
    if(x==y)
        return x;
    if(x<y)
        return gcd(y-x,x);
    else
        return gcd(x-y,y);
}
//辗转相除法
//int gcd(int x,int y) {return y?gcd(y,x%y):x;} 
