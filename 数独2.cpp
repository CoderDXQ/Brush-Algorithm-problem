#include<bits/stdc++.h>
using namespace std;

int a[9][9];
int sum=0;
bool sign=false;

//ֻ�������һ������������ȷ���
bool check(int key,int n){
	//�����
	int j=n/9; 
	for(int i=0;i<9;i++)
	    if(a[j][i]==key) 
	        return false;
	//����� 
	j=n%9;
	for(int i=0;i<9;i++) {
		if(a[i][j]==key)
		    return false;
	}
	//���Ÿ�С����
	int x=n/9;//n��������
	int y=n%9;//n��������
	//***����Ҫ�ļ���*** 
	x=x/3*3;
	y=y/3*3; //x��y��n���ڵ�С���������Ͻǵ����� 
	for(int i=x;i<x+3;i++)
	    for(int j=y;j<y+3;j++)
		    if(a[i][j]==key)
			    return false; 	 
	return true;
}
int DFS(int n){//�����̱�ţ�n�Ƕ�ά���̵�һά��� 
	if(n>80){//��ʱ˵���ҵ��� 
		sign=true;//�ź��� ˵���ҵ��� 
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
				//���if�������ҵ�һ�ֽ֮ⷨ��Ļ��ݹ����з�ֹ���̸�ԭ 
			/*	if(sign){
					return 0;	
				}	*/
				//ֻ��û�ҵ�������Ż��ݣ�������������if��䣬�ڵݹ���˵Ĺ�������õĿ��ֱ��ȥ�� 
				if(sign==false) a[n/9][n%9]=0;//���� 
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
	//��һ�����н⣬�Ȱ����н�������� 
	cout<<"******************"<<endl;
    for(int i=0;i<9;i++){
	    for(int j=0;j<9;j++)
	    	cout<<a[i][j]<<' '; 
        cout<<endl;	
    }
    system("pause");
	return 0;
 } 
