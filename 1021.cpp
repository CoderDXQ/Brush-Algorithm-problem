#include<stdio.h>
#include<cstring>
int main()
{
	int i,len,k;
	char a[1001];
	int b[10];
	scanf("%s",&a);
	for(i=0;i<10;i++) b[i]=0;
	len=strlen(a);
	for (i=0;i<len;++i)
	{
		k=a[i]-'0';
		b[k]++;
	}
	for (i=0;i<10;++i)
	{
		if(b[i]) printf("%d:%d\n",i,b[i]);
	}

}
