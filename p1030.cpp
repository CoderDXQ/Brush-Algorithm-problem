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
	for(p=begin;1;p++){//ֱ���õ�ַ���в��� 
		if(*p==c) return i;
		i++;
	}
}
//ldr������lrd�Ǻ��� 
tree* create(char* ldr,char* lrd,int len){//len�Ǻ��������и��ڵ��λ�� 
	if(len<=0) return NULL;//���÷������� 
	tree* p=new tree;//��ָ����� ���Ƚ����ڵ� 
	p->data=lrd[len-1];//�Ӻ�������ȡ�����һ����Ϊ���ڵ��ֵ 
	int i=find(ldr,p->data);//�������������ҵ������ֳ��������� 
	p->left=create(ldr,lrd,i);//i���������и��ڵ��ں��������е�λ�� 
	p->right=create(ldr+i+1,lrd+i,len-1);//len-1���������ĸ��ڵ��ں��������е�λ�� 
	return p;//���ص�ַ 
}
void dlr(tree* t){//������� 
	cout<<t->data;//�� 
	tree* p;
	if(p=t->left) dlr(p);//�� 
	if(p=t->right) dlr(p);//�� 
}
int main()
{
	char a[10],b[10];
	cin>>a;cin>>b;
	tree* t=create(a,b,strlen(a));//���ó�ָ����� 
	dlr(t);//�����ǵ�ַ 
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s1[15],s2[15];//s1���������У�s2�Ǻ������� 
//��������ֱ�������������ʱ�Ľڵ�˳��������������˳�򣬿���ʡ�ԣ� 
void dfs(int l1,int r1,int l2,int r2){
	if(l1>r1) return;//������� 
	//��l1=r1ʱ������ֻ��һ��Ԫ�أ���Ҷ�ڵ� 
	int p;
    for(int i=l1;i<=r1;i++){
    	if(s1[i]==s2[r2]){//s2[r2]�Ǹ��ڵ� 
    		p=i;
			break;//��֦ 
		}
	}
	cout<<s1[p];
	int d1=(p-1)-l1;//��s1�м����������ĳ��� 
	int d2=(r1-1)-p;//��s2�м����������ĳ��� 
	dfs(l1,p-1,l2,l2+d1);
	dfs(p+1,r1,(r2-1)-d2,r2-1);
}
int main()
{
	int len;
	cin>>s1>>s2;
	len=strlen(s1);//s1���������У�s2�Ǻ������� 
    dfs(0,len-1,0,len-1);//�±���㿪ʼ
	return 0; 
}*/ 


#include<bits/stdc++.h>
using namespace std;
string a,b;//ʵ�����ַ������� ��a���������У�b�Ǻ������� 
int dfs(int left1,int right1,int left2,int right2)
{
	int m=a.find(b[right2]);
	cout<<b[right2];
	//��m==left1��˵���������ֻ��һ��Ԫ�أ���Ҷ�ڵ� 
	int d1=m-1-left1;//������������������������ 
	int d2=right1-(m+1);//������������������������
	if(m>left1) dfs(left1,m-1,left2,left2+d1);
	if(m<right1) dfs(m+1,right1,right2-1-d2,right2-1);
	//�����ǳ��ȵ�һ���㷨����һ���㷨�������
	/*
	right2-1-d2=left2+(m-left1);
	m-left1�������������������ĳ��ȣ�Ҳ�Ǻ����������������ĳ��� 
	left2+��m-left1�� ���Ǻ���������������һ��Ԫ�ص����� 
	ͬ��left2+d1=left2+��m-1-left1�� 
	*/ 
}
int main()
{
	cin>>a>>b;//string.size()�ǳ��ȣ�Ҫת��Ϊ�±� 
	dfs(0,a.size()-1,0,b.size()-1);
	return 0;
}































