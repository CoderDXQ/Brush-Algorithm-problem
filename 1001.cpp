#include<stdio.h>
using namespace std;
int main()
{
	int n,k;
	k=0;
	scanf("%d",&n);
	
	while(n!=1)
{
	
	if(n%2==0)
	    n=n>>1;
	else
	    n=(3*n+1)/2;
	k++;
	
}
    printf("%d\n",k);
	
}
