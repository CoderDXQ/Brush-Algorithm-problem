/*
#include<bits/stdc++.h>
using namespace std;

int main() 
{
	bool live[42];
	memset(live,1, sizeof(live));
	//41���ˣ�ÿ������3�ͱ�ɱ�� 
	int killed=0,k=0,flag=1;
	cout<<"Death Order:\n";
	while(killed<39){
	    while(k<3){
	    	if(live[flag]==1) {
			    k++;
			    if(k==3) {
			    	killed++;
				    live[flag]=0;
				    cout<<flag<<' ';
			    }
			}
			flag++;
			if(flag==42) flag=1;
		}
	    if(k==3) k=0;
	} 
	cout<<'\n';
	cout<<"Survivor Number:";
	for(int i=1;i<=41;i++){
		if(live[i]==1) cout<<i<<' '; 
	} 
}
*/


#include<bits/stdc++.h>
using namespace std;
int main()
{
	int people=41;
	int k=3;
	//��0��ʼ��ţ���ôʣ�µ����һ���˵ı��һ��Ϊ0
	//����1��ʼ��ţ���ôȡ�������Ƚ��鷳 
	int result=0;
	for(int i=2;i<=41;i++)
	{
		//cout<<result+1<<' ';
		//��������������ţ���ô����Ĳ��ǳ�ʼ��ţ����Ǹ������±궨����� 
		result=(result+k)%i;
	}
    //ֻ��������һ����ɱ���� 
	cout<<result+1<<'\n'; 
}

















