#include<stdio.h>
#include<string.h>

int main()
{
	char a[1000];
	int q[1000];
	int b,i,j,k,r,len,s;
	FILE *fp;
	fp=fopen("input.txt","r");
	if (fp==NULL) return 0;
	fscanf(fp,"%s %d",a,&b);
	//for(i=0;i<1001;i++) q[i]=11;
	len=strlen(a);
	i=0;s=a[0]-'0';j=0;
	while(i<len)
	{
			//printf("%d &&%d\n",s,i);
		if(s<b) {
			s=s*10+a[++i]-'0'; 
			if (s<b&&i<len-1) printf("0");
		}
		else
		{
			//q[j++]=s/b;
			printf("%d",s/b);
			s=s%b;
			if(i==len-1) printf(" %d\n",s);
		}
	//printf("[%d]",s);
	}
	
//	printf("   %s %d %d\n",a,b,s);
//	printf("%d %d %d\n",q[3],b,len);
}
