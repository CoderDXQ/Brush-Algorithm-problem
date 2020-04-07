#include<stdio.h>
void quickSort(int a[],int left,int right)
{
	int temp,i,j;
	i=left;j=right;
	if(left<right)
	{
		 temp=a[left];
	    while(i<j)
	    {
		while((i<j)&&(a[j]>temp)) j--;
		if(i<j)
		{
		a[i]=a[j];i++;
	    }
		while((i<j)&&(a[i]<=temp)) i++;
		if(i<j)
		{
		a[j]=a[i];j--;
	    }
	}
	a[i]=temp; 
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
	}
}
int main()
{
	int i,j,k;
	int a[100001];
	long long n;
	long long p;
	scanf("%lld %lld",&n,&p);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	quickSort(a,0,n-1);
	//for(i=0;i<n;i++) printf("%d ",a[i]);
	k=0;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>=i;j--)
		    {
		    	if(a[j]<=a[i]*p)
		    	{
		    		if (k<j-i+1) k=j-i+1;
		    		break;
				}
			}
	}
	printf("%d\n",k);
	//for(i=0;i<n;i++) printf("%d ",a[i]);
}

