struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};
//原理：两种遍历方法，一种是根左右，一种是根右左。如果两个遍历序列是一样的，那么这颗二叉树即是对称的
//这个原理利用了二叉树天然的对称性

bool isSymmetrical(BinaryTreeNode* pRoot)
{
    return isSymmetrical(pRoot,pRoot);//虽然函数名一样 但这是两个函数
}

bool isSymmetrical(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{//直接在遍历的过程中比较
    if(pRoot1==nullptr && pRoot2==nullptr)
        return true;
    
    if(pRoot1==nullptr || pRoot2==nullptr)
        return false;//能执行到这里 pRoot1和pRoot2不可能同时为nullptr

    if(pRoot1->m_nValue!=pRoot2->m_nValue)
        return false;
    return isSymmetrical(pRoot1->m_pLeft,pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight,pRoot2->m_pLeft);

}