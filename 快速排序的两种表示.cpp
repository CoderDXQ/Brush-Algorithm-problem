#include<bits/stdc++.h>
using namespace std;
int a[100005];
void quicksort(int left,int right)
{
    int i,j,base,t;
	i=left;j=right;
	base=a[(i+j)/2];//分治思想，有效应对有序数列的排序 
	while(i<=j)//从小到大 
	{
		while(a[j]>base) j--;
		while(a[i]<base) i++;
		if(i<=j)
		{
			t=a[j];
		    a[j]=a[i];
		    a[i]=t;
		    j--;i++;
		}
	}
	if(left<j)quicksort(left,j);
	if(i<right)quicksort(i,right);	
}

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	quicksort(1,n);
	//Quicksort(a[1],1,n);
	for(i=1;i<=n-1;i++) printf("%d ",a[i]);
	printf("%d\n",a[n]);
}
 
