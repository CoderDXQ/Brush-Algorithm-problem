vector<int>maxInWindows(const vector<int>& num,unsigned int size)
{
    vector<int> maxInWindows;
    if(num.size()>=size && size>=1)
    {
        deque<int> index;

        for(unsigned int i=0;i<size;i++)//初始化窗口 
        {//滑动队列中来了个比较大的，需要排空滑动窗口
            while (!index.empty() && num[i]>=num[index.back()])
                index.pop_back();
            
            index.push_back(i);//放入下标数据
        }

        //继续执行
        for(unsigned int i=size;i<num.size();i++)
        {
            maxInWindows.push_back(num[index.front()]);//保存每个滑动窗口的最大值

            while (!index.empty() && num[i]>=num[index.back()])
                index.pop_back();//滑动队列中来了个比较大的，需要排空滑动窗口
                
            if(!index.empty() && index.front()<=(int)(i-size))//处理划出窗口的数字 i-size是滑动窗口中最左侧数字的下标
                index.pop_front();//窗口向后移

            index.push_back(i);
        }
        maxInWindows.push_back(num[index.front()]);
    }
    return maxInWindows;
}