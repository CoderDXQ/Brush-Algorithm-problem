#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string st1,st2,st;
	int i,j,k,len,f,n,max;
	long long ss,s=0;
	cin>>st1>>st2>>f>>n;
	if(f==1)
	{
	    len=st1.length();
	    st=st2;
	    for(i=0;i<len;++i)
	    {
	    	if(st1[i]>='0'&&st1[i]<='9') s=s*n+st1[i]-'0';
	    	else s=s*n+st1[i]-'a'+10;
		}
	}
	else
	{
		st=st1;
	    len=st2.length();
	    for(i=0;i<len;++i)
	    {
	    	if(st2[i]>='0'&&st2[i]<='9') s=s*n+st2[i]-'0';
	    	else s=s*n+st2[i]-'a'+10;
		}
	}//转换出第一个数 
	//按进制从小到大进行试验 剪枝 
	len=st.length();
	n=0;
	for(i=0;i<len;i++){
		if (n<st[i]) n=st[i];
	}
	if(n>='0'&&n<='9') n=n-'0';
	    	else n=n-'a'+10;
	    ss=0;	
	    while(ss<s){
		n++;ss=0;
	    for(i=0;i<len;++i)
	    {
	    	if(st[i]>='0'&&st[i]<='9') ss=ss*n+st[i]-'0';
	    	else ss=ss*n+st[i]-'a'+10;
		}
	//	printf("n=%d ss=%d\n",n,ss);
		if(ss==s){
			printf("%d\n",n);break;
		}
		if(ss>s){
			printf("Impossible\n");break;
		}
	}
}

