#include<bits/stdc++.h>
using namespace std;

int a[9][9];
int sum=0;
int s=0;
int t=0;
//void shuchu(); 
//���������ȷ������޽������� 
bool check(int key,int n){
	//��
	int j=n/9; 
	for(int i=0;i<9;i++)
	    if(a[j][i]==key) 
	        return false;
	//�� 
	j=n%9;
	for(int i=0;i<9;i++) {
		if(a[i][j]==key)
		    return false;
	}
	//�Ÿ�С����
	int x=n/9;//n��������
	int y=n%9;//n��������
	//����Ҫ�ļ��� 
	x=x/3*3;//n���ڵ�С���������Ͻǵ����� 
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
				a[n/9][n%9]=0;//���� 
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
	
	//��һ�����н⣬�Ȱ����н�������� 
	cout<<"������"; 
	cout<<sum<<endl;
	cout<<"����DFS������"; 
	cout<<s<<endl;	
	cout<<"���������";
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
