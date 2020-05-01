

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
bool ok(int x1,int y1,int x2,int y2){//[x1,y1][x2,y2]�ֱ���������������
    int t=(y2-x2+1)/(y1-x1+1),le=y1-x1+1;//t=len2/len1,le=len1
    if((y2-x2+1)%(y1-x1+1))return false;//���������ȶ����ɱ������������й�ϵ
    for(int i=1;i<=t;i++)//�ڶ�������ĳ����ǵ�һ�����䳤�ȵ���t��
        for(int j=1;j<=le;j++)//ö�ٵ�һ�����������λ
            if(s[x1+j-1]!=s[(i-1)*le+x2+j-1])return false;//���μ����Ƿ�ƥ��
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
    int t=r-l+1;//�������ĳ���
    for(int i=l;i<r;i++){//ö�ٷָ��
        t=min(dfs(l,i)+dfs(i+1,r),t);
        if(ok(l,i,i+1,r))t=min(t,dfs(l,i)+2+get((r-i)/(i-l+1)+1));
        //��������������õ�һ��Ŀǰ��̳���
        //+1����ΪҪ�������һ�ַ���
    }
    return f[l][r]=t;
}
int main(){
    //freopen("jh.txt","r",stdin);
    scanf("%s",s+1);n=strlen(s+1);
    printf("%d",dfs(1,n));
    return 0;
}



