#include<bits/stdc++.h>
using namespace std;
#define FOR(i,n,m) for(int i=n;i<=m;i++)//宏定义 
int n,a[110],c[110],p,ans; 
int main()
{
	 scanf("%d",&n);
	 FOR(i,1,n) scanf("%d",&a[i]);
	 FOR(i,1,n) c[i]=c[i-1]+a[i];
	 p=c[n]/n;
	 FOR(i,1,n-1) if(p*i!=c[i]) ans++;//从左到右依次保证完成挪动 
	 printf("%d\n",ans);
	return 0;
}
