#include <bits/stdc++.h>
using namespace std;
int f[1001],p,res[1001],sav[1001],s;//save[]���ݴ������̵Ľ�������� 
void result_1(){//����
	memset(sav,0,sizeof(sav));
	for(int i=1;i<=500;i++)//�˷��޵��� 
	    for(int j=1;j<=500;j++) sav[i+j-1]+=res[i]*f[j];
	for(int i=1;i<=1000;i++){//�����λ 
		sav[i+1]+=sav[i]/10;
		sav[i]=sav[i]%10;
	}
	//memcpy(res,sav,sizeof(res));//���ƺ��� 
	for(int i=0;i<=1000;i++) res[i]=sav[i]; //�洢��� 
 } 
void result_2(){//�Գ� 
	memset(sav,0,sizeof(sav));
	for(int i=1;i<=500;i++)//ѭ����500���ɣ����õ�1000 
	    for(int j=1;j<=500;j++) sav[i+j-1]+=f[i]*f[j];//�˷��޵��� 
	for(int i=1;i<=1000;i++){
		sav[i+1]+=sav[i]/10;
		sav[i]=sav[i]%10;
	}
	for(int i=0;i<=1000;i++) f[i]=sav[i];//�洢��� 
 } 
int main(){
	cin>>p;
	s=(int)(log10(2)*p)+1;//log10���Դ����� 
	res[1]=1;//��ʼ��Ӧ����1 
	f[1]=2;//��Ҫ��ʼ�� f[]��2��p�η��Ľ������ʼ��Ӧ����2������1 
	cout<<s<<endl;
	while(p) {//����2��p�η�
		if(p&1) result_1();//���� 
		p>>=1;
		result_2();//�Գ� 
	}
	res[1]-=1;//2��p�η�-1
	for(int i=500;i>=1;i--){//��� 
	        if(i<500&&i%50==0) cout<<endl;
	    	cout<<res[i];
		 } 
	return 0;
}  
