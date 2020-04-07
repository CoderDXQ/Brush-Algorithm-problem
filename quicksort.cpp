#include<stdio.h>

//void quickSort(int arr[],int low,int high);
int main()
{
    
    int i;	
    int a[10];
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
    quickSort(a,0,9);
    
    for(i=0;i<10;i++)
        printf("%d ",a[i]);
	
}
//int 
int Partition(int arr[],int low,int high)
{
	int i=low;
	int j=high;
	int tmp=arr[i];
	while(i<j)
	{
		while(i<j && arr[j]<=tmp) j--;
		arr[i]=arr[j];
		while(i<j && arr[i]>=tmp) i++;
		arr[j]=arr[i];
	}
	arr[i]=tmp;
	return i;
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int key;
		key=Partition(arr,low,high);
		quickSort(arr,low,key-1);
		quickSort(arr,key+1,high);
	}
}
