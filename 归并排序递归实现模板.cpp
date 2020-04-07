#include<bits/stdc++.h>
using namespace std;
int A[100];
const int maxn=100;
void merge(int A[],int L1,int R1,int L2,int R2){
	int i=L1,j=L2;    //【L1，R1】，【L2，R2】是每次要合并的两个序列 
	int temp[maxn],index=0;
	while(i<=R1&&j<=R2){
		if(A[i]<=A[j]){
			temp[index++]=A[i++];
		}else{
			temp[index++]=A[j++];
		}
	}//index是temp数组的下标 ，也是本次合并后的序列相对于A数组的偏移值 
	while(i<=R1) temp[index++]=A[i++];
	while(j<=R2) temp[index++]=A[j++];
	for(i=0;i<index;i++){
		A[L1+i]=temp[i];//L1是偏移值 
	}
}

void mergeSort(int A[],int left,int right){
    if(left<right){//限制每次进入merge的只有两个序列，每个序列两个元素 
    	int mid=(left+right)/2;
    	mergeSort(A,left,mid);
    	mergeSort(A,mid+1,right);//mergeSort不停地划分区间 
    	merge(A,left,mid,mid+1,right);//合并 
	}	
}

int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++) cin>>A[i];
	cout<<endl;
	mergeSort(A,1,n);
	for(i=1;i<=n;i++) cout<<A[i]<<' ';
}
