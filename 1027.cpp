#include <stdio.h>
int main()
{
	int i,j,n,k,s,N;
	char a;
    scanf("%d %c",&N,&a);
    n=0;
    while(2*n*n-1<=N)
    {
    	n++;
	}
	n--;
	if(N==1) { printf("%c\n",a);
	}
	else
	{
	
	for(i=0;i<n;++i)
	{
		for(j=0;j<i;j++) printf(" ");
		k=2*n-2*i-1;
		for(j=0;j<k;j++) printf("%c",a);
		for(j=0;j<i;j++) printf(" ");
		printf("\n");
	}	
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<i;j++) printf(" ");
		k=2*n-2*i-1;
		for(j=0;j<k;j++) printf("%c",a);
		for(j=0;j<i;j++) printf(" ");
		printf("\n");
	}
	
}
    if (N==0) printf("0\n");
	else printf("%d\n",N-2*n*n+1);
}
