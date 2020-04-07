#include<stdio.h>

int main()
{
	int i,j,k;
	float w,t,l;
	float a[3];
	for(i=0;i<3;i++)
	{
		scanf("%f%f%f",&w,&t,&l);
		if(w>t&&w>l) {
		printf("W ");a[i]=w;}
		if(t>w&&t>l) {
		printf("T ");a[i]=t;}
		if(l>w&&l>t) {
		printf("L ");a[i]=l;
	}}
	t=1;
	for(i=0;i<3;i++)
	{
		t=t*a[i];
	}
	t=(t*0.65-1)*2;
	printf("%.2f\n",t);
	
	
}
