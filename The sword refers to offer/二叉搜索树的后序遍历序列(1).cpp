//这是一个存在性问题，因此只要能证明存在即可，无需找出所有存在的可能
//为什么这里是二叉搜索树而不是普通二叉树，因为搜索树本身的性质也是本题的一个重要条件
//二叉搜索树的特点是 根节点的左子树的所有节点全都小于根节点，右子树的所有节点全都大于根节点
bool VerifySquenceOfBST(int sequence[],int length)
{//用递归的思想分解问题
    if(sequence==nullptr || length<=0)
        return false;

    int root=sequence[length-1];

    int i=0;
    for(;i<length-1;i++)
    {
        if(sequence[i]>root)
            break;
    }//此时i是右子树的第一个节点，左子树可以为空

    int j=i;
    for(;j<length-1;j++)
    {
        if(sequence[j]<root)
            return false;//二叉搜索树的右子树的所有节点全都大于根节点
    }

//能走到这说明这个层次的右子树符合条件
    bool left=true;//继续向更深层次检查
    if(i>0)//左子树非空
        left=VerifySquenceOfBST(sequence,i);//此时i刚好是数组长度

    bool right=true;
    if(i<length-1)
        right=VerifySquenceOfBST(sequence+i,length-i-1);

    return (left && right);
}