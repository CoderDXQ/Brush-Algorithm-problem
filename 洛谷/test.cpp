#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
    vector<int> sav;
    sav.push_back(1);
    sav.push_back(2);
    for(vector<int>::iterator it=sav.begin();it!=sav.end();it++)
        cout<<" "<<*it;
    
    cout<<endl;
    return 0;
}