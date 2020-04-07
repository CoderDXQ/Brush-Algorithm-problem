#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
struct lian
{
	char add[5];
	int data;
	char next[5];
}a[100001];
int main()
{
	int n,k,i,j,kk,t;
	char chu[5];
	lian s;
	char jieshu[5]="-1";
	stack <lian> st;
	lian b[100001];
	FILE *fp;
	fp=fopen("input.txt","r");
	if (fp==NULL) return 0;
	fscanf(fp,"%s %d %d",chu,&n,&k);
	kk=k;
	for(i=0;i<n;++i)
	{
		fscanf(fp,"%s %d %s",&b[i].add,&b[i].data,&b[i].next);
	}
	for(i=0;i<n;++i)
	{
		if(strcmp(b[i].add,chu)==0)
		{
		    k=i;break;	
		}
	}
	j=0;a[j]=b[k];//结构体赋值 
	strcpy(chu,a[j].next);
	while((j<n)&&(strcmp(chu,jieshu)!=0))
	{
		++j;
		for(i=0;i<n;++i)
	    {
		if(strcmp(b[i].add,chu)==0) {k=i;break;	}
	    }
	    a[j]=b[k];strcpy(chu,a[j].next);
	}
	
	j=0;t=0;
	while(j<n)//cun yi
	{
		if(n-j<kk)
		{
			for(i=0;i<n;++i) 
			{
				b[t++]=a[j+i];
			}
			j=n;
		}
		else
		{
			for(i=0;i<kk;++i)
			{
                st.push(a[j]);
				j++;			
			}
			
			while((st.empty()==false))
			{
				b[t++]=st.top();
				st.pop();	
				//printf("%s %d %s &&\n",b[t-1].add,b[t-1].data,b[t-1].next);
			}
			//printf("j=%d\n",j);
			
		}
	}
	
	for(i=0;i<n-1;++i)
	{
		strcpy(b[i].next,b[i+1].add);//strcpy!=strcmp
	}
	
	//printf("%d",k);
	//printf("%s %d %d",chu,n,k);
	for(i=0;i<n;++i)
	{  
		printf("%s %d %s\n",b[i].add,b[i].data,b[i].next);
    }
	

}
