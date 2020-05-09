//https://www.nowcoder.com/questionTerminal/5f76ce2a25744d96bb9797e03c523302
//DP解法
#include<bits/stdc++.h>
using namespace std;
string encode(string s)
{
    int length=s.size();
    //二维动态数组 元素是vector<string>
    //vector<string>(length,"")的意思是vector数组初始长度为length，内容为空
    vector<vector<string>> dp(length,vector<string>(length,""));

    for(int step=1;step<=length;step++)
    {
        for(int i=0;i+step-1<length;i++)
        {
            int j=i+step-1;
            dp[i][j]=s.substr(i,step);
            for(int k=i;k<j;k++)
            {
                string left=dp[i][k];
                string right=dp[k+1][j];
                if(left.size()+right.size()<dp[i][j].size())
                {
                    dp[i][j]=left+right;
                }
            }
            string t=s.substr(i,j-i+1),replace="";
            auto pos=(t+t).find(t,1);//找到重复的部分
            if(pos>=t.size()) 
                replace=t;
            else
                replace=to_string(t.size()/pos)+'['+dp[i][i+pos-1]+']';
            if(replace.size()<dp[i][j].size()) dp[i][j]=replace;
        }
    }

    for(int i=0;i<length;i++)
    {
        for(int j=0;j<length;j++)
            cout<<dp[i][j];
        cout<<endl;
    }

    return dp[0][length-1];
}



int main()
{
    string s;
    cin>>s;
    cout<<encode(s).length()<<endl;
    return 0;
}