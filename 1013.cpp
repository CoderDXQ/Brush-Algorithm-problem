#include<stdio.h>
#include<math.h>
bool a[10001]={1};
void dabiao()
{
	int k,l,j;
	for(l=4;l<10001;++l)
	{
		k=sqrt(l);
		for(j=2;j<=k;++j)
		{
			if(l%j==0) {
			a[l]=false;
			break;}
		}
	}	
}
int main()
{
	
	int m,n,count,i,countt,s;
	s=0;
	int b[10001];
	count=0;countt=0;
	for(i=0;i<=10001;++i) {
	a[i]=true;b[i]=0;}
	dabiao();
	for (i=0;i<=10000;i++)
	{
		if (a[i]==true)  {b[s]=i;s++;}
	}
	printf("%d",s);
	//scanf("%d %d",&m,&n);
	i=0;

	/*for(i=1;i<200001;++i)
	{
		if (a[i]==true)
		{
			count++;
			if((count<=n+1)&&(count>=m+1))
			{
			countt++;
			if (countt%10==0) printf("%d\n",i);
			else if (count!=n+1) printf("%d ",i);
			    else printf("%d",i);
			}
		}
		
		if (count==n+1) {printf("\n");break;}
	}*/
	printf("%d",a[44]);

 } 
