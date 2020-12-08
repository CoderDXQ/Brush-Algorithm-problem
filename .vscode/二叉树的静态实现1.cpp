#include <bits/stdc++.h>
using namespace std;

typedef char elemBTree;

struct BTNode
{
    elemBTree data;
    BTNode *lchild, *rchild;
};

typedef BTNode *BTree;
typedef BTNode *elemStack;
struct sNode
{
    elemStack data;
    sNode *next;
};
typedef sNode *linklist;
void initStack(linklist &ls);
void push(linklist &ls, elemStack data);
void pop(linklist &ls);
elemStack getTop(linklist ls);
bool isEmpty(linklist ls);
bool isFull(linklist ls);

void preCreateBT(BTree &bt);
// 必須要有const
void preOrder(const BTree &bt);
void inCreateBT(BTree &bt);
void inOrder(const BTree &bt);
void visit(BTNode *node);
void postOrder(const BTree &bt);

int main()
{
    BTree bt;
    cout << "先序创建二叉树：";
    preCreateBT(bt);
    cout << "先序遍历二叉树(非递归): ";
    preOrder(bt);
    cout << "\n中序遍历二叉树(非递归): ";
    inOrder(bt);
    cout << "\n后序遍历二叉树(非递归): ";
    postOrder(bt);
    cout << endl;

    return 0;
}

void initStack(linklist &ls)
{
    ls = NULL;
}

void push(linklist &ls, elemStack data)
{
    if (!isFull(ls))
    {
        sNode *newNode = new sNode;
        newNode->data = data;
        newNode->next = ls;
        ls = newNode;
    }
    else
        cout << "栈已满，无法入栈";
}

void pop(linklist &ls)
{
    if (!isEmpty(ls))
    {
        sNode *delNode = new sNode;
        delNode = ls;
        ls = ls->next;
        delete delNode;
    }
    else
    {
        cout << "栈空，无法出栈";
    }
}

elemStack getTop(linklist ls)
{
    return ls->data;
}

bool isEmpty(linklist ls)
{
    if (ls == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(linklist ls)
{
    sNode *newNode = new sNode;
    if (newNode)
    {
        delete newNode;
        return false;
    }
    else
    {
        delete newNode;
        return true;
    }
}

void preCreateBT(BTree &bt)
{
    elemBTree elem;
    cin >> elem;
    if (elem == '#')
    {
        bt = NULL;
    }
    else
    {
        bt = new BTNode;
        bt->data = elem;
        preCreateBT(bt->lchild);
        preCreateBT(bt->rchild);
    }
}

void preOrder(const BTree &bt)
{
    BTNode *node = bt;
    linklist ls;
    initStack(ls);

    while (node || !isEmpty(ls))
    {
        while (node)
        {
            visit(node);
            if (node->rchild)
            {
                // 直接把右子树放进去
                push(ls, node->rchild);
            }
            node = node->lchild;
        }
        if (!isEmpty(ls))
        {
            node = getTop(ls);
            pop(ls);
        }
    }
}

void inOrder(const BTree &bt)
{
    BTNode *node = bt;
    linklist ls;
    initStack(ls);

    while (node || !isEmpty(ls))
    {
        while (node)
        {
            push(ls, node);
            node = node->lchild;
        }
        if (!isEmpty(ls))
        {
            node = getTop(ls);
            visit(node);
            pop(ls);
            // 加个if？？？
            node = node->rchild;
        }
    }
}

void postOrder(const BTree &bt)
{
    BTNode *node = bt;
    BTNode *pre = NULL;

    linklist ls;
    initStack(ls);

    while (node || !isEmpty(ls))
    {
        while (node)
        {
            push(ls, node);
            node = node->lchild;
        }

        if (!isEmpty(ls))
        {
            node = getTop(ls);
            if ((node->rchild == NULL) || (node->rchild == pre))
            {
                visit(node);
                pop(ls);
                pre = node;
                node = NULL;
            }
            else
            {
                node = node->rchild;
            }
        }
    }
}

void visit(BTNode *node)
{
    cout << node->data;
}