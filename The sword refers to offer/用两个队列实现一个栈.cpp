#include<bits/stdc++.h>
using namespace std;

template<typename T>class CStack{//定义类型
public://方法
    CStack(){};
    ~CStack(){};
    void push(const T& node);
    void pop();
    T top();
    int size();
    bool empty();
private:
    queue<T> queue1;
    queue<T> queue2;
};

//对方法进行重载
template<typename T>void CStack<T>::push(const T& node)
{//queue1只有一个元素 随时准备弹出
    if(queue1.size()>0)
    {
        queue1.push(node);    
    }
    else if(queue2.size()>0)
    {
        queue2.push(node);
    }
    else
    {
        queue1.push(node);
    }
    printf("node had been pushed\n");
}

template<typename T>void CStack<T>::pop()
{
    if(queue1.empty() && queue2.empty())
    {
        printf("stack is empty no operation\n");
    }
    else if(!queue2.empty())
    {
        while(queue2.size()>1)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        queue2.pop();
        printf("stack has been poped,leaves %d elements\n",queue1.size()+queue2.size());
    }
    else if(!queue1.empty())
    {
        while (queue1.size()>1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        queue1.pop();
        printf("stack has been poped,leaves %d elements\n",queue1.size()+queue2.size());
    }
    
}

template<typename T>T CStack<T>::top()
{
    T data;
    if(!queue1.empty())
    {
        while (queue1.size()>1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        
        data=queue1.front();
        queue2.push(queue1.front());
        queue1.pop();
        return data;
    }
    else if(!queue2.empty())
    {
        while(queue2.size()>1)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        data=queue2.front();
        queue1.push(queue2.front());
        queue2.pop();
        return data;
    }
    else
    {
        printf("stack is empty no operation\n");
    }
    return data;
}

template<typename T>int CStack<T>::size()
{
    return queue1.size()+queue2.size();
}

template<typename T>bool CStack<T>::empty()
{
    if(queue1.empty() && queue2.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
   CStack<int> stack;
   while (true)
   {
       string str;
       int num;
       cin>>str;
       if(str=="push")
       {
           cin>>num;
           stack.push(num);
       }
       if(str=="top")
       {//若输出28说明文件为空 28是ASCII码的文件分隔符
           cout<<stack.top()<<endl;
       }
       if(str=="pop")
       {
           stack.pop();
       }
       if(str=="size")
       {
           cout<<stack.size()<<endl;
       }
       if(str=="empty")
       {
           if(stack.empty()==true)
           {
               printf("True\n");
           }
           else
           {
               printf("False\n");
           }
           
       }
   }
   
    system("pause");
    return 0;
}