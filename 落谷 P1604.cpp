#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[2010],b[2010],c[2018],i,y,x,l1,l2,z;
	char n[2001],m[2001];
	cin>>z;
	cin>>n;cin>>m;
	//���������ڶ���ı���������Ҫ�г�ʼ�� 
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));
	l1=strlen(n);l2=strlen(m);
	for(i=0;i<l1;i++)
	    if(z>10&&n[i]>='A') a[l1-i]=n[i]-'A'+10;//��������10�Ľ���
		else a[l1-i]=n[i]-'0';
	 for(i=0;i<l2;i++)
	    if(z>10&&m[i]>='A') b[l2-i]=m[i]-'A'+10;//��������10�Ľ���
		else b[l2-i]=m[i]-'0';
		x=0;y=0;//����Ҫ���г�ʼ�� 
	while(x<=l1||x<=l2){
		x++;//x��λ����y�ǽ�λ 
		c[x]=y+a[x]+b[x];
		y=c[x]/z;
		c[x]%=z;
	}
	while(c[x]==0&&x>1) x--;
	for(i=x;i>=1;i--){
	    if(c[i]<10) cout<<c[i];
	    else cout<<(char)(c[i]-10+'A');
		}
//	 cout<<endl;
	 return 0;
}
