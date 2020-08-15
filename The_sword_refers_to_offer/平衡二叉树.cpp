//当一棵树的每一个节点的左右子树的高度差都不超过1时，这棵树是平衡二叉树
struct BinaryTreeNode
{
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    int m_nValue;
};

//方法一：从上到下遍历节点并进行检查，这样子节点会被多次访问，时间复杂度高
int TreeDepth(BinaryTreeNode* pRoot)
{//用于计算树的深度的函数
    if(pRoot==nullptr)
        return 0;
    
    int nLeft=TreeDepth(pRoot->m_pLeft);
    int nRight=TreeDepth(pRoot->m_pRight);

//左右子树哪个深就按哪个算
    return (nLeft>nRight)?(nLeft+1):(nRight+1);
}

bool IsBalanced(BinaryTreeNode* pRoot)
{
    if(pRoot==nullptr)
        return true;//认为空树是平衡二叉树
    
    int left=TreeDepth(pRoot->m_pLeft);//计算左子树的深度
    int right=TreeDepth(pRoot->m_pRight);//计算右子树的深度
    int diff=left-right;//计算左右子树的高度差
    if(diff>1 || diff<-1)
        return false;//判定为非平衡二叉树

    return IsBalanced(pRoot->m_pLeft) && IsBalanced(pRoot->m_pRight);//继续向下判定
}

//后序遍历：左右根的顺序可以保证在遍历到根节点时正好可以得到所有节点的平衡度（某个节点的左右子树的高度差）
bool IsBalanced(BinaryTreeNode* pRoot)
{
    int depth=0;
    return IsBalanced(pRoot,depth);
}
bool IsBalanced(BinaryTreeNode* pRoot,int* pDepth)
{//本质上是后序遍历
    if(pRoot==nullptr)
    {//对于叶子节点的处理
        *pDepth=0;
        return true;
    }

    int left,right;
    if(IsBalanced(pRoot->m_pLeft,&left)&&IsBalanced(pRoot->m_pRight,&right))//左右
    {//根
        int diff=left-right;
        if(diff>=-1 && diff<=1)//判定为平衡二叉树的条件
        {
            *pDepth=1+max(right,left);
            return true;//这个返回是给递归过程中上一层的if语句使用的
        }
    }
    //在二叉树的某个节点不满足if中的条件时，说明不是平衡二叉树，则跳过if语句直接返回下面的false，此时已经不满足上一层if语句，递归不再继续向下进行会一层层的返回false
    return false;
}






