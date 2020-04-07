#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000];
	int q[1000];
	int b,i,j,k,r,len,s;
	scanf("%s %d",a,&b);
	len=strlen(a);
	i=0;s=a[0]-'0';j=0;
	while(i<len)
	{
		if(s<b) {
			s=s*10+a[++i]-'0'; 
		}
		else
		{
			printf("%d",s/b);
			s=s%b;
			if(i==len-1) printf(" %d\n",s);
		}	
	}	
}
