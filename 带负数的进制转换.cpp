#include<bits/stdc++.h>
using namespace std;
void zhuan(int n,int r){
	if(n==0) return;
	int m=n%r;//m������
	if(m<0) m=m-r,n=n+r;
	if(m>=10) m='A'+m-10;
	else m+='0';
	zhuan(n/r,r);
	printf("%c",m);
	return; 
}
int main()
{
	int n,r;
	string ans="";//�ַ����ĳ�ʼ��
	cin>>n>>r;
	cout<<n<<'=';
	zhuan(n,r);
	printf("(base%d)",r); 
	return 0;
}
