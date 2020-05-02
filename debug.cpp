#include <bits/stdc++.h>
using namespace std;

void quicksort(int A[],int l,int r){
   int m=l;
   for(int i=l;i<r;i++){
      if(A[i]<A[r]){
         swap(A[i],A[m]);
         ++m;
      }
   }
   swap(A[m],A[r]);
   if(m>l+1)quicksort(A,l,m-1);
   if(m<r-1)quicksort(A,m+1,r);
}

int main(){
   int A[10];
   for(int i=0;i<10;i++) A[i]=10-i;
   for(int i=0;i<10;i++) cout<<A[i]<<' ';
   cout<<endl;
   quicksort(A,0,10-1);
   for(int i=0;i<10;i++) cout<<A[i]<<' ';
}