#include<bits/stdc++.h>
using namespace std;
struct node{
	int n;
	node *left,*right;
	node(int t){//利用构造函数赋初值 
		left=right=NULL;
		n=t;//n存储的是序号 
	}
}*p[100010],*q;
int main()
{
	int m,n,i,j,k,u=1,v;
	p[1]=new node(1);
	cin>>n;
	for(i=2;i<=n;i++){//插入 
		cin>>j>>k;
		p[i]=new node(i);
		if(k){
			if(p[j]->right){//右边有元素，需要移动 
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
			if(j==u) u=i;//用u来记录开头元素，仅限于左插的情况，
			//插在头元素左侧，从而产生了新的开头 
			//可以认为是没有设置头元素的弊端，数组解法设置了头元素，没有这种问题 
		}
	}
	cin>>m;
	for(i=1;i<=m;i++){//删除 
		cin>>k;//左侧有元素 
		if(p[k]->left) p[k]->left->right=p[k]->right;
		if(p[k]->right){//右侧有元素 
			p[k]->right->left=p[k]->left;
			//if(k==u) u=p[k]->right->n;//u标记开头元素,可以放在下面 
        }
        if(k==u) u=p[k]->right->n;
        //***是否可以去掉 
        p[k]->left=p[k]->right=NULL;//注意所删元素在两头的情况
	}
	q=p[u];
    while(q){
        printf("%d ",q->n);
		q=q->right;	
	}
	return 0;
}

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
