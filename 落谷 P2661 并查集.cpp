#include<bits/stdc++.h>
using namespace std;
int n,f,i,k,cnt=0,ans=0x3f3f3f3f;//��Ҫ��ʼ�� 
int fa[200005];
inline int find(int x,int &cnt)//�ҵ������Ľ��� 
{//cntҪ�õ�ַ����������Ϊ���ڵݹ��м����õ�
    cnt++;//�������� 
	if(fa[x]==x) return x;
	else return find(fa[x],cnt);
} 
int main()
{
	cin>>n;
	for(i=1;i<=n;i++) fa[i]=i;//���鼯�ĳ�ʼ��
	for(i=1;i<=n;i++)
	{
		cin>>f;//�ڱ����У�����·����i->f 
		cnt=0;//��Ҫ�ĳ�ʼ�� 
		if(find(f,cnt)==i)//���ڻ�·������=��ֹ��һ����· 
		{
			ans=min(cnt,ans);//ά����С�Ļ��ĳ��� 
			//��ʹ��min��maxʱ��Ҫע��ά�������ĳ�ʼ�� 
		}
		else
		  fa[i]=f;
	 } 
	 cout<<ans<<endl;
	 return 0;
}
