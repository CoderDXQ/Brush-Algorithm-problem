#include<bits/stdc++.h>
using namespace std;
int father[10005];
int find(int x)//�ҵ����� 
{//·��ѹ�� 
	if (father[x]==x) return x;//��������
	else return father[x]=find(father[x]);//�����յĵ�
}//���õݹ�һ��һ����ҵ� 
int main()
{
	int n,m,z,x,y;
	cin>>n>>m;
    for(int i=1;i<=n;i++) father[i]=i;//��ʼ���������Լ��ĵ����Լ� 
	for(register int i=1;i<=m;i++)
	{
		cin>>z>>x>>y;
		if(z==1)
		{//��x��y���ڵļ��Ϻϲ������ǰ�x��y���������յ��ϲ� 
		    father[find(x)]=find(y);
		    //father[find(y)]=find(x);
	    }
		else
		{
			if(find(x)==find(y)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}	
	return 0;
}
