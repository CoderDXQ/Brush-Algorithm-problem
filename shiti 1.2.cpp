#include<bits/stdc++.h>
using namespace std;

int a[500005];

int main(){
	long n;
	memset(a,0,sizeof(a));
	scanf("%d\n",&n);
	for(long i=1;i<=n;i++) scanf("%d",&a[i]);
    long maxx=0;
	for(long i=1;i<=n;i++){
//ÿ��������������Сֵ����ô�ڴ���Ϊ��Сֵ������£����������������չ�����м��� 
		long sum=a[i],min=a[i],left=i-1,right=i+1;
		while(left>=1 && a[left]>=min){//������չ 
			sum+=a[left];
			left--;
		}
		while(right<=n && a[right]>=min){//������չ 
			sum+=a[right];
			right++;
		}
		maxx=max(maxx,a[i]*sum);
	}
	printf("%d\n",maxx);
} 
