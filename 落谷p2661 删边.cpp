#include<bits/stdc++.h>
using namespace std;
#define N 200005
#define INF 200005
int to[N],indegree[N];//��¼��� 
bool visit[N];
int n;
void delzero(){
	bool flag=1;
	for(int i=1;i<=n;i++){//������һ��ɾ�� 
		if(indegree[i]==0&&!visit[i]){
//��iΪ���ı�δ�����ʹ�,��i�����Ϊ0��������һ���ϱ� 
			flag=0;//��־�Ż��б߿���ɾ 
			visit[i]=1;//���ɾ���ĵ㣬��search()�в��ᱻ���� 
			indegree[to[i]]--;//ɾ��һ���� 
		}
	}
	if(flag) return;//û�зϱ߿���ɾ���� 
	else delzero();//������һ��ɾ�� 
}
int ans=INF;//��Ҫ��ʼ��
void search(int start,int now,int step){
	if(start==now){ans=min(ans,step);return;}//���÷�������
	visit[now]=1;//��� 
	search(start,to[now],step+1); //���õݹ������ 
} 
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>to[i];
		indegree[to[i]]++;//������� 
	}
	delzero();
	for(int i=1;i<=n;i++){
		if(!visit[i]){//��֦ 
			visit[i]=1;//��ǣ���Ϊһ����ͨ����������һ���� 
			search(i,to[i],1);//�������л� 
		}
	}
	cout<<ans<<endl;
	return 0;
}
