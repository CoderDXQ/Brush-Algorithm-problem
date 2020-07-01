//包含序列化和反序列化两个部分
//这个方法将nullptr指针变为$后，原来的树实际上变为一颗满二叉树
//满二叉树的国际定义：除叶子节点外，每个节点都有两个子节点
struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};


//前序遍历的方法
void Serialize(BinaryTreeNode* pRoot,ostream& stream)//序列化
{//前序遍历可以，后序遍历也可以
    if(pRoot==nullptr)
    {
        stream<<"$,";//???输出流的代码需要执行一下看看效果
        return;//有一定的剪枝效果
    }
//实质上是前序遍历
    stream<<pRoot->m_nValue<<',';
    Serialize(pRoot->m_pLeft,stream);
    Serialize(pRoot->m_pRight,stream);
}

void Deserialize(BinaryTreeNode** pRoot,istream& stream)//反序列化
{
    int number;
    if(ReadStream(stream,&number))//这个函数可能只能把数字读进number，$读进number时会变为nullptr
    {
        *pRoot=new BinaryTreeNode();
        (*pRoot)->m_nValue=number;
        (*pRoot)->m_pLeft=nullptr;
        (*pRoot)->m_pRight=nullptr;
        
        Deserialize(&((*pRoot)->m_pLeft),stream);
        Deserialize(&((*pRoot)->m_pRight),stream);
    }
}



//？？？？？？再写一个后序遍历的方法
void Serialize(BinaryTreeNode* pRoot,ostream& stream)
{
//????????????????????????????????????????????????????

}
void Deserialize(BinaryTreeNode** pRoot,istream& stream)
{
//????????????????????????????????????????????????????

}








































