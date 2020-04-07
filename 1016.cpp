#include<stdio.h>
int main()
{
	long long a,b,da,db;
	int i,j,k,aa,bb,ka,kb;
	FILE *fp;
	fp=fopen("input.txt","r");
	if (fp==NULL) return 0;
    fscanf(fp,"%lld %lld %lld %lld",&a,&da,&b,&db);
	ka=0;kb=0;
	while(a>0)
    {
    	aa=a%10;
    	if (aa==da) ka=ka*10+da;
    	a=a/10;
		}	
	while(b>0)
    {
    	bb=b%10;
    	if (bb==db) kb=kb*10+db;
    	b=b/10;
		}
	
	//printf("%lld %lld %lld %lld\n",a,da,b,db);
	
	printf("%d\n",ka+kb);
	
}
