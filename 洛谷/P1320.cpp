//这个题可以不存储直接输出
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
    char a;
    char pre;
    int sum,s;
    vector<int> sav;

    cin>>a;
    pre=a;
    sum=1;
    s=1;

    while(cin>>a)
    {
        sum++;
        if(pre==a)
        {
            s++;
        }
        else
        {
            sav.push_back(s);
            s=1;
            pre=a;
        }
        
    }
    sav.push_back(s);

    cout<<sqrt(sum);
    for(vector<int>::iterator it=sav.begin();it<=sav.end();it++)
        cout<<" "<<*it;
    
   // cout<<endl;
    return 0;
}