#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	int a[300005];
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int kk=1;kk<=m;kk++){
		int l,r,k,num=0;
		scanf("%d %d %d",&l,&r,&k);
		for(int i=l;i<=r;i++){
			if(a[i]==k) num++;
		}
		printf("%d\n",num);
	}
} 
