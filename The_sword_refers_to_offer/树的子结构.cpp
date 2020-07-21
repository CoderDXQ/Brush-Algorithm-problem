struct BinaryTreeNode
{
    double m_dbValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

bool HasSubtree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
    bool result=false;
//传进来的两个节点如果有一个为空 那么直接输出false  这里默认空树不是任何树的子树
    if(pRoot1!=nullptr && pRoot2!=nullptr)
    {//顺序类似先根遍历
        if(Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))
            result=DoesTree1HaveTree2(pRoot1,pRoot2);
        if(!result)
            result=HasSubtree(pRoot1->m_pLeft,pRoot2);
        if(!result)
            result=HasSubtree(pRoot1->m_pRight,pRoot2);
    }

    return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{//本质上是DFS
    if(pRoot2==nullptr)
        return true;//特判

    if(pRoot1==nullptr)
        return false;//特判  
    
    if(!Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))
        return false;

//走到这里说明此时的根节点值相同 继续比较两个子节点
    return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}

bool Equal(double num1,double num2)
{
    if((num1-num2>-0.0000001)&&(num1-num2<0.0000001))
        return true;//用于比较浮点数 计算机内表示小数时都有误差 用这个方法可以避免这个问题
    else
        return false;
}


















