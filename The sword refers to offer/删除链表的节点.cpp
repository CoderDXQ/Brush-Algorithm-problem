struct  ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

//给定了指针可以直接删除节点 不需要从头查找要删除的元素在哪
void DeleteNode(ListNode** pListHead,ListNode* pToBeDelete)
{
    if(!pListHead || !pToBeDelete)
        return;//防止非法输入 增强健壮性

    if(pToBeDelete->m_pNext!=nullptr)
    {//要删除的节点不在末尾
        ListNode* pNext=pToBeDelete->m_pNext;
        pToBeDelete->m_nValue=pNext->m_nValue;
        pToBeDelete->m_pNext=pNext->m_pNext;
        delete pNext;
        pNext=nullptr;
    }
    else if(*pListHead==pToBeDelete)
    {//只有一个节点
        delete pToBeDelete;
        pToBeDelete=nullptr;
        *pListHead=nullptr;
    }
    else
    {//要删除的节点在末尾
        ListNode* pNode=*pListHead;
        while(pNode->m_pNext!=pToBeDelete)
        {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=nullptr;
        //防止内存泄漏
        delete pToBeDelete;
        pToBeDelete=nullptr;
    }
    
}
