#include<bits/stdc++.h>//����������ͷ
using namespace std;//�����������ռ�
unsigned long long n,k,sum;//�����ı�������
int main()
{
	
    cin>>n>>k;//����������
    if(k>32) k=32;//�����������
    while(k>1&&n>0)//n>0���ӵĻ�����Ῠ���ڴ�
    for(int i=63;i>=0;i--)
    if(pow(2,i)<=n){n-=pow(2,i);k--;cout<<'A'<<i<<endl;break;}
	//�κ�һ����Ȼ�������Բ�ֳ����ɸ�2���ݵĺ�
    if(n==0){cout<<"0";return 0;}//����
    for(int i=0;;i++)
    {
        if(pow(2,i)>=n)
        {
        	cout<<'B'<<i<<endl;
          //  cout<<(unsigned long long)pow(2,i)-n;//���������
            break;//����forѭ����ߵ�������
        }
    }
    return 0;
}
