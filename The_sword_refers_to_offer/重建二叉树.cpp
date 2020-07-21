//二叉树的问题一般都可以用递归来解决
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* lchild;
    BinaryTreeNode* rchild;
};

//前序、中序构建二叉树
BinaryTreeNode* Construct(int* preorder,int* inorder,int length)
{
    if(preorder==nullptr||inorder==nullptr||length<0)
        return nullptr;//健壮性
    
    return ConstructCore(preorder,preorder+length-1,inorder,inorder+length-1);
}

//建树
BinaryTreeNode* ConstructCore(int* startPreorder,int* endPreorder,int* startInorder,int* endInorder)
{
    int rootValue=startPreorder[0];//前序遍历数组的第一个节点是根
    BinaryTreeNode* root=new BinaryTreeNode();
    root->value=rootValue;
    root->rchild=root->lchild=nullptr;

    if(startPreorder==endPreorder)
    {//只剩下最后一个元素
        if(startInorder==endInorder && *startInorder==*startPreorder)
            return root;
        else//健壮性
            throw std::exception("Invalid input.");
    }
    //在中序遍历数组中寻找下一个根节点并分组构建左右子树
    int* rootInorder=startInorder;
    while(rootInorder<=endInorder && *rootInorder!=rootValue)
    {
        ++rootInorder;
    }

    if(rootInorder==endInorder && *rootInorder!=rootValue)
    {//健壮性
        throw std::exception("Invalid input.");
    }
    
    int leftLength=rootInorder-startInorder;
    int *leftPreorderEnd=startPreorder+leftLength;
    if(leftLength>0)
    {//左子树
        root->lchild=ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
    }
    if(leftLength<endPreorder-startPreorder)
    {//右子树
        root->rchild=ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
    }

    return root;
}