#include<stdio.h>
int main()
{
	int i,a1,n,a2,a3,a5,s,k,m,j;
	bool A1,A2,A3,A4,A5;
	double a4;
	A1=false;A2=false;A3=false;A4=false;A5=false;
	a5=-1;a2=0;a3=0;a4=0;a1=0;k=1;m=0;
    scanf("%d",&j);
    for(i=0;i<j;++i)
    {
    	
    	scanf("%d",&n);
		s=n%5;
    	if (s==1) {
    		a2=a2+k*n;
    		k=k*(-1);
    		A2=true;
		}
		if (s==2) {
			a3++;
			A3=true;
		}
		if (s==3) {
			a4=a4+n;
			m++;
			A4=true;
		}
		if (s==4) {
			if (a5<n) a5=n;
			A5=true;
		}
		if (s==0) {
			if(n%10==0) {
			a1=a1+n;
			A1=true;}
		}
	}	
		
	if (A1==true) printf("%d ",a1);
	else printf("N ");
	if (A2==true) printf("%d ",a2);
	else printf("N ");
	if (A3==true) printf("%d ",a3);
	else printf("N ");
	if (A4==true) printf("%.1f ",a4/m);
	else printf("N ");
	if (A5==true) printf("%d",a5);
	else printf("N"); //注意最后一个输出时不能有空格了 
	printf("\n");
}
