#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
	int len,i,j,k,s;
	string str;
	string aa;
    cin>>str;
	len=str.length();
	if(str[0]=='-')printf("%c",str[0]);
	i=1;
	while(str[i]!='E') i++;
	i++;
    j=i;j++;
    s=0;
    for(j;j<len;j++)
    {
    	s=s*10+(str[j]-'0');
	}

	j=1;
	if(s==0)
	{
		while(str[j]!='E')
		{
			printf("%c",str[j]);
			j++;
		}
		
	}
	else
	{
	    if (str[i]=='-')//指数为负
	    {
	        printf("0.");
			s--;
			for(k=0;k<s;k++) printf("0");
			while(str[j]!='E')
		    {
			if (str[j]!='.')printf("%c",str[j]);
			j++;
		    }
				
    	}
	    else//指数为正
	    {
	    	s++;
		    while(str[j]!='E')
		    {
		    	if(s==0) printf(".");
		    	if (str[j]!='.')
				{
				  printf("%c",str[j]);s--;
			    }
		    	j++;
		    	
			}
			
			if(s>0)
			{
				for(k=0;k<s;k++) printf("0");
			}
		    
	    }
    }
    printf("\n");
}
