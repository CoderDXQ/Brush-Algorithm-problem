#include<iostream>
#include<string>
#include<cstring>//���ӻ�CE
using namespace std;
int n;
string s;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=2;i<=n;++i)//���ڵ�һ��Ϊԭ�������Ե�������
    {
        string ss;
        cin>>ss;
        int x=s.find(ss[0]);//�ҵ���������ĸ��ڵ���ԭ���е�λ��
        s.erase(x,1);//������ڵ�
        s.insert(x,ss);//��������
    }
    for(int i=0;i<s.size();++i)
    if(s[i]!='*') cout<<s[i];//������սڵ�
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
        if (a[i][0] == x) break;  //��������
    for (j=1;j<3;j++)
        if (a[i][j] != '*') pig(a[i][j]);    //����
}
int main()
{
    long i,j,m,k;
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    pig(a[1][0]);   //�Ӹ��ڵ㿪ʼ
    while(1) //����Ϯ
    return 0;
}
