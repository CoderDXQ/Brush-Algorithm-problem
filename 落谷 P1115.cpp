/*#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,ans=0,tmp=0,now=0;
	cin>>n;
	cin>>now;
	ans=now;
	if(now>0) tmp=now;
	for(register int i=2;i<=n;i++)
	{
		cin>>now;
		tmp=tmp+now;//tmp�ǵ�ǰ������ 
		if(tmp>ans) ans=tmp;//ans�������������� 
		if(tmp<0) tmp=0;//�Ͽ� ����tmp����������� 
	}
	printf("%d",ans);
 }*/
 
 #include<bits/stdc++.h>
 using namespace std;
 int main()
 {
 	int n[200001],p,ans[200001]={0};
 	int sum=-9999999;
 	cin>>p;
 	for(int i=1;i<=p;i++)
 	{
 		cin>>n[i];
 		ans[i]=max(ans[i-1]+n[i],n[i]);//DP
 		//��ans[i-1]+n[i]<0 ��ans[i]Ϊ n[i]����ʾ���������жϿ� 
 		//ans[i]�洢��ǰλ�õ�ǰ�����е�������
        sum=max(sum,ans[i]); 		
        // sum�洢������������кͣ���ÿ��ans[i]�ȽϺ�ó������
		//sum�ĸ���ֵ�ǳ���Ҫ��������һ����С����
	 }
	 cout<<sum;
	 return 0;
  } 
 
