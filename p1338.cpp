#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int p=n,c=0;//p�����һ����ԭʼ���е�λ�� 
	for(int s=1;m>0;s++,p--)
	{//��p��λ�� 
		c=min(s,m);//m����һ������Ҫ�ճ���������� c������p���ƿ��Դճ���������� 
		m-=c;//s����p������Ϊ������ӵ�����Ը��� 
	}
	for(int i=1;i<p;i++){
		cout<<i<<' ';
	}//���˳��     
	cout<<p+c<<' ';//�����һ����ԭʼ����λ���ϵ���
//�ҵ�P��λ�ú����λ���ϵ���ÿ����һ����Ծ�����һ 
	for(int i=n;i>=p;i--){
		if(i!=p+c){
			cout<<i<<' ';
		}
	}
	return 0;
}

