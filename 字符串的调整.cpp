#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	getline(cin,str);
	
	int num=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='*'){
			num++;
			str.erase(i,1);
			str.insert(0,"*");
	//		i--;//������*����£�ɾ����һ����ԭ�±�֮����Ȼ��һ��*�������±��Ѿ�����1 
		}
	}
	cout<<str;
} 
