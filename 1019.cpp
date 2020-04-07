#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,max,i,min,s,t;
	int a[4];
	scanf("%d",&n);
	s=n;
	for(i=3;i>=0;i--)
	{
		t=s%10;
		s=s/10;
		a[i]=t;	
	}
	if(n<1000)
	{
		for(i=0;i<4;i++)
		{
			printf("%d",a[i]);
		}
		printf(" - ");
		for(i=0;i<4;i++)
		{
			printf("%d",a[i]);
		}
			printf(" = 0000\n");
	}
	else
	{
	
	while(n!=6174)
	{
		sort(a,a+4,cmp);//从大到小排列 
		max=0;min=0;
		for(i=0;i<4;i++)
		{
			printf("%d",a[i]);
			max=max*10+a[i];
		}
		printf(" - ");
		for(i=3;i>=0;i--)
		{
			printf("%d",a[i]);
			min=min*10+a[i];
		}
		n=max-min;
		if(n==0) {
			printf(" = 0000\n");break;
		}
		else
		{
			s=n;
	        for(i=3;i>=0;i--)
	        {
	      	t=s%10;
		    s=s/10;
	     	a[i]=t;	
         	}
         	printf(" = ");
			for(i=0;i<4;++i)
			{
			printf("%d",a[i]);
		    }
		    printf("\n");
		}
	}
    } 
}
