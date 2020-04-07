#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

void quickSort(int a[],int left,int right)
{
	int temp,i,j;
	i=left;j=right;
	if(left<right)
	{
		 temp=a[left];
	    while(i<j)
	    {
		while((i<j)&&(a[j]>temp)) j--;
		if(i<j)
		{
		a[i]=a[j];i++;
	    }
		while((i<j)&&(a[i]<=temp)) i++;
		if(i<j)
		{
		a[j]=a[i];j--;
	    }
	}
	a[i]=temp; 
	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
	}
}
int main()
{
	int i,j,k,s;
	int a[10001];
	
	int n,p;
	FILE *fp;
	fp=fopen("input.txt","r");
	if(fp==NULL) return 0;//C语言中的等号是两个等号 
	fscanf(fp,"%d %d",&n,&p);
	for(i=0;i<n;i++) fscanf(fp,"%d",&a[i]);
	quickSort(a,0,n-1);
	//for(i=0;i<n;i++) printf("%d ",a[i]);
	k=-1;
	for(i=0;i<n-1;i++)
	{
		for(j=n-1;j>i;j--)
		    {
		    	if(a[j]<=a[i]*p)
		    	{
		    		if (k<j-i+1) k=j-i+1;
		    		break;
				}
			}
	}
	printf("%d\n",k);
	fclose(fp);
	//for(i=0;i<n;i++) printf("%d ",a[i]);
}

