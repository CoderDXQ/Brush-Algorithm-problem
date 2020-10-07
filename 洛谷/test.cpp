#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
    // vector<int> sav;
    // sav.push_back(1);
    // sav.push_back(2);
    // for(vector<int>::iterator it=sav.begin();it!=sav.end();it++)
    //     cout<<" "<<*it;
    
    // cout<<endl;


    string st;
    getline(cin,st);
    for(int i=0;i<=st.length();i++) //输出所有字符包括末尾回车的ASCII码   getline方法会读入末尾的换行符
        cout<<(int)(st[i])<<" ";

    return 0;
}