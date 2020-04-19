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
}

template<typename T>void CQueue<T>::appendTail(const T& element)//重载
{//插入队列时保证Stack2为空
    while(!stack2.empty())
    {
        //T& data;泛型变量定义
        stack1.push(stack2.top());
        stack2.pop();
    }
    stack1.push(element);
}

template<typename T>T CQueue<T>::deleteHead()
{//出队列时保证stack1为空
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