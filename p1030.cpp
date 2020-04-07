/*#include<bits/stdc++.h>
using namespace std;
struct tree{
	char data;
	tree* left;
	tree* right;
};
inline int find(char* begin,char c){
	char*p;
	int i=0;
	for(p=begin;1;p++){//直接用地址进行操作 
		if(*p==c) return i;
		i++;
	}
}
//ldr是中序，lrd是后序 
tree* create(char* ldr,char* lrd,int len){//len是后序序列中根节点的位置 
	if(len<=0) return NULL;//设置返回条件 
	tree* p=new tree;//用指针操作 ，先建立节点 
	p->data=lrd[len-1];//从后序序列取出最后一个作为根节点的值 
	int i=find(ldr,p->data);//在中序序列中找到根，分出左右子树 
	p->left=create(ldr,lrd,i);//i是左子树中根节点在后序序列中的位置 
	p->right=create(ldr+i+1,lrd+i,len-1);//len-1是右子树的根节点在后序序列中的位置 
	return p;//返回地址 
}
void dlr(tree* t){//先序遍历 
	cout<<t->data;//根 
	tree* p;
	if(p=t->left) dlr(p);//左 
	if(p=t->right) dlr(p);//右 
}
int main()
{
	char a[10],b[10];
	cin>>a;cin>>b;
	tree* t=create(a,b,strlen(a));//设置成指针变量 
	dlr(t);//传的是地址 
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s1[15],s2[15];//s1是中序序列，s2是后序序列 
//不建树，直接输出；（建树时的节点顺序就是先序遍历的顺序，可以省略） 
void dfs(int l1,int r1,int l2,int r2){
	if(l1>r1) return;//中序遍历 
	//当l1=r1时，序列只有一个元素，即叶节点 
	int p;
    for(int i=l1;i<=r1;i++){
    	if(s1[i]==s2[r2]){//s2[r2]是根节点 
    		p=i;
			break;//剪枝 
		}
	}
	cout<<s1[p];
	int d1=(p-1)-l1;//在s1中计算左子树的长度 
	int d2=(r1-1)-p;//在s2中计算右子树的长度 
	dfs(l1,p-1,l2,l2+d1);
	dfs(p+1,r1,(r2-1)-d2,r2-1);
}
int main()
{
	int len;
	cin>>s1>>s2;
	len=strlen(s1);//s1是中序序列，s2是后序序列 
    dfs(0,len-1,0,len-1);//下标从零开始
	return 0; 
}*/ 


#include<bits/stdc++.h>
using namespace std;
string a,b;//实质是字符串数组 ，a是中序序列，b是后序序列 
int dfs(int left1,int right1,int left2,int right2)
{
	int m=a.find(b[right2]);
	cout<<b[right2];
	//若m==left1，说明这个序列只有一个元素，即叶节点 
	int d1=m-1-left1;//在中序序列中求左子树长度 
	int d2=right1-(m+1);//在中序序列中求右子树长度
	if(m>left1) dfs(left1,m-1,left2,left2+d1);
	if(m<right1) dfs(m+1,right1,right2-1-d2,right2-1);
	//以上是长度的一种算法，另一种算法更好理解
	/*
	right2-1-d2=left2+(m-left1);
	m-left1是中序序列中左子树的长度，也是后序序列中左子树的长度 
	left2+（m-left1） 就是后序序列右子树第一个元素的坐标 
	同理，left2+d1=left2+（m-1-left1） 
	*/ 
}
int main()
{
	cin>>a>>b;//string.size()是长度，要转化为下标 
	dfs(0,a.size()-1,0,b.size()-1);
	return 0;
}































