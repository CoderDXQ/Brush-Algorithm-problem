#include<stdio.h>
#include<string.h>

int main()
{
	char xm[11];
	char xh[11];
	char xmm[11];
	char xhh[11];
	char xmmm[11];
	char xhhh[11];
	int min,max,i,m,cj;
	max=-1;
	min=101;//这两个初始赋值非常重要 
	scanf("%d",&m);
	for(i=1;i<=m;++i)
	{
		scanf("%s %s %d",&xm,&xh,&cj);
		if (max<cj)
		{
			max=cj;
			strcpy(xmm,xm);
			strcpy(xhh,xh);
		}
		if(min>cj)
		{
			min=cj;
			strcpy(xmmm,xm);
			strcpy(xhhh,xh);
		}
	}
	printf("%s %s\n",xmm,xhh);
	printf("%s %s\n",xmmm,xhhh);
}
