//二叉搜索树的中序遍历是一个有序序列
struct BinaryTreeNode
{
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    int m_nValue;
};

BinaryTreeNode* KthNode(BinaryTreeNode* pRoot,unsigned int k)
{
    if(pRoot==nullptr||k==0)
        return nullptr;
    //这个函数的作用就是增强健壮性
    return KthNodeCore(pRoot,k);
}

//改写中序遍历
BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot,unsigned int& k)
{
    BinaryTreeNode* target=nullptr;

    if(pRoot->m_pLeft!=nullptr)
        target=KthNodeCore(pRoot->m_pLeft,k);

    if(target==nullptr)
    {
        if (k==1)
            target=pRoot;
        k--;
    }

    if(target==nullptr && pRoot->m_pRight!=nullptr)//加了剪枝条件
        target=KthNodeCore(pRoot->m_pRight,k);

    return target;
}




