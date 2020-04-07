#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
	long n;
	memset(a,0,sizeof(a));
	scanf("%d\n",&n);
	for(long i=1;i<=n;i++) scanf("%d",&a[i]);
    long maxx=0;
	for(long i=1;i<=n;i++){
//每个数都可能是最小值，那么在此数为最小值得情况下，向左右两侧最大化扩展子序列即可 
		long sum=a[i],min=a[i],left=i-1,right=i+1;
		while(left>=1 && a[left]>=min){//向左扩展 
			sum+=a[left];
			left--;
		}
		while(right<=n && a[right]>=min){//向右扩展 
			sum+=a[right];
			right++;
		}
		maxx=max(maxx,a[i]*sum);
	}
	printf("%d\n",maxx);
} 
