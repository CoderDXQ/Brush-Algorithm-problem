#include<bits/stdc++.h>
using namespace std;

int a[9][9];
int sum=0;
bool sign=false;

//只能输出第一次搜索出的正确结果
bool check(int key,int n){
	//检查行
	int j=n/9; 
	for(int i=0;i<9;i++)
	    if(a[j][i]==key) 
	        return false;
	//检查列 
	j=n%9;
	for(int i=0;i<9;i++) {
		if(a[i][j]==key)
		    return false;
	}
	//检查九个小方块
	int x=n/9;//n的行坐标
	int y=n%9;//n的列坐标
	//***最重要的技巧*** 
	x=x/3*3;
	y=y/3*3; //x和y是n所在的小方块最左上角的坐标 
	for(int i=x;i<x+3;i++)
	    for(int j=y;j<y+3;j++)
		    if(a[i][j]==key)
			    return false; 	 
	return true;
}
int DFS(int n){//把棋盘标号，n是二维棋盘的一维序号 
	if(n>80){//此时说明找到了 
		sign=true;//信号量 说明找到了 
		return 0;
	}
	if(a[n/9][n%9]!=0){
		DFS(n+1);
	}
	else{
		for(int i=1;i<=9;i++){
			if(check(i,n)){
			    a[n/9][n%9]=i;
				if(n<=80) DFS(n+1);
				//这个if用于在找到一种解法之后的回溯过程中防止棋盘复原 
			/*	if(sign){
					return 0;	
				}	*/
				//只有没找到的情况才回溯，如果不加下面的if语句，在递归回退的过程中填好的空又变回去了 
				if(sign==false) a[n/9][n%9]=0;//回溯 
			}
		}	
	}	 
	return 0;
} 

int main()
{
	for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++) 
	        cin>>a[i][j];
 
	DFS(0); 
	//不一定必有解，先按必有解的情况输出 
	cout<<"******************"<<endl;
    for(int i=0;i<9;i++){
	    for(int j=0;j<9;j++)
	    	cout<<a[i][j]<<' '; 
        cout<<endl;	
    }
    system("pause");
	return 0;
 } 
