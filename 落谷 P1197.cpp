#include<bits/stdc++.h>
using namespace std;
const int MAXI=4e5+4;
int f[MAXI],head[MAXI],h[MAXI],ans[MAXI],En=0;
bool e[MAXI];
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
   /* if(x!=f[x]) f[x]=find(f[x]);
    return f[x];*/
}
struct edge{
	int from,to,next;//nextΪǰ���Ƕ����� 
}a[MAXI];//a[]��� 
void insert(int u,int v){//��ʽǰ���� 
	a[En].from=u;
	a[En].to=v;
	a[En].next=head[u];
	head[u]=En;
	En++;
}
int main(){
	int n,m,k,x,y,tot,i,u;
	cin>>n>>m;
	for(i=0;i<n;++i){
		f[i]=i;//���鼯��ʼ�� 
		head[i]=-1;//ǰ���ǳ�ʼ�� 
	}
	for(i=0;i<m;++i)
	{//����ͼ 
		cin>>x>>y;
		insert(x,y);insert(y,x);//����ͼ 
	}
	cin>>k;
	tot=n-k;//�����ʣ��ĵ� 
	for(i=1;i<=k;i++){
		cin>>x;
		e[x]=true;
		h[i]=x;//�洢���α�����ĵ� 
	}//��������
	//�������ٳ����б�����ĵ㽨�����鼯������ͨ����� 
	for(i=0;i<2*m;i++){//�ߵ����㶼û����� 
		if(e[a[i].from]==false&&e[a[i].to]==false)
		{//En�Ǵ�0��ʼ�� 
			if(find(a[i].from)!=find(a[i].to))//����ͬһ���鼯������ͨ
			{
				tot--;
				f[find(a[i].from)]=find(a[i].to);//����̫��ĵ����Լ� 
			 } 
		}
	} 
	ans[k+1]=tot;//k�δ����ʣ�µ���ͨ�����Ŀ�����������޸� 
	for(int t=k;t>=1;t--){
	    u=h[t];
	    tot++;
	    e[u]=false;//�ָ��õ� 
	    for(i=head[u];i!=-1;i=a[i].next)//ǰ���Ǳ��� 
	    {
	    	if(e[a[i].to]==false&&find(u)!=find(a[i].to))
	    	{//u��ĳ���ߵĶԵ�δ����������㲻��ͬһ���鼯 
	    		tot--;
	    		f[find(a[i].to)]=find(u);//�ϲ� 
			}
		 } 
		 ans[t]=tot;
	}
	for(i=1;i<=k+1;++i) cout<<ans[i]<<endl;
	return 0;
} 
