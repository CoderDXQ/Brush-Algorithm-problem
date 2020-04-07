#include<bits/stdc++.h>
using namespace std;
int p,k=499;
int data[3100005];//根据需要更改
int jieguo[500];
int main(){
	cin>>p;
    memset(jieguo,0,sizeof(jieguo));
	for(int i=0;i<p;i++) data[i]=1;
	//转换 
	bool flag=true;
	while(flag){
		if(k<0) break;//根据题意剪枝 
		int num=0;
	    flag=false;
	    for(register int i=0;i<p;i++){
		    num=(num<<1)+data[i];//位运算最好加括号 
		    data[i]=num/10;
			num=num%10;
		    if(data[i]!=0&&flag==false) flag=true;
			//当data[]数组全是0时,flag=false,不再进入循环 
	    }//for循环执行完之后num是本次短除之后的余数 
        jieguo[k--]=num;
    } 
    printf("%d\n",(int)(log10(2)*p+1));//**直接算出位数 
    for(int i=0;i<10;i++){
       	    for(int j=i*50;j<(i+1)*50;j++) cout<<jieguo[j];
       	    cout<<endl;
	   }
    return 0;
}
