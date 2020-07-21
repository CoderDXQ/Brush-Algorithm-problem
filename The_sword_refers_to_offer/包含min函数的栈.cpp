//栈是后进先出

std::stack<std::int> m_data;
std::stack<std::int> m_min;//定义栈

templete<typename T>void StackWithMin<T>::push(const T& value)
{
    m_data.push(value);

    if(m_min.size()==0 || value<m_min.top())
        m_min.push(value);//辅助栈，存储正常栈对应位置时的最小值
    else
        m_min.push(m_min.top());
}

template<typename T>void StackWithMin<T>::pop()
{
    assert(m_data.size()>0 && m_min.size()>0);//断言 健壮性
    //两个栈非空才能执行下面的部分
    m_data.pop();
    m_min.pop();
}

template<typename t>const T& StackWithMin<T>::min()const
{
    assert(m_data.size()>0 && m_min.size()>0);//健壮性
    
    return m_min.top();
}







