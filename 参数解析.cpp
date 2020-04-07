#include<bits/stdc++.h>
using namespace std;

int main(){
	string st;
	string shuchu[100];
	getline(cin,st);//读取整行字符串 
	int i=0,num=0;
	bool yn=0;
	int qian,hou;
	qian=0;
	/*
	for(int i=0;i<st.length();i++){
		printf("%4d",i);
	}	
	cout<<endl;
	for(int i=0;i<st.length();i++){
		printf("%4c",st[i]) ;
	}	
	cout<<endl;
	*/
	
	/*
	while(i<st.length()){
		if(st[i]=='"') {// 防备双引号里的空格 
			yn=!yn;		
			//cout<<i<<' ';
		}
		
		if(yn==0 && st[i]==' '){
			num++;
			hou=i;
		//	cout<<i<<' ';
		} 
		i++;
	}
	num++;	
	cout<<num<<endl;
	*/
	i=0;num=0;
	while(i<st.length()){
		if(st[i]=='"') {// 防备双引号里的空格 
			yn=!yn;
			if(yn==1) qian=i+1;
			if(yn==0) //?????????????
			{
				hou=i;
			//	cout<<qian<<' '<<hou<<endl;
				shuchu[num]=st.substr(qian,hou-qian);
				num++;
				qian=hou+2;
				i=i+2;
				continue;
			}
		}
		
		if(yn==0 && st[i]==' '){
			hou=i;
		//	cout<<qian<<' '<<hou<<endl;
			shuchu[num]=st.substr(qian,hou-qian+1);
			num++;
			qian=hou+1;
		} 

        if(i==st.length()-1 && hou<st.length()-1){
        //	cout<<qian<<' '<<hou<<endl;
        	hou=st.length()-1;
        	shuchu[num]=st.substr(qian,hou-qian+1);
			num++;
		}
		i++;
	}
	cout<<num<<endl;
	for(int i=0;i<num;i++)
	    cout<<shuchu[i]<<endl;
} 
