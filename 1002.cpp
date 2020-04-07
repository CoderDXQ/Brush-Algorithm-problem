#include<stdio.h>

int main()
{
	char A[102];
	int B[4]={0,0,0,0};
	
	int i,s,k;
	s=0;
	scanf("%s",&A);
	for (i=0;A[i]!='\0';++i)
	    s+=A[i]-'0';
	    
	k=-1;
    while(s!=0)
    {
    	++k;
    	B[k]=s%10;
    	s=s/10;
	}
	for (;k>=0;--k)
	{
		i=B[k];
		if (i==0) printf("ling");
    	if (i==1) printf("yi");
    	if (i==2) printf("er");
    	if (i==3) printf("san");
    	if (i==4) printf("si");
    	if (i==5) printf("wu");
    	if (i==6) printf("liu");
    	if (i==7) printf("qi");
    	if (i==8) printf("ba");
    	if (i==9) printf("jiu");
    	if(k>0) printf(" ");
	}	
}
