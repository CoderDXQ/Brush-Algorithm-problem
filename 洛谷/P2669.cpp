#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    long long i,k,sum,day;

    cin>>k;

    i=1;sum=0;day=1;
    while(day<=k)
    {
        for(int j=1;j<=i;j++)
            if(day<=k)
            {
                sum+=i;
                day++;
            }
        i++;
    }
    cout<<sum<<endl;
    return 0;
}