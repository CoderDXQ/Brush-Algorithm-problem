#include<stdio.h>
using namespace std;
int n,cnt=1;
void func(int x)
{
	for(int i=1;i<=x/2;i++)
	{
		cnt++;
		func(i);
	}
 } 
 int main()
 {
 	scanf("%d",&n);
 	func(n);
 	printf("%d\n",cnt);
 }//�õݹ�ᳬʱ��ԭ�����ظ����㣬��˿��õ���*/
#include<stdio.h>//��һ�ֵ��� 
using namespace std;
int N,Ans[1005],Sum[1005];
int main()
{
	scanf("%d",&N);
	for(register int i=1;i<=N;i++)//register intʹint i��cpu�ڲ��Ĵ�����
	//�洢�������ڴ棬�Ӷ���������������ȣ������������ϳ�����ѭ���� 
	    Sum[i]=Sum[i-1]+(Ans[i]=Sum[i>>1]+1);//λ���� 
	return not printf("%d\n",Ans[N]);
}
#include<iostream>//�ڶ��ֵ��� 
using namespace std;
int f[1001];
int main()
{
	int n;	cin>>n;f[1]=1;
	for(int i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		if(i%2==0) f[i]+=f[i/2];
	}
	cout<<f[n];
}
