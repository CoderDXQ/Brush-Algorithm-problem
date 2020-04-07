/*#include<bits/stdc++.h>
using namespace std;
int main(){
	long long m,k,k2,l,r;
	cin>>m;
	m=m<<1;//m乘2 
    k=sqrt(m);
    for(int k1=k;k1>=2;k1--)//i=1时l=r 不符合题意 
    	if(m%k1==0){
		 k2=m/k1;
		if((k2-k1)&1==1){
		    l=(k2-k1+1)>>1;
			r=(k2+k1-1)>>1;    
    	    cout<<l<<' '<<r<<endl;
        }
	}
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
int main()
{//尺取法是整体往右走的 
	int i,j,n,m,sum;
	cin>>m;
	n=m>>1;
	i=1,j=2,sum=3;
	while(i<=n)//当i=1时的特殊情况 
	{
		if(sum<m)
		{
			j++;
			sum+=j;
		}
		else if(sum==m)
		{
			cout<<i<<' '<<j<<endl;
			sum-=i;
			i++;
		}
		else 
		{
			sum-=i;
			i++;
		}		
	}
	return 0;
} 
