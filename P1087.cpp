/*#include<bits/stdc++.h>
using namespace std;
struct Tree{
	char ty;
	Tree *left,*right;
	Tree(): left(NULL),right(NULL){}//换成NULl可以 
}*root=new Tree();//构造函数设置初值（初始化 )

char typeoff(const string s)   //不加取址符可以，string变量就是用地址工作 
{//string变量传递的是地址  函数名不能与系统中的typeof重复 
	int cnt0=count(s.begin(),s.end(),'0');
	int cnt1=s.size()-cnt0;
	if(cnt0!=0&&cnt1!=0) return 'F';
	if(cnt1==0) return 'B';
	if(cnt0==0) return 'I';
} 
void create(Tree* f,string s){
	if(s.size()==1){//叶节点的类型判定不用调用typeof函数，直接用三目运算即可 
		f->ty=(s=="0"?'B':'I');//三目运算符
		return;//设置好返回 
	}
	f->left=new Tree();f->right=new Tree();
	f->ty=typeoff(s);
	create(f->left,s.substr(0,s.size()/2));//初始位置，长度 
	create(f->right,s.substr(s.size()/2));//后面几位 
}
void post(Tree* f)
{//后序遍历 
	if(f->left) post(f->left);//左 
	if(f->right) post(f->right);//右 
	cout<<f->ty;//根 
}
int main()
{
	int n;
	cin>>n;
	string fbi;
	cin>>fbi;
	create(root,fbi);//输入根节点进行操作 
	post(root);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
char A[1025];
void work(int low,int up)//这个函数实际上是后序遍历 
{//思考清楚递归过程
//左右子树的字符串拼接起来正好是根所代表的字符串 
	int mid=(low+up)/2;
	if(low!=up){
		work(low,mid);//左 
		work(mid+1,up);//右 
	}
	//递归退栈或到达某一层后执行下面的操作 
	int i,a=0,b=0;
	for(i=low;i<=up;i++)//计数0,1确定F,B,I 
	{
		if(A[i]=='0') a++;
		else b++;
	 } 
	 if(a&&b) cout<<'F';
	 else if(a) cout<<'B';
	 else cout<<'I';
	 //根操作 
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",A+1);
    work(1,pow(2,n));	
	return 0;
 } 










































