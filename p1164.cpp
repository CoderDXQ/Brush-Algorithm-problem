/*
#include<bits/stdc++.h>
using namespace std;
int n,m; 
int v[105],f[110][10005];
//f[]�洢ĳ�����ѵķ����� 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=0;i<n;i++) f[i][0]=1;//ֻ���i+1����ʱ�ķ��� 
    for(int i=1;i<=n;i++)
       for(int j=1;j<=m;j++)
       {//j����Ǯ�� 
       	   f[i][j]=f[i-1][j];//�̳�ǰi-1���˻���Ϊj�ķ����� 
		   if(j>=v[i]) f[i][j]+=f[i-1][j-v[i]]; 
//�ڲ�ͬ�����µ������ 
	   }
	cout<<f[n][m]<<endl;
	return 0;
 } 
#include<bits/stdc++.h>
using namespace std;
int n,m; 
int v[105],f[10005];
//f[]�洢ĳ�����ѵķ����� 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	f[0]=1;//��Ҫ��ʼ��  j-v[i]=0ʱ����ֻ���i���� 
		for(int i=1;i<=n;i++)//ö�����в�Ʒ 
	    for(int j=m;j>=v[i];j--)
	    {//�ڵ��i���˵�����£�����Ϊj�ķ����� 
	    	f[j]=f[j]+f[j-v[i]]*1;
		}
	cout<<f[m];
	return 0;
 }  
#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,b[105]; 
int v[105]; 
void dfs(int k,int x)
{//k���Ѿ�����Ǯ��x�ǵڼ�����Ʒ 
	if(k>m) return;
	if(k==m){
		sum++;
		return;
	}
	for(int i=x+1;i<=n;i++)
	if(b[i]==0)
	{
		b[i]=1;
		dfs(k+v[i],i);//ѡ��i����Ʒ 
		b[i]=0;
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	dfs(0,0);//???????????????
	cout<<sum;
	return 0;
 } */ 
#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,b[105]; 
int v[105]; 
void dfs(int k,int x)
{//k���Ѿ�����Ǯ��x�ǵڼ�����Ʒ 
	if(k==m){sum++;return;}
	for(int i=x+1;i<=n;i++)
//�����Ǵ�x+1��ʼ������x+1֮ǰ�Ĳ�û�б���Ļᱻ�ظ����ǣ����½����� 
		if (k+v[i]<=m) 
		{
			b[i]=1;
		    dfs(k+v[i],i);
		    b[i]=0;
			}//ѡ��i����Ʒ 
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>v[i];
	dfs(0,0);//???????????????
	cout<<sum;
	return 0;
 } 
