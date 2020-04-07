#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,c,num=0;
	scanf("%d %d %d",&n,&m,&c);
	
	for(int i=1;i<=n;i++){
		int s;
		int bj[c];
		memset(bj,0,sizeof(bj));
		while(scanf("%d",&s)!=EOF){
			bj[s]++;
		}
		for(int j=0;j<=c;j++){
			if(bj[j]>1) num++;
		}
		
	}
	scanf("%d\n",num); 	
} 
