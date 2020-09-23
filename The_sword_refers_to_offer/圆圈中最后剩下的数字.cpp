//约瑟夫环问题

//方法一：环形链表模拟
int LastRemaining(unsigned int n,unsigned int m)
{
    if(n<1 || m<1)
        return -1;

    unsigned int i=0;

    list<int> numbers;
    for(int i=0;i<n;i++)
        numbers.push_back(i);//往模拟链表中加数
    
    list<int>::iterator current=numbers.begin();//current是指针

    while(numbers.size()>1)
    {
        for(int i=1;i<m;i++)
        {
            current++;
            if(current==numbers.end())//成环
                current=numbers.begin();
        }

//从for循环出来恰好走了m-1个节点 下一个节点就是要删除的节点
        list<int>::iterator next=++current;

        if(next==numbers.end())
            next=numbers.begin();

        --current;
        numbers.erase(current);
        current=next;
    }

    return *(current);
}


//方法二：建立数学模型 相对位置逆序求解

int LastRemaining(unsigned int n,unsigned int m)
{
    if(n<1 || m<1)
        return -1;

    int last=0;
    for(int i=2;i<=n;i++)//因为最后都是剩下一个数字且链表是环形，所以没有正反向的区别
        last=(last+m)%i;//计算每次的相对位置
    
    return last;
}

