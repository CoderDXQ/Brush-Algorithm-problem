/*#include<bits/stdc++.h>
using namespace std;
struct tree{
	char me;
	tree* left;tree* right;
	tree(char w=0):me(w),left(0),right(0){}//用构造函数初始化 
	//w有值时赋值，无值时是初始化的值 
}root;
inline tree* build(char w){//函数类型是tree*，返回值是指针（地址） 
	if(w=='*') return 0;
	return new tree(w);//返回的是地址 
}
tree* find_tree(char w,tree* start=&root)//用地址来做,只输入W的值即可，start自己赋值 
{
	if(start->me==w) return start;
	tree* ans=0;
	if(start->left) ans=find_tree(w,start->left);
	if(ans) return ans;//在build函数中，当w=*时，节点地址是0，因此在这里必须被判断 
	if(start->right) ans=find_tree(w,start->right);
	if(ans) return ans;
 }  
void preorder(tree* start)
{
	cout<<start->me;
	if(start->left) preorder(start->left);
	if(start->right) preorder(start->right);
}
int main()
{
	int n;cin>>n;
	char me,l,r;cin>>me>>l>>r;
	root.me=me;root.left=build(l);root.right=build(r);
	for(int i=1;i<n;i++)
	{
		char me,l,r;cin>>me>>l>>r;//作用域在循环体内部 
		tree* node=find_tree(me);//查找该字符根节点 
		node->left=build(l);node->right=build(r);
	}
	preorder(&root);return 0;
 } */

#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
	cin>>n;
	cin>>s;//读入根节点 
	for(int i=2;i<=n;i++)
	{
	    string ss;
	    cin>>ss;
	    int x=s.find(ss[0]);
	    s.erase(x,1);//删除 
	    s.insert(x,ss);//插入，形成新的先序序列 
	    //利用了输入序列就是先序序列的条件 
	}
	for(int i=0;i<s.size();i++)
	    if(s[i]!='*') cout<<s[i];	
}

 #include<bits/stdc++.h>
 using namespace std;
 string a[10001];
 long n;
 void pig(char x)
 {
 	cout<<x;
 	long i,j;
 	for(i=1;i<=n;i++) if(a[i][0]==x) break;//找到所在的行 
 	for(j=1;j<3;j++)
 	    if(a[i][j]!='*') pig(a[i][j]);//递归进行输出 
 	
 }
 int main()
 {
 	long i,j,k,m;
 	cin>>n;
 	for(i=1;i<=n;i++) cin>>a[i];
 	pig(a[1][0]);//传递根节点 
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
