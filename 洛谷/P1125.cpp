#include<iostream>
#include<stdio.h>
#include<cstring>//这个头包含memset函数

using namespace std;

const int prime[25]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};//打表 设置成常量可以使运算更快

int main()
{

    string st;
    cin>>st;
    int count[26],max=-1,min=101;

    memset(count,0,sizeof(count));

    for(int i=0;i<st.length();i++)
    {
        count[st[i]-'a']++;
        if(max<count[st[i]-'a'])
        {
            max=count[st[i]-'a'];
        }
    }

     for(int i=0;i<26;i++)
     {
         if(count[i]>0 && min>count[i])  
         {
             min=count[i];
         }
     }

    int num=max-min;

    for(int i=0;i<25;i++)
    {
        if(prime[i]==num)
        {
            cout<<"Lucky Word"<<endl;
            cout<<num<<endl;
            return 0;//直接结束程序
        }   

    }

    cout<<"No Answer"<<endl;
    cout<<0<<endl;



    return 0;
}