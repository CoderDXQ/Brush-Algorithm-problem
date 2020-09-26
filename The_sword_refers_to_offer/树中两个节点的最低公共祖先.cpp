//这个树不是二叉树，可能是N叉树

//N叉树的数据结构如下

#include<bits/stdc++.h>//用于消除下面代码中的爆红

struct TreeNode
{
    vector<TreeNode*> m_vChildren;//存储子节点的指针
    typedef value;
}

TreeNode* GetLastCommonParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
        return nullptr;
    
    list<TreeNode*> path1;
    GetNodePath(pRoot,pNode1,pNode1);//找到第一条路径

    list<TreeNode*> path2;
    GetNodePath(pRoot,pNode2,pNode2);//找到第二条路径

    return GetLastCommonNode(path1,path2);//找到两条路径的交点
}


bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)//pNode是目标节点 pRoot可以认为是当前节点
{//从某个节点向上找路直到根节点  这个过程类似于先序遍历
    if(pRoot==pNode)
        return true;//找到了目标节点

    path.push_back(pRoot);//把当前节点放进路径

    bool found=false;

    vector<TreeNode*>::iterator i=pRoot->m_vChildren.begin();
    while(!found && i<pRoot->m_vChildren.end())
    {//这其实是一个DFS的过程 找到目标节点之后就会一层一层返回
        found=GetNodePath(*i,pNode,path);
        i++;
    }

    if(!found)//程序走到这里说明该节点的所有子节点都扫描过了 从该节点经过不可能找到目标节点 应该从路径中剔除
        path.pop_back();//这个步骤类似于回溯

    return found;
}

TreeNode* GetLastCommonNode(const list<TreeNode*>& path1,const list<TreeNode*>& path2)
{
    list<TreeNode*>::const_iterator iterator1=path1.begin();
    list<TreeNode*>::const_iterator iterator2=path2.begin();

    TreeNode* pLast=nullptr;

    while(iterator1!=path1.end()&&iterator2!=path2.end())
    {//从路径的前面往后走
        if(*iterator1 == *iterator2)
            pLast=*iterator1;
        else
        {//剪枝
            break;
        }
        
        iterator1++;
        iterator2++;
    }
    return pLast;//返回最后一个
}

