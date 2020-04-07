#include<stdio.h>

int main()
{
	long long a,b,c;
	int i,t;
	scanf("%d",&t);
	//printf("%d",t);
	for(i=0;i<t;i++)
    {
    	scanf("%lld %lld %lld",&a,&b,&c);
    	//printf("%lld %lld %lld",a,b,c);
    	if (a+b>c)
    	
    		printf("Case #%d: true\n",i+1);
		
		else
		
			printf("Case #%d: false\n",i+1);
		
    	
	}	
	
}
