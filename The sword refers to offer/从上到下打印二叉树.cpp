struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

//不分行从上到下打印二叉树
void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
    if(!pTreeRoot)
        return;
    
    std::deque<BinaryTreeNode*> dequeTreeNode;

    dequeTreeNode.push_back(pTreeRoot);
    
    while (dequeTreeNode.size())
    {
        BinaryTreeNode* pNode=dequeTreeNode.front();
        dequeTreeNode.pop_front();

        printf("%d",pNode->m_nValue);

        if(pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);

        if(pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
}


//分行从上到下打印二叉树
void Print(BinaryTreeNode* pRoot)
{
    if(pRoot==nullptr)
        return;

    std::queue<BinaryTreeNode*> nodes;
    nodes.push(pRoot);
    int nextLevel=0;//下一层的节点个数
    int toBePrinted=1;//记录某一层应该被打印的节点的个数

    while (!nodes.empty())
    {
        BinaryTreeNode* pNode=nodes.front();
        print("%d",pNode->m_nValue);

        if(pNode->!=nullptr)
        {
            nodes.push(pNode->m_pLeft)
            ++nextLevel;
        }
        if(pNode->m_pRight!=nullptr)
        {
            nodes.push(pNode->m_pRight);
            ++nextLevel;
        }

        nodes.pop();
        --toBePrinted;

        if(toBePrinted==0)
        {
            Print("\n");
            toBePrinted=nextLevel;
            nextLevel=0;//这个方法不需要在定义节点的结构体中家变量，从而节省内存
        }
    }
}

//之字形打印二叉树
//除了下面这种方法，也可以改改上面的方法实现（只增加一个stack和一个信号量）
void Print(BinaryTreeNode* pRoot)
{
    if(pRoot==nullptr)
        return;

    std::stack<BinaryTreeNode*>level[2];//元素是栈的数组,类似于动态数组
    int current=0;
    int next=1;

    levels[current].push(pRoot);
    while (!level[0].empty() || !level[1].empty())
    {
        BinaryTreeNode* pNode=level[current].top();
        level[current].pop();

        print("%d",pNode->m_nValue);

        if(current==0)
        {
            if(pNode->m_pLeft!=nullptr)
                level[next].push(pNode->m_pLeft);
            if(pNode->m_pRight!=nullptr)
                level[next].push(pNode->m_pRight);
        }
        else
        {//换方向存储
            if(pNode->m_pRight!=nullptr)
                level[next].push(pNode->m_pRight);
            if(pNode->m_pLeft!=nullptr)
                level[next].push(pNode->m_pLeft);
        }
        if(level[current].empty())//此时应该换方向了
        {
            print("\n");
            current=1-current;//0-1互换操作
            next=1-next;
        }
    }
}



