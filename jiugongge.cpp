#include<bits/stdc++.h>
using namespace std;

int a[9][9];
int sum=0;
int s=0;
int t=0;
//void shuchu(); 
//输出所有正确结果或无结果的情况 
bool check(int key,int n){
	//行
	int j=n/9; 
	for(int i=0;i<9;i++)
	    if(a[j][i]==key) 
	        return false;
	//列 
	j=n%9;
	for(int i=0;i<9;i++) {
		if(a[i][j]==key)
		    return false;
	}
	//九个小方块
	int x=n/9;//n的行坐标
	int y=n%9;//n的列坐标
	//最重要的技巧 
	x=x/3*3;//n所在的小方块最左上角的坐标 
	y=y/3*3; 
	for(int i=x;i<x+3;i++)
	    for(int j=y;j<y+3;j++)
		    if(a[i][j]==key)
			    return false; 	 
			    
	return true;
}

int DFS(int n){
	s++;
	if(n>80){
		sum++;
		shuchu();
	    cout<<sum<<endl; 
		return 0;
	}
	if(a[n/9][n%9]!=0){
		DFS(n+1);
	}
	else{
		for(int i=1;i<=9;i++){
			if(check(i,n)){
			    a[n/9][n%9]=i;
				DFS(n+1);
				//shuchu();
				a[n/9][n%9]=0;//回溯 
			}
		}	
	}	 
	 return 0;
} 


int main()
{
//	freopen("sample.out","w",stdout);
	
	for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++) 
	        cin>>a[i][j];
 
	DFS(0); 
	
	//不一定必有解，先按必有解的情况输出 
	cout<<"答案数："; 
	cout<<sum<<endl;
	cout<<"进入DFS次数："; 
	cout<<s<<endl;	
	cout<<"输出次数：";
	cout<<t<<endl;	
	
//	fclose(stdout);
	
	return 0;
 } 
 void shuchu(){
	t++; 
	cout<<"******************"<<endl;
    for(int i=0;i<9;i++){
	    for(int j=0;j<9;j++)
	    	cout<<a[i][j]<<' '; 
        cout<<endl;	
    }
}
