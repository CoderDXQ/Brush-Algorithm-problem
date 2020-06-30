//两种方法，一种是以空间换时间，另外使用哈希，走两趟即可
//第二种是在原链表的每个节点后面接一个新链表，类似于DNA的复制

//第二种方法 这种方法要走三遍，但是不使用额外的空间
struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;//顺序指针
    ComplexListNode* m_pSibling;//随机指针
};

void CloneNodes(ComplexListNode* pHead)
{//复制节点的顺序关系
    ComplexListNode* pNode=pHead;
    while(pNode!=nullptr)
    {
        ComplexListNode* pCloned=new ComplexListNode();
        pCloned->m_nValue=pNode->m_nValue;
        pCloned->m_pNext=pNode->m_pNext;
        pCloned->m_pSibling=nullptr;

        pNode->m_pNext=pCloned;

        pNode=pCloned->m_pNext;
    }
}

void ConnectSiblingNodes(ComplexListNode* pHead)
{//复制节点的随机关系
    ComplexListNode* pNode=pHead;

    while(pNode!=nullptr)
    {
        ComplexListNode* pCloned=pNode->m_pNext;
        if(pNode->m_pSibling!=nullptr)
        {
            pCloned->m_pSibling=pNode->m_pSibling->m_pNext;
        }

        pNode=pCloned->m_pNext;
    }
}

ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{//复制完成，进行抽离 这个函数只对顺序指针进行操作
    ComplexListNode* pNode=pHead;
    ComplexListNode* pClonedHead=nullptr;
    ComplexListNode* pClonedNode=nullptr;

    if(pNode!=nullptr)//首先进行头节点的抽离
    {
        pClonedHead=pClonedNode=pNode->m_pNext;
        pNode->m_pNext=pClonedNode->m_pNext;//分离、连接
        pNode=pNode->m_pNext;//移动
    }

    //随后进行其他节点的抽离
    while(pNode!=nullptr)
    {
        pClonedNode->m_pNext=pNode->m_pNext;//分离、连接
        pClonedNode=pClonedNode->m_pNext;//指针移动
        pNode->m_pNext=pClonedNode->m_pNext;//分离、连接
        pNode=pNode->m_pNext;//指针移动

    }

    return pClonedHead;
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return ReconnectNodes(pHead);
}

//第一种方法
//？？？？？？有时间写写第一种，需要遍历两次原始链表
//第一趟，每走一个原始链表节点就在新链表加上一个节点，并且把原始链表的节点和新链表的节点建立哈希关系或者其他对应关系
//第一趟只复制顺序关系，第二趟复制随机关系
//第二趟，从原始节点头节点开始复制随机关系，使用第一趟建立的关系可以快速找到新链表随机指针的值
//？？？？？？在下面添加代码