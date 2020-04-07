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
/*
int Partition(int a[],int left,int right)
{
	int temp=a[left];
	while(left<right)
	{
		while((left<right)&&(a[right]>temp)) right--;
		a[left]=a[right];
		while((left<right)&&(a[left]<=temp))left++;
		a[right]=a[left];
	}
	a[left]=temp;
	return left;
}
void quickSort(int a[],int left,int right)
{
	int i;
	if(left<right)
	{
		int pos=Partition(a,left,right);
		quickSort(a,left,pos-1);
		quickSort(a,pos+1,right);
	}
}*/
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
	for(i=0;i<n;i++) printf("%d ",a[i]);
	
	
	
	fclose(fp);
	//for(i=0;i<n;i++) printf("%d ",a[i]);
}

