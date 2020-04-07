/* 
//迭代法
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) { //把地址传进来
	struct ListNode *res=NULL,*cur=head;
	while(cur) {
		head=head->next;//head向后移动
		cur->next=res;//cur是上次的新head节点，将上次的新head节点接到最左边（现在头结点）
		res=cur;//res存每次新的头结点
		cur=head;//cur指向下一个节点
	}
	return res;//返回头结点
}

int main(){
	ListNode* head;//只是定义了一个指针变量，并没有产生结构体实体 
	ListNode* pre;
	head=new ListNode;//用new来产生一个结构体实体，实体的内存地址存在head中 
	head->val=1;
	head->next=NULL;
	pre=head;//同类型变量赋值 
	for(int i=2; i<=5; i++) {//构造链表 
		ListNode* st;
		st=new ListNode; 
		st->val=i;
		st->next=NULL;
		pre->next=st;//要有取址符
		pre=st;
	}
	head=reverseList(head);
	while(head) {//输出链表 
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
	head->val=-1;//头结点设为-1（可以认为为空），防备m=1的情况发生 
	head->next=NULL;
	
	ListNode* zhi;
	zhi=head;
	
	int k;//共有k个节点 
	cin>>k;
	
	for(int i=1;i<=k;i++){
		st=new ListNode;
		st->val=i;
		st->next=NULL;
		zhi->next=st;
		zhi=st;
	}//构造链表 
	
	int m,n;//从m反转到n
	cin>>m>>n;
	
    ListNode* sss;
	ListNode* start;
	start=head;
	for(int i=1;i<m;i++) start=start->next;
    sss=start;//sss是衔接第一个出栈的节点的节点，即前一段的最后一个节点 
    start=start->next;//start是第一个入栈的节点 
    
	stack<ListNode*> ss;//直接定义成指针栈更节省空间 

	for(int i=0;i<=n-m;i++) {
		ss.push(start);//入栈的是副本 
	    start=start->next;
    }//start此时指向后一段的头结点 
    
    ListNode* tt;
	while(!ss.empty()) {//给前一段接上栈中节点 
		tt=ss.top();
		sss->next=tt;
		ss.pop();//弹栈 
		sss=sss->next;
	}

	sss->next=start;//接上后一段 

    head=head->next;//过掉空节点 
	while(head){//输出 
		cout<<head->val<<' ';
		head=head->next; 
	}
}































