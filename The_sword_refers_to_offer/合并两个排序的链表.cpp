struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};

ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1==nullptr)
        return pHead2;
    else if(pHead2==nullptr)
        return pHead1;

    ListNode* pMergedHead=nullptr;

    if(pHead1->m_nKey<pHead2->m_nKey)
    {
        pMergedHead=pHead1;
        pMergedHead->m_pNext=Merge(pHead1->m_pNext,pHead2);
    }
    else
    {
        pMergedHead=pHead2;
        pMergedHead->m_pNext=Merge(pHead1,pHead2->m_pNext);
    }
    return pMergedHead;
}