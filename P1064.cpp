#include<bits/stdc++.h>
using namespace std;
int v[65][3],p[65][3];//ͬʱ�洢�����͸�����(�۸�)��(��Ҫ����۸�ĳ˻��� 
int f[32005];//DP���� 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){//���봦�� 
		int vv,pp,qq;
		cin>>vv>>pp>>qq;
		if(!qq)//���� 
		{v[i][0]=vv;p[i][0]=pp*vv;}
		else//����1 
		{if(v[qq][1]==0){v[qq][1]=vv;p[qq][1]=pp*vv;}
			else{v[qq][2]=vv;p[qq][2]=pp*vv;}//����2 
	}
	}//��Щv[i] p[i]�ǿյ� 
	for(int i=1;i<=m;i++)
	    if(v[i][0]>0){//��֦ 
	    for(int j=n;j>=v[i][0];j--)
		{//ö�ٸ��ֹ��򷽰� 
		    if(j>=v[i][0]+v[i][1]+v[i][2])//��������+�������� 
			    f[j]=max(f[j],f[j-v[i][0]-v[i][1]-v[i][2]]+p[i][0]+p[i][1]+p[i][2]);
			if(j>=v[i][0]) f[j]=max(f[j],f[j-v[i][0]]+p[i][0]);//��������
			if(j>=v[i][0]+v[i][1])//��������+��һ������
			    f[j]=max(f[j],f[j-v[i][0]-v[i][1]]+p[i][0]+p[i][1]);
			if(j>=v[i][0]+v[i][2]) //��������+�ڶ�������
			    f[j]=max(f[j],f[j-v[i][0]-v[i][2]]+p[i][0]+p[i][2]);
			if(j>=v[i][0]+v[i][1]+v[i][2])//��������+�������� 
			    f[j]=max(f[j],f[j-v[i][0]-v[i][1]-v[i][2]]+p[i][0]+p[i][1]+p[i][2]);
		}
     }		 
	cout<<f[n]<<endl;
	return 0;
} 
