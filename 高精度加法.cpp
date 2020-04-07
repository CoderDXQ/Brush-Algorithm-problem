#include<bits/stdc++.h>
using namespace std;
char a1[1000],b1[1000];
int a[1000],b[1000],c[1000];
int main()
{
	memset(c,0,sizeof(c));//初始化 
	scanf("%s",a1);scanf("%s",b1);
	int lena=strlen(a1),lenb=strlen(b1);
	for(int i=0;i<lena;i++) {a[lena-i-1]=int(a1[i]-48);} 
	 for(int i=0;i<lenb;i++) {b[lenb-i-1]=int(b1[i]-48);//倒序处理便于进位 }
	int m=max(lena,lenb);
	for(int i=0;i<m;i++)
	{
		c[i]+=a[i]+b[i];
		while(c[i]>=10)	{c[i+1]++;c[i]=c[i]-10;}
	}
	while(c[m]==0&&m!=0) m--;//避免0+0时不输出 
	for(int i=m;i>=0;i--) cout<<c[i];
	cout<<endl;
	return 0;
}
