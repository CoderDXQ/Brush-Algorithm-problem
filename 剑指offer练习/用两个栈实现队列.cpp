//队列的类型
template<typename>class CQueue
{
    public:
        CQueue(void);
        ~CQueue(void);
//新的队列的插入和删除功能
        void appendTail(const T& node);//泛型
        T deleteHead();

    private:
        stack<T> stack1;//两个栈 泛型
        stack<T> stack2;
};

template<typename T>void CQueue<T>::appendTail(const T& element)//重载
{//插入队列时保证Stack2为空 其实不必如此
    while(!stack2.empty())
    {
        //T& data;泛型变量定义
        stack1.push(stack2.top());
        stack2.pop();
    }
    stack1.push(element);
}

template<typename T>T CQueue<T>::deleteHead()
{//出队列时保证stack1为空 其实不必如此
    while (!stack1.empty())
    {
        //T& data;泛型变量定义
        stack2.push(stack1.top());
        stack1.pop();
    }

    if(stack2.size()==0)//健壮性
    {
        throw new exception("queue is empty");
    }

    T head=stack2.top();//head是个地址
    stack2.pop();
    return head;
}


#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
 
template <typename T> class CQueue
{
public:
	CQueue(void){};
	~CQueue(void){};
	void appendTail(const T& node);
	T deleteHead();
 
private:
	stack<T> stack1;
	stack<T> stack2;
};
 
template<typename T> 
void CQueue<T>::appendTail(const T& node)
{//插入只与stack1有关 
	stack1.push(node);
}
 
template<typename T> T CQueue<T>::deleteHead()
{//弹出只与stack2有关 若stack2为空就把stack1的元素灌进去
	if(stack2.size() <= 0){
		while(stack1.size() > 0){
			T& data = stack1.top();//带不带&都可以
			stack1.pop();
			stack2.push(data);
		}
	}
	if(stack2.size() == 0)
		throw new exception("queue is empty");
	T head = stack2.top();
	stack2.pop();
	return head;
}
int main()
{
	CQueue<int> qu;
	int a = 1;
	int b = 2;
	int c = 3;
	qu.appendTail(a);
	qu.appendTail(b);
	qu.appendTail(c);
	cout<<qu.deleteHead()<<" ";
	cout<<qu.deleteHead()<<" ";
	cout<<qu.deleteHead()<<" ";
	system("pause");
	return 0;
}