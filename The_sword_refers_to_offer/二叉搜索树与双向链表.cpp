//二叉搜索树的中序遍历刚好是有序的
//二叉树有关的问题优先考虑分解问题，然后使用递归来解决

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList=nullptr;//也是值最大的节点
    ConvertNode(pRootOfTree,&pLastNodeInList);//传递地址的值

    BinaryTreeNode* pHeadOfList=pLastNodeInList;//返回来的是树最右边的节点(链表最右边的节点)
    while(pHeadOfList!=nullptr && pHeadOfList->m_pLeft!=nullptr)
        pHeadOfList=pHeadOfList->m_pLeft;//移动回树最左边的节点(链表最左边的节点)

    return pHeadOfList;
}

void ConvertNode(BinaryTreeNode* pNode,BinaryTreeNode** pLastNodeInList)
//使用双重指针可以避免递归返回时变量从栈中弹出，同时提高兼容性且每次都装进一个地址，pLastNodeInList相当于全局变量
{//中序遍历
    if(pNode==nullptr)
        return;//健壮性

    BinaryTreeNode* pCurrent=pNode;

    if(pCurrent->m_pLeft!=nullptr)//左
        ConvertNode(pCurrent->m_pLeft,pLastNodeInList);

//根 在这一部分中，头两条语句会有重复复值的情况发生
    pCurrent->m_pLeft=*pLastNodeInList;
    if(*pLastNodeInList!=nullptr)//先遍历到的节点小
        (*pLastNodeInList)->m_pRight=pCurrent;
    *pLastNodeInList=pCurrent;

    if(pCurrent->m_pRight!=nullptr)//右
        ConvertNode(pCurrent->m_pRight,pLastNodeInList);
}//这个函数最后弹出的节点是根节点 pLastNodeInList存的值是树最右边的节点




















