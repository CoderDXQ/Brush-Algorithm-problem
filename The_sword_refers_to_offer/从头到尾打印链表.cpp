//节点结构体
struct ListNode
{
    int value;
    ListNode* next;
};

//尾插
void AddToTail(ListNode** pHead,int pvalue)
{//传入头指针的指针 如果要对头指针做变更那么就要更改头指针的指针所指向的内存里的数据
//直接改变头指针的值在出函数之后会失效 
//此外用双重指针是为了增强算法在不同环境下的健壮性 
//当然 该算法也可以使用单指针实现
    ListNode* pNew=new ListNode();
    pNew->value=pvalue;
    pNew->next=nullptr;//构造待插入的节点

    if(*pHead==nullptr)//头指针为空
    {
        *pHead=pNew;//头指针的值为pNew的值
    }
    else
    {
        ListNode* pNode=*pHead;
        while(pNode->next!=nullptr)
        {
            pNode=pNode->next;
        }//把指针移动到链表尾
        pNode->next=pNew;//尾插
    }
}


//删除节点
void RemoveNode(ListNode** pHead,int pvalue)
{
    if(pHead==nullptr||*pHead==nullptr)
       return;
     
    ListNode* pToBeDeleted=nullptr;
    if((*pHead)->value==pvalue)
    {//删除头结点
        pToBeDeleted=*pHead;
        *pHead=(*pHead)->next;
    }
    else
    {
        ListNode* pNode=*pHead;
        while (pNode->next!=nullptr && pNode->next->value!=pvalue)
        {
            pNode=pNode->next;
        }
        if(pNode->next!=nullptr && pNode->next->value==pvalue)
        {
            pToBeDeleted=pNode->next;
            pNode->next=pNode->next->next;
        }
    }

    if(pToBeDeleted!=nullptr)
    {//释放内存  防止内存泄漏
        delete pToBeDeleted;
        pToBeDeleted=nullptr;
    }
}

//逆序遍历打印
//方法一：利用栈来实现
void PrintListReversingly(ListNode* pHead)
{
    std::stack<ListNode*> nodes;//指针栈 节省空间 提高效率

    ListNode* pNode=pHead;
    while (pNode!=nullptr)
    {
        nodes.push(pNode);
        pNode=pNode->next;
    }
    
    while(!nodes.empty())
    {
        pNode=nodes.top();
        nodes.pop();
        print("%d\t",pNode->value);
    }
}
//用递归来实现
void PrintListReversing(ListNode* pHead)
{
    if(pHead!=nullptr)
    {
        if(pHead->next!=nullptr)
        {
            PrintListReversing(pHead->next);
        }
        printf("%d\t",pHead->value);
    }
}//缺点：容易出现栈溢出





























