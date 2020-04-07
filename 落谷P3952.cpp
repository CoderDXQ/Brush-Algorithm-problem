#include<bits/stdc++.h>
using namespace std;
string a,b;
int c,d,e,f[27],g[27],h,k,l[100],m,n,o;
int main()
{
	cin>>o;
	while(o>0){
		c=0;d=0;m=0;n=0;e=0;h=0;k=0;o--;
		memset(f,0,sizeof(f));memset(l,0,sizeof(l));//³õÊ¼»¯ 
		do{a=b;cin>>b;}while(b[0]!='O');
		for(int i=0;i<a.length();i++) c=c*10+a[i]-'0'; 
		for(int i=4;i<b.length()-1;i++) d=d*10+b[i]-'0';
		while(c>0)
		{
			c--;cin>>a;
			if(a[0]=='F')
			{
				e++;cin>>a;
				if(f[a[0]-96]) e=-1;
				else f[a[0]-96]=1,g[e]=a[0]-96;
				cin>>a>>b;
				if(a[0]!='n'&&b[0]=='n'&&k==0) h++,l[e]=1;
				else if(((a.length()==b.length()&&a>b)||(a.length()>b.length())||(a[0]=='n'&&b[0]!='n'))&&k==0) k=1,n=e;
			}else
			{
				m=max(m,h);f[g[e]]=0;
				if(l[e]==1)h--,l[e]=0;
				e--;
				if(n>0&&e<n) k=0,n=0;
			}
			if(e==-1) printf("ERR\n"),c=-1;
		}
		if(e>0) printf("ERR\n");
		if(e==0&&m==d) printf("Yes\n");
		if(e==0&&m!=d) printf("No\n");
	}
	return 0;
}
