#include<bits/stdc++.h> 
using namespace std;
#define N 100000
struct node{
	int id;
	int score;
};node a[N];

bool cmp(node x,node y)//x����ͷԪ�أ�y����βԪ�� 
{
	if(x.score!=y.score) return y.score<x.score;
	else return y.id>x.id;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].id>>a[i].score;
	sort(a+1,a+n+1,cmp);//sort�������Զ�ѡ�����������㷨�������ǵ�ַ��cmp�ǱȽϹ��� 
    m=m*1.5;
    int line,sum=0;
    line=a[m].score;
    for(int i=1;a[i].score>=line;i++)
    {
    	sum++;
	}
	cout<<line<<' '<<sum<<endl;
	for(int i=1;i<=sum;i++)
	{
		cout<<a[i].id<<' '<<a[i].score<<endl;
		}	
}
