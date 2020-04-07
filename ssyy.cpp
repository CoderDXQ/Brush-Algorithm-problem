#include<bits/stdc++.h>
using namespace std;
int m,n;
string input,output;
int data[1000];//根据需要更改
void init(){//把字符转化成数字
	memset(data,0,sizeof(data));
	for(int i=0;i<input.size();i++) {
		if(input[i]<=57) data[i]=input[i]-'0';//57在ASCII码中是9
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
	}//for循环执行完之后num是本次短除之后的余数 
	char x;
	if(num<=9) x='0'+num;
	else x='A'+num-10;
	string s(1,x);//字符串s中有1个字符x  ****新的字符串赋值方法 
    //string s(p,'1'); 符串s中有p个字符1
	output.insert(0,s);//插在前面 ,output.insert()函数只能插入字符串，不能插入字符 
	return flag;
}
void trans(){
	bool flag=true;
	while(flag) flag=div();
	cout<<output<<endl;
}
int main(){//m是原来的进制，n是要转换的进制 
    cin>>m>>n;
	cin>>input;//把input转化成数字保存在数组中 
    memset(data,0,sizeof(data));
	for(int i=0;i<input.size();i++) {
		if(input[i]<=57) data[i]=input[i]-'0';//57在ASCII码中是9
		else data[i]=input[i]-'A'+10;
	}
    output="";//字符串初始化
	trans(); 
    return 0;
}
