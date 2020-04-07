#include<cstdio>
#include<iostream>
#include<map>
#include<stack>
#include<string>//只能用cin cout 输入输出 
using namespace std;
int main()
{
	int i,j,k;
	int s;
	string c;
	stack<int> st;
	map<int,string> mp;
	mp[0]="zero";//字符串是双引号，字符是单引号 
	mp[1]="one";
	mp[2]="two";
	mp[3]="three";
	mp[4]="four";
	mp[5]="five";
	mp[6]="six";
	mp[7]="seven";
	mp[8]="eight";
	mp[9]="nine";
	
	//for(i=0;i<110;i++) a[i]=-1;
    cin>>c;
    k=c.length();
    s=0;
    //map<char,string>::iterator it;
    for(i=0;i<k;++i)
    {
    	s=s+c[i]-'0';
    }
    
    	
    //printf("%d\n",s);
    if (s==0) printf("zero\n");
    while(s>0)
    {
        k=s%10;
		st.push(k);
		s=s/10;	
	}
	while(st.empty()==false)
	{
		k=st.top();
		st.pop();
     	if(st.empty()==false) cout<<mp[k]<<' ';
     	else cout<<mp[k]<<'\n';
     	
	}
}
