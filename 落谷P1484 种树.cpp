#include<bits/stdc++.h>
using namespace std;
#define N 500007
#define int long long//һ������ 
struct Place{int val,l,r;}p[N];
struct Node{//�����зŵ�Ԫ�� 
	int val,id;
	bool operator<(Node it) const
	{
		return val<it.val; 
	}//�������ؽ������򣬴���� 
};
int n,m,ans;
bool vis[N];//������� 
priority_queue<Node> q;
void Del(int x){
	p[x].l=p[p[x].l].l;p[x].r=p[p[x].r].r;
	p[p[x].l].r=x;p[p[x].r].l=x;//ɾ���ڵ� 
}
signed main(){//int�����汻�滻���ˣ��������޷��������� 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i].val;
		p[i].l=i-1;p[i].r=i+1;
		q.push((Node){p[i].val,i});//��� 
	}
	for(int i=1;i<=m;i++){//�����m���� 
	    while(vis[q.top().id]) q.pop();//�ų����ȶ������Ѿ������ʵĵ�
		Node now=q.top();q.pop();
		if(now.val<=0) break;//����������Ĳ������ģ���ô��û�����ֵı�Ҫ
		ans+=now.val;//���������� 
		vis[p[now.id].l]=vis[p[now.id].r]=1;//��� 
		p[now.id].val=p[p[now.id].l].val+p[p[now.id].r].val-p[now.id].val;
		//��������Ƿ��ڲ��Ե�Ȩֵ��ʽ 
		q.push((Node){p[now.id].val,now.id});
		Del(now.id);//���ڲ��ԵĲ��� 
	}
	cout<<ans;
	return 0;
 } 
