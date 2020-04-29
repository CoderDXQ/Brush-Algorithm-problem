
#include <bits/stdc++.h>
using namespace std;
 
string encoding_string(string s)
{
    if (s == "")return "";
    if (s.size() <= 4)return s;
 
    int len = s.size();
    int len2 = len / 2;    //重复子串的最大长度 可以分成的份数至少要2份
 
    int best_count = 0;//一次遍历得到的最优重复数
    int best_len = INT_MAX;//一次遍历得到的最优压缩到的长度
    string pre, cur, lat;//一次遍历得到的最优子串
 
    while (len2 >= 1)//重复子串长度最小为1
    {
        for (int k = 0; k <= len - len2; k++)//从第k个下标开始找重复子串
        {
            int count = 1;
            string s2 = s.substr(k, len2);
            string s3, s4;
            for (int j = 1; len2 * j + len2 <= len; j++)
            {
                s3 = s.substr(k + len2 * j, len2);
                if (s2.compare(s3) == 0 && s2.size() == s3.size())
                    count++;
                else
                    break;
            }
 
            int newlen = (len - count * len2) + 3 + len2;//压缩后的字符串长度
            if (newlen < len && newlen < best_len && count > 1)//如果压缩有效
            {
                best_len = newlen;
                best_count = count;
                pre = s.substr(0, k);
                cur = s.substr(k, len2);
                lat = s.substr(k + count * len2);
            }
 
        }
        len2--;//重复字符串长度缩短1
    }
 
    if (best_count == 0)
        return s;
 
    return encoding_string(pre) + to_string(best_count) + "[" + encoding_string(cur) + "]" + encoding_string(lat);
}
int main()
{
    string s;
    cin >> s;
 
    string result = "";
    result = encoding_string(s);
 
    cout << result.size() << endl;
 
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
string encode(string s) {
        int lenth = s.size();
        vector<vector<string>> dp(lenth,vector<string>(lenth,""));
        for(int step=1;step<=lenth;step++){
            for(int i=0;i+step-1<lenth;i++){
                int j=i+step-1;
                dp[i][j]=s.substr(i,step);
                for(int k=i;k<j;k++){
                    string left = dp[i][k];
                    string right = dp[k+1][j];
                    if(left.size()+right.size()<dp[i][j].size()){
                        dp[i][j]=left+right;
                    }
                }
                string t = s.substr(i,j-i+1),replace="";
                auto pos = (t+t).find(t,1);
                if(pos>=t.size()) replace=t;
                else replace = to_string(t.size() / pos) + '[' + dp[i][i + pos - 1] + ']';
                if(replace.size()<dp[i][j].size()) dp[i][j]=replace;
            }
        }
        return dp[0][lenth-1];
}
 
int main(){
    string s;
    cin>>s;
    cout<<encode(s).length()<<endl;
}



#include<cstdio>
#include<iostream>
#include<cstring>
#define N 170
using namespace std;
int f[N][N],n;char s[N];
bool ok(int x1,int y1,int x2,int y2){//[x1,y1][x2,y2]分别是左右两半区间
    int t=(y2-x2+1)/(y1-x1+1),le=y1-x1+1;//t=len2/len1,le=len1
    if((y2-x2+1)%(y1-x1+1))return false;//两者连长度都不成比例，更不会有关系
    for(int i=1;i<=t;i++)//第二段区间的长度是第一段区间长度的整t倍
        for(int j=1;j<=le;j++)//枚举第一段区间的所有位
            if(s[x1+j-1]!=s[(i-1)*le+x2+j-1])return false;//依次检验是否匹配
    return true;
}
int get(int t){
    int p=0;
    while(t){t/=10;p++;}
    return p;
}
int dfs(int l,int r){
    if(l==r)return 1;
    if(l>r)return 0;
    if(f[l][r])return f[l][r];
    int t=r-l+1;//这段区间的长度
    for(int i=l;i<r;i++){//枚举分割点
        t=min(dfs(l,i)+dfs(i+1,r),t);
        if(ok(l,i,i+1,r))t=min(t,dfs(l,i)+2+get((r-i)/(i-l+1)+1));
        //如果符合条件，得到一个目前最短长度
        //+1是因为要加上左侧一字符串
    }
    return f[l][r]=t;
}
int main(){
    //freopen("jh.txt","r",stdin);
    scanf("%s",s+1);n=strlen(s+1);
    printf("%d",dfs(1,n));
    return 0;
}



