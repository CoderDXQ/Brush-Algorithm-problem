#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int quan[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,24};
	int cuo=0;
	
	while(n>0){
		string str;
		int s,sum=0;
		bool b=true;
		cin>>str;
		for(int i=0;i<16;i++){
			if(str[i]=='x') {
			    //sum+=10*quan[i];
			    b=false;
			    cout<<str<<endl;
			    break;
				} 
			else sum+=(str[i]-'0')*quan[i];
		}
		s=sum%11;
		if(s==10&&str[16]!='x') b=false;
	//	if(b==false) cout<<str<<endl;
		
		//cout<<s<<endl;
		//if(b==true) 
		n--;
	}
	if (cuo==0)cout<<"All passed"<<endl; 
	
 } 
