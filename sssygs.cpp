#include<bits/stdc++.h>
using namespace std;
int p,k=499;
int data[3100005];//������Ҫ����
int jieguo[500];
int main(){
	cin>>p;
    memset(jieguo,0,sizeof(jieguo));
	for(int i=0;i<p;i++) data[i]=1;
	//ת�� 
	bool flag=true;
	while(flag){
		if(k<0) break;//���������֦ 
		int num=0;
	    flag=false;
	    for(register int i=0;i<p;i++){
		    num=(num<<1)+data[i];//λ������ü����� 
		    data[i]=num/10;
			num=num%10;
		    if(data[i]!=0&&flag==false) flag=true;
			//��data[]����ȫ��0ʱ,flag=false,���ٽ���ѭ�� 
	    }//forѭ��ִ����֮��num�Ǳ��ζ̳�֮������� 
        jieguo[k--]=num;
    } 
    printf("%d\n",(int)(log10(2)*p+1));//**ֱ�����λ�� 
    for(int i=0;i<10;i++){
       	    for(int j=i*50;j<(i+1)*50;j++) cout<<jieguo[j];
       	    cout<<endl;
	   }
    return 0;
}
