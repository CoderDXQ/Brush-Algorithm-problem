struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
    if(pRoot==nullptr)
        return;

    std::vector<int> path;
    int currentSum=0;
    FindPath(pRoot,expectedSum,path,currentSum);
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum,std::vector<int>& path,int currentSum)
{//递归一般将返回条件写在前面
    currentSum+=pRoot->m_nValue;
    path.push_back(pRoot->m_nValue);

    bool isLeaf=pRoot->m_pLeft==nullptr && pRoot->m_pRight==nullptr;

    if(currentSum==expectedSum && isLeaf)
    {//是叶节点并且符合输出条件
        printf("A path is found:");
        std::vector<int>::iterator iter=path.begin();
        for(;iter!=path.end();iter++)
            printf("%d\t",*iter);

        printf("\n");
    }

    if(pRoot->m_pLeft!=nullptr)
        FindPath(pRoot->m_pLeft,expectedSum,path,currentSum);
    if(pRoot->m_pRight!=nullptr)
        FindPath(pRoot->m_pRight,expectedSum,path,currentSum);

    path.pop_back();//类似于回溯 currentSum不需要更改，因为节点的值可能为负值
}