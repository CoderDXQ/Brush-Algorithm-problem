#include<bits/stdc++.h>
using namespace std;
string a[30]; 
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<n;i++)
	    for(j=i+1;j<=n;j++){//字符串的字典序排序可以直接来 
	    	if(a[i]+a[j]<a[j]+a[i])  swap(a[i],a[j]);
		}//字符串相加在字典序选择排序中的应用 
	for(i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;
string a[30];
bool cmp(string a,string b)
{
	return a+b>b+a;//a代表数组头部，b代表数组尾部 
 } 
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);//sort函数传递的是地址 
	for(i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
}
