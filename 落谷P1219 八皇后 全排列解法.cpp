#include<bits/stdc++.h>
using namespace std;
int main(){
	int j,n,sum=0;
	bool xs[28];
	bool xx[28];
	bool flag;
	int num[15]={0};
	cin>>n;
	for(int i=1;i<=n;i++) num[i]=i;//��ʼ�� 
	do{
	    memset(xs,0,sizeof(xs));
	    memset(xx,0,sizeof(xx));
	    flag=true;
		for(register int i=1;i<=n;i++){
			if(!xs[i+num[i]]) xs[i+num[i]]=true;
		    else {
				flag=false;
			    break;//break������ں��� 
		    }
		    if(!xx[i-num[i]+n]) xx[i-num[i]+n]=true;
		    else {
				flag=false;
			    break;//break������ں���
		    }
		}
		if(flag==true){
			sum++;
			if(sum<=3){
				for(j=1;j<=n;j++) cout<<num[j]<<' ';
				cout<<endl;
			}
		}
	}while(next_permutation(num+1,num+n+1));//�������̫�� 
// next_permutation(a,b) �Ը�����ǰb-a��Ԫ�ؽ��� 
	cout<<sum;
	return 0;
}
