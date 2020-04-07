#include<iostream>
#include<string>
#include<cstring>//不加会CE
using namespace std;
int n;
string s;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=2;i<=n;++i)//由于第一个为原串，所以单独输入
    {
        string ss;
        cin>>ss;
        int x=s.find(ss[0]);//找到这个子树的根节点在原串中的位置
        s.erase(x,1);//清除根节点
        s.insert(x,ss);//加入子树
    }
    for(int i=0;i<s.size();++i)
    if(s[i]!='*') cout<<s[i];//不输出空节点
    else continue;
}

#include<bits/stdc++.h>
using namespace std;
string a[10001];
long n;
void pig(char x)
{
    cout<<x;   
    long i,j;
    for (i=1;i<=n;i++)
        if (a[i][0] == x) break;  //找所在行
    for (j=1;j<3;j++)
        if (a[i][j] != '*') pig(a[i][j]);    //深搜
}
int main()
{
    long i,j,m,k;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    pig(a[1][0]);   //从根节点开始
    while(1) //防抄袭
    return 0;
}
