struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void MirrorRecursively(BinaryTreeNode* pNode)
{//更改一个先序遍历即可
    if(pNode==nullptr)
        return;//健壮性
    if(pNode->m_pLeft==nullptr && pNode->m_pRight==nullptr)
        return;//叶节点不需要镜像
    
    BinaryTreeNode* pTemp=pNode->m_pLeft;
    pNode->m_pLeft=pNode->m_pRight;
    pNode->m_pRight=pTemp;//镜像

    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);
    
    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}



