//�����Σ����䣩��̬�滮�����й��������������õݹ����ǰ�� 
#include<bits/stdc++.h>
using namespace std;
int n,v[39],f[47][47],i,j,k,root[49][49];
void print(int l,int r)
{
	if(l>r) return;//��ֹջ��� 
	if(l==r) 
	{
	    cout<<l<<' ';
		return;
	}
	cout<<root[l][r]<<' ';
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);//��Ŀ�涨�����������123456...n 
 } 
 int main()
 {
 	cin>>n;
    for(i=1;i<=n;i++) cin>>v[i];
	for(i=1;i<=n;i++) 
	{
	    f[i][i]=v[i];
		f[i][i-1]=1;
	}//����DPȨֵ����ĳ�ʼ��
	for(i=n;i>=1;i--)//i�����ǵ��򣬱�֤����Խ��Խ�� 
	   for(j=i+1;j<=n;j++)	
	      for(k=i;k<=j;k++){//k���������ε� 
	      	if(f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k]){
	      		f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
	      		root[i][j]=k;//���� 
			  }
		  } 
	cout<<f[1][n]<<endl;
	print(1,n);
	return 0;
 }
