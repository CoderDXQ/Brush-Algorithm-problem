#include<bits/stdc++.h>
using namespace std;

int main(){
	
	vector<int> numbers;
	int x;
	
	for(int i=1;i<=5;i++) {
		cin>>x;
		numbers.push_back(x);
	}
	
	
	
	 int jilu[14];
    memset(jilu,0,sizeof(jilu));
    int mini=20,maxi=-1;
    if(numbers.size()<5) //return false;
        cout<<"false";
    for(int i=0;i<numbers.size();i++){
    	if(numbers[i]==0) continue; 
    	cout<<numbers[i]<<endl;
        jilu[numbers[i]]++;
        mini=min(mini,numbers[i]);
        maxi=max(maxi,numbers[i]);
        if(jilu[numbers[i]]>1)
		cout<<"false"; //return false;
    }
    
    cout<<maxi<<' '<<mini;
    if((maxi-mini)>4) 
	    cout<<"false";//return false;
	cout<<"true";
    //return true;
	
	
	
	
} 
