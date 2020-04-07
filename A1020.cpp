#include<stdio.h>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50;
struct node
{
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn],in[maxn],post[maxn];
int n;

node *create(int postL,int postR,int inL,int inR)
{
	if(postL>postR){
		return NULL;
	}
	node *root=new node;
	root->data=post[postR];
	int k;
	for(k=inL;k<=inR;k++)
	{
		if (in[k]==post[postR]){
			break;
		}
	}
	int num=k-inL;
	root->lchild=create(postL,postL+num-1,inL,k-1);
	root->rchild=create(postL+num,postR-1,k+1,inR);
	return root;
}

int nu=0;
void BFS(node * root)
{
	queue<node*> q;//队列中存地址可以减小内存负担
	q.push(root);
	while(!q.empty())
    {
    	node *now=q.front();//队列是front不是top
		q.pop();
		printf("%d",now->data);
		nu++;
		if (nu<n) printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild);
    	if(now->rchild!=NULL) q.push(now->rchild);
		}	
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;++i)
	{
		scanf("%d",&in[i]);
	}
	node * root=create(0,n-1,0,n-1);
	BFS(root);
	return 0;
}

