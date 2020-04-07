#include<stdio.h>
int main()
{
	long long i,j,d,n;
	scanf("%lld %lld",&n,&d);
	int a[50];
	int k=0;
	k=0;
	while(n>0)
	{
        a[k]=n%d;
        n=n/d;
        k++;
	}
	i=0;j=k-1;
	while(a[i]==a[j])
	{
		i++;j--;
	}
	
	if(j<i) 
	{
		printf("Yes\n");
		for(i=0;i<k-1;i++) printf("%d ",a[i]);
		printf("%d\n",a[k-1]);
	}
	else
	{
		printf("No\n");
		for(i=k-1;i>0;i--) printf("%d ",a[i]);
		printf("%d\n",a[0]);
	}
}
