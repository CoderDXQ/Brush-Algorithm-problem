#include<bits/stdc++.h>
using namespace std;
int i,n,v[49],dp[49][49],root[49][49];
int ser(int l,int r){
	if(dp[l][r]>0) return dp[l][r];// dp[l][r]�Ѿ��������ӽṹ 
	//if(l==r) return v[l];//���Ҷ�ӽڵ����������м������� 
	if(r<l) return 1;//����������Ҷ˵����� 
	for(int i=l;i<=r;i++){
		int p=ser(l,i-1)*ser(i+1,r)+dp[i][i];
//������������·��ݹ飬��������ӽṹ֮�������ϼ��� 
		if(p>dp[l][r]){//���� 
		    dp[l][r]=p;
		    root[l][r]=i;
	}
	}
	return dp[l][r];
//����֮ǰδ������������ӽṹ��ֵ���״μ��������������ӽṹ��ֵ�� 
} 
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
	for(i=1;i<=n;i++) dp[i][i]=v[i];
	printf("%d\n",ser(1,n));
	print(1,n);
	return 0;
}
