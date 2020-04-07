#include<bits/stdc++.h>
using namespace std;

int n,a[500010],c[500010];
long long ans=0;
void msort(int b,int e)
{
	if(b>=e) return;
	int mid=(b+e)/2,i=b,j=mid+1,k=b;
	msort(b,mid),msort(mid+1,e);
	while(i<=mid&&j<=e)
	    if(a[i]<=a[j]) c[k++]=a[i++];
	    else
	        c[k++]=a[j++],ans+=mid-i+1;
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=e)
        c[k++]=a[j++];
    //c数组暂存该段归并排序的结果
	for(int l=b;l<=e;l++)
	    a[l]=c[l]; 
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	msort(1,n);
	cout<<ans;
	return 0;
}
