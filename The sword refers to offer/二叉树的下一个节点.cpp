struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* lchild;
    BinaryTreeNode* rchild;
    BinaryTreeNode* parent;
};

//以pNode为根节点继续进行中序遍历 



BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if(pNode==nullptr)
        return nullptr;

    BinaryTreeNode* pNext=nullptr;
    if(pNode->rchild!=nullptr)
    {//若pNode有右子树 则下一个节点是右子树的最左侧节点(若该右子树无左子树 则返回该右子树的根节点)
        BinaryTreeNode* pRight=pNode->rchild;//右子树的根节点
        while(pRight->lchild!=nullptr)
            pRight=pRight->lchild;
        //此时pRight代表右子树的最左侧
        pNext=pRight;
    }
    else if(pNode->parent!=nullptr)
    {
//若pNode没有右子树，且pNode是其父节点的左子树 则下一个节点是父节点
//若pNode没有右子树，且pNode是其父节点的右子树 这代表要由其父节点向上回溯(一个左根右结束) 知道这可越来越大的树是某个节点的左子树 则所求的下一个节点就是这个节点
        BinaryTreeNode* pCurrent=pNode;
        BinaryTreeNode* pParent=pNode->parent;
        while(pParent!=nullptr && pCurrent==pParent->rchild)
        {
            pCurrent=pParent;
            pParent=pParent->parent;
        }
        pNext=pParent;
    }
    
    return pNext;
}