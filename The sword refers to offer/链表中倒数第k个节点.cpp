struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;//结构体的类型决定了对链表的遍历只能是单向的
};

//两个指针呢同时走可以实现遍历一次完成任务
//当一个指针走到头之后，就有手段将链表转换为数组，此时可以根据下标实现快速查询，这种方法在大量查询时有效
//但是这里只需要查询一次
//假设链表足够长，那么倒数第k个节点，即为正数第n-k+1个节点 下表从1开始计数
//那么第一个节点走k-1步之后第二个节点（开始指向头节点）开始走，两个节点一起走 
//当第一个节点走到最后之后第二个节点刚好走了n-k+1，此时第二个节点的位置就是倒数第k个节点
ListNode* FindKthToTail(ListNode* pListHead,unsigned int k)
{
    if(pListHead == nullptr || k == 0)
    {
        return nullptr;
    }

    ListNode* pAHead=pListHead;
    ListNode* pBehind=nullptr;

    for(unsigned int i=0;i<k-1;i++)
    {
        if(pAHead->m_pNext != nullptr)
        {
            pAHead=pAHead->m_pNext;
        }
        else
        {
            return nullptr;
        }
    }

    pBehind=pListHead;

    while(pAHead->m_pNext!=nullptr)
    {
        pAHead=pAHead->m_pNext;
        pBehind=pBehind->m_pNext;
    }
    return pBehind; 
}