#include<bits/stdc++.h>
using namespace  std;

int main()
{
    int k,len;
    int st[10000][35];
    string s;

    memset(st,10000*35*sizeof(int),0);
    cin>>k;
    int ji=0;

    while (ji<k)
    {
        cin>>s;
        int i=0;
        int wz=1;
        int num=0;
        while (s[i]<='9' && s[i]>='0')
        {//1
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        
        while(num>0)
        {
            int end=8;
            st[ji][end--]=num%2;
            num>>1;
        }
        cout<<num<<endl;

        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//2
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        while(num>0)
        {
            int end=16;
            st[ji][end--]=num%2;
            num>>1;
        }
        cout<<num<<endl;

        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//3
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        while(num>0)
        {
            int end=24;
            st[ji][end--]=num%2;
            num>>1;
        }
        cout<<num<<endl;

        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//4
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        while(num>0)
        {
            int end=32;
            st[ji][end--]=num%2;
            num>>1;
        }
        cout<<num<<endl;

        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//5
            num=num*10+s[i]-'0';
            i++;
        }
        cout<<num<<endl;
        st[k][0]=num;

        for(int i=0;i<=32;i++)
        {
            cout<<st[ji][i]<<' ';
        }
        cout<<endl;

        ji++;
    }
    




    return 0;
}
