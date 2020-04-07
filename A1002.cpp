#include<cstdio>
int main()
{
	float f;
	float a[1001]={0};
	int i,n,k;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d %f",&n,&f);
		a[n]=a[n]+f;
	}
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		scanf("%d %f",&n,&f);
		a[n]=a[n]+f;
	}
	k=0;
	for(i=1000;i>=0;i--)
	{
	    if(a[i]!=0) k++;
	}
	printf("%d",k);
	for(i=1000;i>=0;i--)
	{
	    if(a[i]!=0)	printf(" %d %.1f",i,a[i]);
	}
	printf("\n");
}
