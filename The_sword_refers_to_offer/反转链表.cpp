struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

ListNode* ReverseList(ListNode* pHead)
{
    if(pHead==nullptr || pHead->m_pNext==nullptr)
        return pHead;//健壮性

    ListNode* pReversedHead=nullptr;//反转后的头节点
    ListNode* pNode=pHead;
    ListNode* pPrev=nullptr;//已经反转的串的头节点

    while(pNode!=nullptr)
    {
        ListNode* pNext=pNode->m_pNext;//储存 不然会丢失

        if(pNext == nullptr)//到达最后一个
            pReversedHead=pNode;
//这里需要重点理解一下
        pNode->m_pNext=pPrev;
        pPrev=pNode;
        pNode=pNext;
    }
    return pReversedHead;
}
















