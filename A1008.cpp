#include<stdio.h>
int main()
{
	int i,j,k,n,ting,l;
	long long s=0;
	scanf("%d",&n);
	l=0;
	ting=5*n;//zong=ting+shang+jiang;
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		if(k>l){
		    s=s+(k-l)*6;
		    l=k;
			}
		else
		{
			s=s+(l-k)*4;
			l=k;
		}
	}
	s=s+ting;
	printf("%d\n",s);
}
