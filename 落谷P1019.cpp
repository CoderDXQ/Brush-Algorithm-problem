#include<bits/stdc++.h>
using namespace std;
string str[50],begin;
int length=0,n;//重要初始化 
int vis[50];//标记某个字符串是否被使用 
//int vis[50]={1};只是给第一个元素即vis[0]赋值 
int canlink(string str1,string str2){
	for(int i=1;i<=min(str1.length(),str2.length());i++){//i是重合的长度 
		int flag=1;
		for(int j=0;j<i;j++) 
		   if(str1[str1.length()-i+j]!=str2[j]) flag=0;
		if(flag) return i;//根据贪心原理，取得重复长度越短总的长度越大 
	}
	return 0;
}
/* int canlink(string str1,string str2){
	int j=0;
	while(str1[str1.length()-1-j]==str2[j]) j++;
	return j;
} //这种比法是错误的 */
void solve(string strnow,int lengthnow){
	length=max(lengthnow,length);//更新最大长度 
	for(int i=0;i<2*n;i++){
		if (vis[i]==false) continue;//剪枝 
		int c=canlink(strnow,str[i]);
//cout<<"c="<<c<<" strnow="<<strnow<<" str[i]="<<str[i]<<" i="<<i<<endl;调试 
		if(c>0){
			vis[i]=false;
			solve(str[i],lengthnow+str[i].length()-c);
			vis[i]=true;//回溯 
		}
	}
}
int main(){//memset(vis,1,sizeof(vis));//memset只能赋值0，-1 
	fill(vis,vis+50,1);//对vis数组赋初值 
	cin>>n;//每个字符串最多使用两次，那么将输入的字符串复制一次即可 
	for(int i=0;i<n;i++){cin>>str[i];str[i+n]=str[i];}//str[n]为开始的那个字符 
	cin>>begin;
	solve(begin,1);
    cout<<length;
    return 0;
}
