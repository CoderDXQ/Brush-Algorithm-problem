#include<stdio.h>
int main()
{
	int i,j,k;
	int a[10];
	for (i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for (i=1;i<10;i++)
	{
		if (a[i]) {
		a[i]--;
		printf("%d",i);
		break;
		}
	}
	for (i=0;i<10;i++)
	{
		if (a[i]) {
		
		for(j=0;j<a[i];j++) {
		printf("%d",i);}

		}
	}
	printf("\n");
	
}
