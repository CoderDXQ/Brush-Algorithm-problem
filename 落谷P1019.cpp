#include<bits/stdc++.h>
using namespace std;
string str[50],begin;
int length=0,n;//��Ҫ��ʼ�� 
int vis[50];//���ĳ���ַ����Ƿ�ʹ�� 
//int vis[50]={1};ֻ�Ǹ���һ��Ԫ�ؼ�vis[0]��ֵ 
int canlink(string str1,string str2){
	for(int i=1;i<=min(str1.length(),str2.length());i++){//i���غϵĳ��� 
		int flag=1;
		for(int j=0;j<i;j++) 
		   if(str1[str1.length()-i+j]!=str2[j]) flag=0;
		if(flag) return i;//����̰��ԭ��ȡ���ظ�����Խ���ܵĳ���Խ�� 
	}
	return 0;
}
/* int canlink(string str1,string str2){
	int j=0;
	while(str1[str1.length()-1-j]==str2[j]) j++;
	return j;
} //���ֱȷ��Ǵ���� */
void solve(string strnow,int lengthnow){
	length=max(lengthnow,length);//������󳤶� 
	for(int i=0;i<2*n;i++){
		if (vis[i]==false) continue;//��֦ 
		int c=canlink(strnow,str[i]);
//cout<<"c="<<c<<" strnow="<<strnow<<" str[i]="<<str[i]<<" i="<<i<<endl;���� 
		if(c>0){
			vis[i]=false;
			solve(str[i],lengthnow+str[i].length()-c);
			vis[i]=true;//���� 
		}
	}
}
int main(){//memset(vis,1,sizeof(vis));//memsetֻ�ܸ�ֵ0��-1 
	fill(vis,vis+50,1);//��vis���鸳��ֵ 
	cin>>n;//ÿ���ַ������ʹ�����Σ���ô��������ַ�������һ�μ��� 
	for(int i=0;i<n;i++){cin>>str[i];str[i+n]=str[i];}//str[n]Ϊ��ʼ���Ǹ��ַ� 
	cin>>begin;
	solve(begin,1);
    cout<<length;
    return 0;
}
