//思路：先检查是否存在环 存在环的用
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

//快慢法检查是否存在环
ListNode* MeetingNode(ListNode* pHead)
{
    if(pHead == nullptr)//链表中没有节点
        return nullptr;

    ListNode* pSlow=pHead->m_pNext;
    if(pSlow == nullptr)
        return nullptr;//链表中只有一个节点

    ListNode* pFast=pSlow->m_pNext;
    while(pFast!=nullptr && pSlow!=nullptr)
    {
        if(pFast == pSlow)
            return pFast;//相遇则说明有环

//运行到这里说明快慢指针不相同
        pSlow=pSlow->m_pNext;
        pFast=pFast->m_pNext;
//再次加快一步
        if(pFast != nullptr)//走得快的加快一下 如果存在环的话 由于这个操作的存在 最后一定会出现相遇的情况
            pFast=pFast->m_pNext;

    }
    return nullptr;
}

//前后法找出环的入口节点
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetingNode=MeetingNode(pHead);
    if(meetingNode==nullptr)
        return nullptr;//无环 代码健壮性

    int nodesInLoop=1;
    ListNode* pNode1=meetingNode;
    while(pNode1->m_pNext!=meetingNode)
    {
        pNode1=pNode1->m_pNext;
        nodesInLoop++;//计数环的长度
    }

    pNode1=pHead;
    for(int i=0;i<nodesInLoop;i++)
        pNode1=pNode1->m_pNext;

    ListNode* pNode2=pHead;
    while(pNode1!=pNode2)//相等时说明两个前后指针在同一处 即为环的入口节点
    {
        pNode1=pNode1->m_pNext;
        pNode2=pNode2->m_pNext;
    }
    return pNode1;
}

//如果一上来就用哈希法就不用这么麻烦了 判断存在环的同时也找到环的入口节点
//哈希法：从头节点遍历链表，将每个节点的地址进行哈希，如果在遍历过程中命中哈希，那么这个点就是入口节点









