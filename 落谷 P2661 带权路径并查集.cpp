#include<bits/stdc++.h>
using namespace std;
int f[200002],d[200002],n,minn,last;
int find(int x){//��Ȩ·�����鼯ģ�� 
	if(f[x]==x) return x;
	else
	{
		int last=f[x];//��¼���ڵ� 
		f[x]=find(f[x]);//�������ȣ�����̫�棩�ڵ� 
		d[x]+=d[last];//����·���� 
		return f[x];//������������һ�鲢�鼯 
	}
}
void check(int a,int b){
	int x=find(a),y=find(b);
	if(x==y) minn=min(minn,d[a]+d[b]+1);
//�¼����һ���ߵ������˵��ڲ��鼯��ͬ���ȣ���һ���ɻ� 
//d[]����õ㵽�����ȣ�����̫�棩��·������ 
	else{
		f[x]=y;//�ϲ� 
		d[a]=d[b]+1;//����·������ 
	}
	
}
int main(){
	int i,t;
	cin>>n;
	for(i=1;i<=n;i++) f[i]=i;//���鼯��ʼ��
	minn=0x7777777;//��Ҫ��ʼ��
	for(i=1;i<=n;i++){
		cin>>t;
		check(i,t);
	 } 
    cout<<minn<<endl;
	return 0;	
}

