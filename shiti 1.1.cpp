#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
}nn[500005];

bool cmp(node a,node b){
	if(a.y==b.y) return a.x<b.x;
	else return a.y>b.y;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %d",&nn[i].x,&nn[i].y);
	sort(nn,nn+n,cmp);
    int xmin=0; 
	for(register int i=0;i<n;i++){
        if(nn[i].x>xmin) {
        	xmin=nn[i].x;
		    printf("%d %d\n",nn[i].x,nn[i].y);	
	    }
	}
} 
