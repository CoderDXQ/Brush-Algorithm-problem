/*#include<bits/stdc++.h>
using namespace std;
struct tree{
	char me;
	tree* left;tree* right;
	tree(char w=0):me(w),left(0),right(0){}//�ù��캯����ʼ�� 
	//w��ֵʱ��ֵ����ֵʱ�ǳ�ʼ����ֵ 
}root;
inline tree* build(char w){//����������tree*������ֵ��ָ�루��ַ�� 
	if(w=='*') return 0;
	return new tree(w);//���ص��ǵ�ַ 
}
tree* find_tree(char w,tree* start=&root)//�õ�ַ����,ֻ����W��ֵ���ɣ�start�Լ���ֵ 
{
	if(start->me==w) return start;
	tree* ans=0;
	if(start->left) ans=find_tree(w,start->left);
	if(ans) return ans;//��build�����У���w=*ʱ���ڵ��ַ��0�������������뱻�ж� 
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
		char me,l,r;cin>>me>>l>>r;//��������ѭ�����ڲ� 
		tree* node=find_tree(me);//���Ҹ��ַ����ڵ� 
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
	cin>>s;//������ڵ� 
	for(int i=2;i<=n;i++)
	{
	    string ss;
	    cin>>ss;
	    int x=s.find(ss[0]);
	    s.erase(x,1);//ɾ�� 
	    s.insert(x,ss);//���룬�γ��µ��������� 
	    //�������������о����������е����� 
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
 	for(i=1;i<=n;i++) if(a[i][0]==x) break;//�ҵ����ڵ��� 
 	for(j=1;j<3;j++)
 	    if(a[i][j]!='*') pig(a[i][j]);//�ݹ������� 
 	
 }
 int main()
 {
 	long i,j,k,m;
 	cin>>n;
 	for(i=1;i<=n;i++) cin>>a[i];
 	pig(a[1][0]);//���ݸ��ڵ� 
 	return 0;
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
  
