/* 
//������
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) { //�ѵ�ַ������
	struct ListNode *res=NULL,*cur=head;
	while(cur) {
		head=head->next;//head����ƶ�
		cur->next=res;//cur���ϴε���head�ڵ㣬���ϴε���head�ڵ�ӵ�����ߣ�����ͷ��㣩
		res=cur;//res��ÿ���µ�ͷ���
		cur=head;//curָ����һ���ڵ�
	}
	return res;//����ͷ���
}

int main(){
	ListNode* head;//ֻ�Ƕ�����һ��ָ���������û�в����ṹ��ʵ�� 
	ListNode* pre;
	head=new ListNode;//��new������һ���ṹ��ʵ�壬ʵ����ڴ��ַ����head�� 
	head->val=1;
	head->next=NULL;
	pre=head;//ͬ���ͱ�����ֵ 
	for(int i=2; i<=5; i++) {//�������� 
		ListNode* st;
		st=new ListNode; 
		st->val=i;
		st->next=NULL;
		pre->next=st;//Ҫ��ȡַ��
		pre=st;
	}
	head=reverseList(head);
	while(head) {//������� 
		cout<<head->val<<' ';
		head=head->next;
	}
}
*/

#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

int main(){
	ListNode* head;
	ListNode* st;

	head=new ListNode;
	head->val=-1;//ͷ�����Ϊ-1��������ΪΪ�գ�������m=1��������� 
	head->next=NULL;
	
	ListNode* zhi;
	zhi=head;
	
	int k;//����k���ڵ� 
	cin>>k;
	
	for(int i=1;i<=k;i++){
		st=new ListNode;
		st->val=i;
		st->next=NULL;
		zhi->next=st;
		zhi=st;
	}//�������� 
	
	int m,n;//��m��ת��n
	cin>>m>>n;
	
    ListNode* sss;
	ListNode* start;
	start=head;
	for(int i=1;i<m;i++) start=start->next;
    sss=start;//sss���νӵ�һ����ջ�Ľڵ�Ľڵ㣬��ǰһ�ε����һ���ڵ� 
    start=start->next;//start�ǵ�һ����ջ�Ľڵ� 
    
	stack<ListNode*> ss;//ֱ�Ӷ����ָ��ջ����ʡ�ռ� 

	for(int i=0;i<=n-m;i++) {
		ss.push(start);//��ջ���Ǹ��� 
	    start=start->next;
    }//start��ʱָ���һ�ε�ͷ��� 
    
    ListNode* tt;
	while(!ss.empty()) {//��ǰһ�ν���ջ�нڵ� 
		tt=ss.top();
		sss->next=tt;
		ss.pop();//��ջ 
		sss=sss->next;
	}

	sss->next=start;//���Ϻ�һ�� 

    head=head->next;//�����սڵ� 
	while(head){//��� 
		cout<<head->val<<' ';
		head=head->next; 
	}
}































