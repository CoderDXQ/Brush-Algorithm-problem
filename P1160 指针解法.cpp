#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	node *left,*right;
	node(int t){//���ù��캯������ֵ 
		left=right=NULL;
		n=t;//n�洢������� 
	}
}*p[100010],*q;
int main()
{
	int m,n,i,j,k,u=1,v;
	p[1]=new node(1);
	cin>>n;
	for(i=2;i<=n;i++){//���� 
		cin>>j>>k;
		p[i]=new node(i);
		if(k){
			if(p[j]->right){//�ұ���Ԫ�أ���Ҫ�ƶ� 
				p[j]->right->left=p[i];
				p[i]->right=p[j]->right;
			}
			p[j]->right=p[i];p[i]->left=p[j];
		}
		else{
		    if(p[j]->left)
			{
				p[j]->left->right=p[i];
				p[i]->left=p[j]->left;
				}
			p[j]->left=p[i];p[i]->right=p[j];
			if(j==u) u=i;//��u����¼��ͷԪ�أ����������������
			//����ͷԪ����࣬�Ӷ��������µĿ�ͷ 
			//������Ϊ��û������ͷԪ�صı׶ˣ�����ⷨ������ͷԪ�أ�û���������� 
		}
	}
	cin>>m;
	for(i=1;i<=m;i++){//ɾ�� 
		cin>>k;//�����Ԫ�� 
		if(p[k]->left) p[k]->left->right=p[k]->right;
		if(p[k]->right){//�Ҳ���Ԫ�� 
			p[k]->right->left=p[k]->left;
			//if(k==u) u=p[k]->right->n;//u��ǿ�ͷԪ��,���Է������� 
        }
        if(k==u) u=p[k]->right->n;
        //***�Ƿ����ȥ�� 
        p[k]->left=p[k]->right=NULL;//ע����ɾԪ������ͷ�����
	}
	q=p[u];
    while(q){
        printf("%d ",q->n);
		q=q->right;	
	}
	return 0;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
