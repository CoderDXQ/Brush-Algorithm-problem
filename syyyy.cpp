#include<bits/stdc++.h>
using namespace std;
map<char,char>m0,m1;  //m0记录密文对明文，m1记录明文对密文
char miwen[10000],mingwen[10000],target[10000];
int main()
{
    cin>>miwen>>mingwen>>target;//也可以用gets（）；
	//cout<<miwen<<'\n'<<mingwen<<'\n'<<target; 
    for(int i=0;i<strlen(miwen);i++)//检查自相矛盾的字母 
    {//字符串就是字符数组
        if((m0.count(miwen[i]) && m0[miwen[i]]!=mingwen[i]) || (m1.count(mingwen[i]) && m1[mingwen[i]]!=miwen[i]))
        {
            cout<<"Failed";
            return 0;
        }
        else
        {
            m0[miwen[i]]=mingwen[i];
            m1[mingwen[i]]=miwen[i];//生成map 
        }
    }
    char temp='A';
    for(int i=0;i<26;i++)//检查有没有没出现的字母 
    {
        if(!m1.count(temp+i))
        {
            cout<<"Failed";
            return 0;
        }
    }
    for(int i=0;i<strlen(target);i++)
    {
        if(target[i]!=' ')//注意输入的翻译信息行末有空格！！还有可能是一段话 
            cout<<m0[target[i]];
    }
    return 0;
}
