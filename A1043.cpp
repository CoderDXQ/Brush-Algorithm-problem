#include<stdio.h>
#include<vector>//用变长数组来存储树的遍历有优势 
using namespace std;
struct node{
	int data;
	node *left,*right;
};//树的通常定义 

void insert(node*&root,int data)//要对root做改动，所以用引用型 
{
	if(root==NULL)
	{
		root=new node;
		root->data=data;
		root->left=root->right=NULL;
		return;
	}
	if(data<root->data) insert(root->left,data);
	else insert(root->right,data);
}
void preOrder(node *root,vector<int>&vi)//要对vi做改动，所以用引用型 
{
	if(root==NULL) return； 
	vi.push_back(root->data);
	preOrder(root->left,vi);
	preOrder(root->right,vi);
}
void preOrderMirror(node *root,vector<int>&vi)
{
	if(root==NULL) return;
	vi.push_back(root->data);
	preOrderMirror(root->right,vi);
	preOrderMirror(root->left,vi);
	//镜像树就是在遍历时交换访问左右子树的顺序 
}
void postOrder(node *root,vector<int>&vi)
{
	if(root==NULL) return;
	postOrder(root->left,vi);
	postOrder(root->right,vi);
	vi.push_back(root->data);
}
void postOrderMirror(node *root,vector<int>&vi)
{
	if(root==NULL) return;
	postOrderMirror(root->right,vi);
	postOrderMirror(root->left,vi);
	vi.push_back(root->data);	
}
vector<int>origin,pre,preM,post,postM;
int main()
{
	int n,data;
	node *root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		origin.push_back(data);
		insert(root,data);//用指针来做更方便，不宜用静态数组来表示二叉树 
	}
	preOrder(root,pre);
	preOrderMirror(root,preM);//vector在使用时是用的地址，跟数组一样 
	postOrder(root,post);
	postOrderMirror(root,postM);
	if(origin==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++)
		{
			printf("%d",post[i]);
			if(i<post.size()-1) printf(" ");
		}
	}else if(origin==preM){
		printf("YES\n");
		for(int i=0;i<postM.size();i++)
		{
			printf("%d",postM[i]);
			if(i<postM.size()-1) printf(" ");
		}
   }
   else
   {
   	printf("NO");
   }
   printf("\n");
   return 0;
}
