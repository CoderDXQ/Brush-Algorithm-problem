/*#include<bits/stdc++.h>
using namespace std;
struct Tree{
	char ty;
	Tree *left,*right;
	Tree(): left(NULL),right(NULL){}//����NULl���� 
}*root=new Tree();//���캯�����ó�ֵ����ʼ�� )

char typeoff(const string s)   //����ȡַ�����ԣ�string���������õ�ַ���� 
{//string�������ݵ��ǵ�ַ  ������������ϵͳ�е�typeof�ظ� 
	int cnt0=count(s.begin(),s.end(),'0');
	int cnt1=s.size()-cnt0;
	if(cnt0!=0&&cnt1!=0) return 'F';
	if(cnt1==0) return 'B';
	if(cnt0==0) return 'I';
} 
void create(Tree* f,string s){
	if(s.size()==1){//Ҷ�ڵ�������ж����õ���typeof������ֱ������Ŀ���㼴�� 
		f->ty=(s=="0"?'B':'I');//��Ŀ�����
		return;//���ú÷��� 
	}
	f->left=new Tree();f->right=new Tree();
	f->ty=typeoff(s);
	create(f->left,s.substr(0,s.size()/2));//��ʼλ�ã����� 
	create(f->right,s.substr(s.size()/2));//���漸λ 
}
void post(Tree* f)
{//������� 
	if(f->left) post(f->left);//�� 
	if(f->right) post(f->right);//�� 
	cout<<f->ty;//�� 
}
int main()
{
	int n;
	cin>>n;
	string fbi;
	cin>>fbi;
	create(root,fbi);//������ڵ���в��� 
	post(root);
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
char A[1025];
void work(int low,int up)//�������ʵ�����Ǻ������ 
{//˼������ݹ����
//�����������ַ���ƴ�����������Ǹ���������ַ��� 
	int mid=(low+up)/2;
	if(low!=up){
		work(low,mid);//�� 
		work(mid+1,up);//�� 
	}
	//�ݹ���ջ�򵽴�ĳһ���ִ������Ĳ��� 
	int i,a=0,b=0;
	for(i=low;i<=up;i++)//����0,1ȷ��F,B,I 
	{
		if(A[i]=='0') a++;
		else b++;
	 } 
	 if(a&&b) cout<<'F';
	 else if(a) cout<<'B';
	 else cout<<'I';
	 //������ 
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",A+1);
    work(1,pow(2,n));	
	return 0;
 } 










































