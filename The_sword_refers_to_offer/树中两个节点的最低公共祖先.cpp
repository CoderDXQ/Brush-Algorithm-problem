bool GetNodePath(TreeNode* pRoot,TreeNode* pNode,list<TreeNode*>& path)
{
    if(pRoot==pNode)
        return true;

    path.push_back(pRoot);

    bool found=false;

    vector<TreeNode*>::iterator i=pRoot->m_vChildren.begin();
    while(!found && i<pRoot->m_vChildren.end())
    {
        found=GetNodePath(*i,pNode,path);
        i++;
    }

    if(!found)
        path.pop_back();

    return found;
}

TreeNode* GetLastCommonNode(const list<TreeNode*>& path1,const list<TreeNode*>& path2)
{
    list<TreeNode*>::const_iterator iterator1=path1.begin();
    list<TreeNode*>::const_iterator iterator2=path2.begin();

    TreeNode* pLast=nullptr;

    while(iterator1!=path1.end()&&iterator2!=path2.end())
    {
        if(*iterator1 == *iterator2)
            pLast=*iterator1;

        iterator1++;
        iterator2++;
    }
    return pLast;
}

TreeNode* GetLastCommonParent(TreeNode* pRoot,TreeNode* pNode1,TreeNode* pNode2)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
        return nullptr;
    
    list<TreeNode*> path1;
    GetNodePath(pRoot,pNode1,pNode1);

    list<TreeNode*> path2;
    GetNodePath(pRoot,pNode2,pNode2);

    return GetLastCommonNode(path1,path2);

}




