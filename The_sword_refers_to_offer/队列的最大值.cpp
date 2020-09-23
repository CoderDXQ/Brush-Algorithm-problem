template<typenam T>class QueueWithMax
{
public:
    QueueWithMax():currentIndex(0)
    {
    }

    void push_back(T number)
    {
        while(!maximums.empty() && number>=maximums.back()number)
            maximums.pop_back();

        InternalData internalData=(number,currentIndex);
        data.push_back(internalData);
        maximums.push_back(internalData);

        ++currentIndex;
    }

    void pop_front()
    {
        if(maximums.empty())
            throw new exception("queue is empty");

        if(maximums.front().index==data.front().index)
            maximums.pop_front();
        
        data.pop_front();
    }

    T max() const
    {
        if(maximums.empty())
            throw new exception("queue is empty");

        return maximums.front().number;//自定义队列maximums的头节点存放的是当前队列的最大值
    }
private:
    struct InternalData//定义结构体
    {
        T number;
        int index;
    };

    deque<InternalData> data;//存放队列数据
    deque<InternalData> maximums;//存放相应队列情况的最大值
    int currentIndex;
};