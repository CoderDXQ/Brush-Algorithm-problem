struct BinaryTreeNode
{
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    int m_nValue;
};

int TreeDepth(BinaryTreeNode* pRoot)
{
    if(pRoot==nullptr)
        return 0;
    
    int nLeft=TreeDepth(pRoot->m_pLeft);
    int nRight=TreeDepth(pRoot->m_pRight);

//左右子树哪个深就按哪个算
    return (nLeft>nRight)?(nLeft+1):(nRight+1);
}