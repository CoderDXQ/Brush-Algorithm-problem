#include<bits/stdc++.h>
using namespace std;
string a[30]; 
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<n;i++)
	    for(j=i+1;j<=n;j++){//�ַ������ֵ����������ֱ���� 
	    	if(a[i]+a[j]<a[j]+a[i])  swap(a[i],a[j]);
		}//�ַ���������ֵ���ѡ�������е�Ӧ�� 
	for(i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
}

#include<bits/stdc++.h>
using namespace std;
string a[30];
bool cmp(string a,string b)
{
	return a+b>b+a;//a��������ͷ����b��������β�� 
 } 
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);//sort�������ݵ��ǵ�ַ 
	for(i=1;i<=n;i++) cout<<a[i];
	cout<<endl;
}
