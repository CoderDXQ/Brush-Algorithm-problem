#include<stdio.h>
#include<string.h>
int main()
{
	int i,la,lb,min,z;
	char a[4][60];
	char zhou[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	FILE *fp=fopen("input.txt","r");
	if (fp==NULL) {return 0;}
	for (i=0;i<4;++i) {fscanf(fp,"%s",a[i]);}
	
	
	la=strlen(a[0]);
	lb=strlen(a[1]);
	if (la<lb) min=la;
	else min=lb;
	
	i=0;	
	while (i<min)
	{
		if((a[0][i]==a[1][i])&&(a[0][i]>='A')&&(a[0][i]<='G'))
		{
			z=a[0][i]-'A';
		    printf("%s ",zhou[z]);
		    break;
		}
		i++;	
	}
	i++;
	while (i<min)
	{
		if((a[0][i]==a[1][i]))
		{
			if((a[0][i]>='A')&&(a[0][i]<='N'))
			{	
			z=a[0][i]-'A';
		    printf("%d:",z+10);
		    break;
		    }
		    if((a[0][i]>='0')&&(a[0][i]<='9'))
			{	
			z=a[0][i]-'0';
		    printf("%02d:",z);
		    break;
		    }
		}
		i++;	
	}
	
	
	la=strlen(a[2]);
	lb=strlen(a[3]);
	if (la<lb) min=la;
	else min=lb;
	
	i=0;	
	while (i<min)
	{
		if((a[2][i]==a[3][i])&&(((a[2][i]>='a')&&(a[2][i]<='z'))||((a[2][i]>='A')&&(a[2][i]<='Z'))))
		{
		    printf("%02d\n",i);
		    break;
		}
		i++;	
	}
}

/*
#include<stdio.h>
#include<string.h>
int main()
{
	int i,la,lb,min,z;
	char a[4][60];
	char zhou[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	for (i=0;i<4;++i) scanf("%s",a[i]);
	
	
	la=strlen(a[0]);
	lb=strlen(a[1]);
	if (la<lb) min=la;
	else min=lb;
	
	i=0;	
	while (i<min)
	{
		if((a[0][i]==a[1][i])&&(a[0][i]>='A')&&(a[0][i]<='G'))
		{
			z=a[0][i]-'A';
		    printf("%s ",zhou[z]);
		    break;
		}
		i++;	
	}
	i++;
	while (i<min)
	{
		if((a[0][i]==a[1][i]))
		{
			if((a[0][i]>='A')&&(a[0][i]<='N'))
			{	
			z=a[0][i]-'A';
		    printf("%02d:",z+10);
		    break;
		    }
		    if((a[0][i]>='0')&&(a[0][i]<='9'))
			{	
			z=a[0][i]-'0';
		    printf("%02d:",z);
		    break;
		    }
		}
		i++;	
	}
	
	
	la=strlen(a[2]);
	lb=strlen(a[3]);
	if (la<lb) min=la;
	else min=lb;
	
	i=0;	
	while (i<min)
	{
		if((a[2][i]==a[3][i])&&(((a[2][i]>='a')&&(a[2][i]<='z'))||((a[2][i]>='A')&&(a[2][i]<='Z'))))
		{
		    printf("%02d\n",i);
		    break;
		}
		i++;	
	}
}*/
