#include<bits/stdc++.h>
using namespace std;

int main(){
	double m;
	int n;
	vector<double> res;
	
	cin>>m>>n;//mԪ��n����� 
	
	srand(time(NULL));//��������������ӣ�����ÿ��rand���ɵ�������ж���ͬ 
	for(int i=1;i<n-1;i++){
		double dt=rand()%10;//0-9֮�������� 
		double dt1=(double)dt*m/10;//���ηֳ��ĺ����С 

		res.push_back(dt1);
		m-=dt1;//ʣ��Ľ���� 
	} 

    double sum=0;	
	res.push_back(m);
	//vector������±�Ҳ�Ǵ�0��ʼ 
	for(int i=0;i<n;i++)
	{
	     cout<<res[i]<<endl;
	     sum+=res[i];
	 } 
	 cout<<sum<<endl;
	return 0;
	
	
} 
