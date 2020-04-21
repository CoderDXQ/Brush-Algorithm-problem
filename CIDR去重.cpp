#include<bits/stdc++.h>
using namespace  std;

int main()
{
    int k,len,sum;
    int st[10000][35];
    string cun[10000];
    string s;
    bool bj[10000];
    memset(bj,0,10000*sizeof(bool));
    memset(st,0,10000*35*sizeof(int));
    cin>>k;
    int ji=0;
    sum=k;
//提取
    while (ji<k)
    {
        cin>>s;
        cun[ji]=s;
        int i=0;
        int wz=1;
        int num=0;
        int end;

        while (s[i]<='9' && s[i]>='0')
        {//1
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        end=8;
        while(num>0)
        {  
            st[ji][end--]=num%2;
            num=num>>1;
        }


        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//2
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        end=16;
        while(num>0)
        {
            st[ji][end--]=num%2;
            num=num>>1;
        }


        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//3
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        end=24;
        while(num>0)
        {
            st[ji][end--]=num%2;
            num=num>>1;
        }


        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//4
            num=num*10+s[i]-'0';
            i++;
        }
        i++;
        end=32;
        while(num>0)
        {
            st[ji][end--]=num%2;
            num=num>>1;
        }


        num=0;
        while (s[i]<='9' && s[i]>='0')
        {//5
            num=num*10+s[i]-'0';
            i++;
        }
        st[ji][0]=num;
        bj[ji]=1;
/**
        for(int i=0;i<=32;i++)
        {
            cout<<st[ji][i]<<' ';
        }
        cout<<endl;
**/
        ji++;
    }
    

    for(int i=0;i<k;i++)
    {
        if(bj[i]==true)
        {
            for(int j=0;j<k;j++)
            {
                if(bj[j]==true && i!=j)
                {
                    int mmin,xiao,da;
                    if(st[i][0]<=st[j][0])
                    {
                        xiao=i;da=j;mmin=st[i][0];
                    }
                    else
                    {
                        xiao=j;da=i;mmin=st[j][0];
                    }
                    
                    int h=1;
                    while(h<=mmin && st[i][h]==st[j][h])
                    {
                        h++;    
                    }
                    if(h>st[xiao][0]) 
                    {
                        bj[da]=false;
                        sum--;
                    }
                }

            }
        }
    }


    cout<<sum<<endl;
    for(int i=0;i<k;i++)
    {
        if(bj[i]==true)
        {
            cout<<cun[i]<<endl;
        }
    }
    
 /*   
    for(int i=0;i<100;i++)
        cout<<bj[i];
*/

    return 0;
}