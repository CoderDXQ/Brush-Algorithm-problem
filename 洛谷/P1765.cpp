#include<stdio.h>
#include<iostream>
#include<istream>

using namespace std;

//注意：不是每个数字键都代表三个数字。
int main()
{
    int sum=0;
    int num[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    string st;



    getline(cin,st);
    for(int i=0;i<st.length();i++)
        {
            if(st[i]==' ') sum++;
            else
            {
                sum+=num[st[i]-'a'];
            }
            
        }
        cout<<sum<<endl;
    return 0;
}