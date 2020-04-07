#include<bits/stdc++.h>
using namespace std;
int main(){
	int j,n,sum=0;
	bool xs[28];
	bool xx[28];
	bool flag;
	int num[15]={0};
	cin>>n;
	for(int i=1;i<=n;i++) num[i]=i;//初始化 
	do{
	    memset(xs,0,sizeof(xs));
	    memset(xx,0,sizeof(xx));
	    flag=true;
		for(register int i=1;i<=n;i++){
			if(!xs[i+num[i]]) xs[i+num[i]]=true;
		    else {
				flag=false;
			    break;//break必须放在后面 
		    }
		    if(!xx[i-num[i]+n]) xx[i-num[i]+n]=true;
		    else {
				flag=false;
			    break;//break必须放在后面
		    }
		}
		if(flag==true){
			sum++;
			if(sum<=3){
				for(j=1;j<=n;j++) cout<<num[j]<<' ';
				cout<<endl;
			}
		}
	}while(next_permutation(num+1,num+n+1));//这个函数太慢 
// next_permutation(a,b) 对该数组前b-a个元素进行 
	cout<<sum;
	return 0;
}
