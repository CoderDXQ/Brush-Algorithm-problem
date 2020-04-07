#include<stdio.h>
int main()
{
	int hh,mm,ss,k;
	double c1,c2;
	scanf("%lf %lf",&c1,&c2);
	
	k=int((c2-c1)/100+0.5);
	
	hh=k/3600;
	if (hh==0)  printf("00:");
	else{
	
	if (hh<10)
	{
		printf("0");
		printf("%d:",hh);
	}
	else
	    printf("%d:",hh);}
	
	k=k%3600;
	mm=k/60;
    if (mm==0) printf("00:");
	else {
	
	if (mm<10)
	{
		printf("0");
		printf("%d:",mm);
	}
	else
	    printf("%d:",mm);}



	ss=k%60;
	if (ss==0) printf("00\n");
	else 
	{
	if (ss<10)
	{
		printf("0");
		printf("%d\n",ss);
	}
	else
	    printf("%d\n",ss);
    } 
}
