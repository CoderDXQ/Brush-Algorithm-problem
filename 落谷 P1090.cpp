#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	while(1)
	{
		int j=1;
		while(a[j]==0) j++;//过滤空堆
		if(j==n) break;
		else
		{
		    a[j]+=a[j+1];
			sum+=a[j];
			for(int i=j+1;i<n;i++) a[i]=a[i+1];//后堆前移	
			n--;//堆数减一 
		 } 
		 for(int i=j;i<n;i++)
		 {//只有一个元素无序且位置已知的冒泡排序 
		 	if (a[i]>a[i+1]) swap(a[i],a[i+1]);
		 }
	}
	cout<<sum;
	return 0;
}
