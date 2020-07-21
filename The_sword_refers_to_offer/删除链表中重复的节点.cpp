struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};

void DeleteDuplication(ListNode** pHead)
{
    if(pHead==nullptr || *pHead==nullptr)
        return;

    ListNode* pPreNode=nullptr;
    ListNode* pNode=*pHead;
    while (pNode!=nullptr)
    {
        ListNode* pNext=pNode->m_pNext;
        bool needDelete=false;//标志
        if(pNext!=nullptr && pNext->m_nValue==pNode->m_nValue)
            needDelete=true;//检查是否重复

        if(!needDelete)
        {//不需要删除 pNode往后移
            pPreNode=pNode;
            pNode=pNode->m_pNext;
        } 
        else
        {
            int value=pNode->m_nValue;
            ListNode* pToBedel=pNode;
            while ( pToBeDel!=nullptr && pToBeDel->m_nValue==value)
            {//不只两个需要删除
                pNext=pToBedel->m_pNext;

                delete pToBedel;
                pToBedel=nullptr;//必须要有的删除操作 不然会造成内存泄漏

                pToBedel=pNext;
            }
            if(pPreNode==nullptr)//一上来就有重复的会引起头节点的变化
                *pHead=pNext;
//变化是永久的 因为传进来的是二维指针 *pHead是二维指针的值即二维指针所指的内存的值
            else
                pPreNode->m_pNext=pNext;//接上

            pNode=pNext;//外层while循环需要
        }   
    }
}
