#include<bits/stdc++.h>
using namespace std;
int v[65][3],p[65][3];//同时存储主件和附件的(价格)与(重要度与价格的乘积） 
int f[32005];//DP数组 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){//输入处理 
		int vv,pp,qq;
		cin>>vv>>pp>>qq;
		if(!qq)//主件 
		{v[i][0]=vv;p[i][0]=pp*vv;}
		else//附件1 
		{if(v[qq][1]==0){v[qq][1]=vv;p[qq][1]=pp*vv;}
			else{v[qq][2]=vv;p[qq][2]=pp*vv;}//附件2 
	}
	}//有些v[i] p[i]是空的 
	for(int i=1;i<=m;i++)
	    if(v[i][0]>0){//剪枝 
	    for(int j=n;j>=v[i][0];j--)
		{//枚举各种购买方案 
		    if(j>=v[i][0]+v[i][1]+v[i][2])//购买主件+两个附件 
			    f[j]=max(f[j],f[j-v[i][0]-v[i][1]-v[i][2]]+p[i][0]+p[i][1]+p[i][2]);
			if(j>=v[i][0]) f[j]=max(f[j],f[j-v[i][0]]+p[i][0]);//购买主件
			if(j>=v[i][0]+v[i][1])//购买主件+第一个附件
			    f[j]=max(f[j],f[j-v[i][0]-v[i][1]]+p[i][0]+p[i][1]);
			if(j>=v[i][0]+v[i][2]) //购买主件+第二个附件
			    f[j]=max(f[j],f[j-v[i][0]-v[i][2]]+p[i][0]+p[i][2]);
			if(j>=v[i][0]+v[i][1]+v[i][2])//购买主件+两个附件 
			    f[j]=max(f[j],f[j-v[i][0]-v[i][1]-v[i][2]]+p[i][0]+p[i][1]+p[i][2]);
		}
     }		 
	cout<<f[n]<<endl;
	return 0;
} 
