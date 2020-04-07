#include<stdio.h>
int main()
{
	int n,d,i,j,k;
	float dj[1000];
	float max=-999999.99;
	float s=0;
	float kc[1000];
	float zj[1000];
	scanf("%d %d",&n,&d);
	for (i=0;i<n;++i)
	{
		scanf("%f",&kc[i]);
	}
	for (i=0;i<n;++i)
	{
		scanf("%f",&zj[i]);
		dj[i]=zj[i]/kc[i];
	}
	while(d>0)
	{
		max=-999999.99;
		for(j=0;j<n;++j)
		{
		    if (max<dj[j])
			{
				k=j;max=dj[j];
				}	
		}
		if(d>kc[k]) {
			d=d-kc[k];s=s+zj[k];
		}
		else
		{
			s=s+dj[k]*d;d=d-kc[k];
		}
		dj[k]=0;
	}
	printf("%.2f\n",s);	
}
