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
    int i=0;

    for(int i=0;i<st.length();i++)
        {//开头的空格也要按一次
            if(st[i]==' ') sum++;
            else if(st[i]<='z' && st[i]>='a')//getcline会读入末尾的回车 因此else语句必须要再用if限制一下
            {
                sum+=num[st[i]-'a'];
            }
            
        }
    cout<<sum<<endl;
    return 0;
}