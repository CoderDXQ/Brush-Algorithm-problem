/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,s=0;
	cin>>n>>m;
	bool visit[200]={0};
	for(int k=0;k<n;k++){
	    for(int i=1;i<=m;i++){//数m个人 
	    	s++;
			if(s>n) s=1;//实现循环机制 
	    	if(visit[s]==1) i--;
		}	
		cout<<s<<' '; 
		visit[s]=1;
	}
	return 0;
}

#include<cstdio>
using namespace std;
int main()
{
	int n,m,s=0;
	scanf("%d%d",&n,&m);
	bool visit[200]={0};
	for(int k=0;k<n;k++){
	    for(int i=0;i<m;i++){if(++s>n)s=1;if(visit[s])i--;}	
		printf("%d ",s);visit[s]=true;
	}
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,zhi=0,ren=0;;
	long long step=0;
	cin>>n>>m;
	bool visit[2000]={0};
	        while(1)
	        {	
	        	zhi++;
	        	if(zhi>n) zhi=zhi%n;
	        	if(visit[zhi]==0) 
				{
				    step++;
			    }
			
			if(step==m&&visit[zhi]==0)
			{
			visit[zhi]=1;
			ren++;
			step=0;
			if(ren<n)cout<<zhi<<' ';
			else cout<<zhi<<endl;
			if(ren==n) break;
		    }
		   }
		   return 0;
}






