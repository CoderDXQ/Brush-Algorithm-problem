#include<bits/stdc++.h>
using namespace std;
int m,n;
string input,output;
int data[1000];//������Ҫ����
void init(){//���ַ�ת��������
	memset(data,0,sizeof(data));
	for(int i=0;i<input.size();i++) {
		if(input[i]<=57) data[i]=input[i]-'0';//57��ASCII������9
		else data[i]=input[i]-'A'+10;
	}
}
bool div(){
	int num=0;
	bool flag=false;
	for(int i=0;i<input.size();i++){
		num=num*m+data[i];
		data[i]=num/n;
		num=num%n;
		if(data[i]!=0) flag=true;
	}//forѭ��ִ����֮��num�Ǳ��ζ̳�֮������� 
	char x;
	if(num<=9) x='0'+num;
	else x='A'+num-10;
	string s(1,x);//�ַ���s����1���ַ�x  ****�µ��ַ�����ֵ���� 
    //string s(p,'1'); ����s����p���ַ�1
	output.insert(0,s);//����ǰ�� ,output.insert()����ֻ�ܲ����ַ��������ܲ����ַ� 
	return flag;
}
void trans(){
	bool flag=true;
	while(flag) flag=div();
	cout<<output<<endl;
}
int main(){//m��ԭ���Ľ��ƣ�n��Ҫת���Ľ��� 
    cin>>m>>n;
	cin>>input;//��inputת�������ֱ����������� 
    memset(data,0,sizeof(data));
	for(int i=0;i<input.size();i++) {
		if(input[i]<=57) data[i]=input[i]-'0';//57��ASCII������9
		else data[i]=input[i]-'A'+10;
	}
    output="";//�ַ�����ʼ��
	trans(); 
    return 0;
}
