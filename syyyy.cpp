#include<bits/stdc++.h>
using namespace std;
map<char,char>m0,m1;  //m0��¼���Ķ����ģ�m1��¼���Ķ�����
char miwen[10000],mingwen[10000],target[10000];
int main()
{
    cin>>miwen>>mingwen>>target;//Ҳ������gets������
	//cout<<miwen<<'\n'<<mingwen<<'\n'<<target; 
    for(int i=0;i<strlen(miwen);i++)//�������ì�ܵ���ĸ 
    {//�ַ��������ַ�����
        if((m0.count(miwen[i]) && m0[miwen[i]]!=mingwen[i]) || (m1.count(mingwen[i]) && m1[mingwen[i]]!=miwen[i]))
        {
            cout<<"Failed";
            return 0;
        }
        else
        {
            m0[miwen[i]]=mingwen[i];
            m1[mingwen[i]]=miwen[i];//����map 
        }
    }
    char temp='A';
    for(int i=0;i<26;i++)//�����û��û���ֵ���ĸ 
    {
        if(!m1.count(temp+i))
        {
            cout<<"Failed";
            return 0;
        }
    }
    for(int i=0;i<strlen(target);i++)
    {
        if(target[i]!=' ')//ע������ķ�����Ϣ��ĩ�пո񣡣����п�����һ�λ� 
            cout<<m0[target[i]];
    }
    return 0;
}
