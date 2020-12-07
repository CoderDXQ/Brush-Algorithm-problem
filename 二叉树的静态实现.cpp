//二叉树的静态实现是指用普通栈来代替二叉树操作中用到的递归栈
//静态二叉树的实现是指用数组来存放二叉树节点 二叉树的操作可以借助递归

#include <bits/stdc++.h>
using namespace std;

enum Tag
{
    left,
    right
};

typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

typedef struct
{
    BTNode *node;
    Tag tag;

} TagNode;

void InOrderWithoutRecursion(BTNode *root);
void PreOrderWithoutRecursion(BTNode *root);
void PreOrderWithoutRecursion1(BTNode *root);
void PostOrderWithoutRecursion(BTNode *root);
void PostOrderWithoutRecursion1(BTNode *root);

int main()
{

    return 0;
}

void InOrderWithoutRecursion(BTNode *root)
{
    if (root == NULL)
        return;
    BTNode *p = root;
    stack<BTNode *> s;

    while (!s.empty() || p)
    {
        while (p)
        {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty())
        {
            p = s.top();
            s.pop();
            cout << setw(4) << p->data;
            p = p->rchild;
        }
    }
}

void PreOrderWithoutRecursion(BTNode *root)
{
    if (root == NULL)
        return;

    BTNode *p = root;
    stack<BTNode *> s;
    while (!s.empty() || p)
    {
        while (p)
        {
            cout << setw(4) << p->data;
            //放到栈中是为了拿到当时的右节点
            s.push(p);
            p = p->lchild;
        }

        if (!s.empty())
        {
            p = s.top();
            s.pop();
            p = p->rchild;
        }
    }
}

void PreOrderWithoutRecursion1(BTNode *root)
{
    if (root == NULL)
        return;

    BTNode *p = root;
    stack<BTNode *> s;

    while (!s.empty())
    {
        cout << setw(4) << p->data;

        if (p->rchild)
            s.push(p->rchild);

        if (p->lchild)
        {
            p = p->lchild;
        }
        else
        {
            p = s.top();
            s.pop();
        }
    }
}

void PostOrderWithoutRecursion(BTNode *root)
{
    if (root == NULL)
        return;

    BTNode *pCur = root;
    BTNode *pLastVisit = NULL;
    stack<BTNode *> s;

    while (pCur)
    {
        s.push(pCur);
        pCur = pCur->lchild;
    }
    while (!s.empty())
    {
        pCur = s.top();
        s.pop();

        if (pCur->rchild == NULL || pCur->rchild == pLastVisit)
        {
            cout << setw(4) << pCur->data;
            pLastVisit = pCur;
        }
        else
        {
            s.push(pCur->rchild);
            pCur = pCur->rchild;
            while (pCur)
            {
                s.push(pCur);
                pCur = pCur->lchild;
            }
        }
    }
}

void PostOrderWithoutRecursion1(BTNode *root)
{

    if (root == NULL)
        return;

    stack<TagNode> s;
    TagNode tagnode;
    BTNode *p = root;

    while (!s.empty() || p)
    {
        while (p)
        {
            tagnode.node = p;
            tagnode.tag = Tag::left;
            s.push(tagnode);
            p = p->lchild;
        }
        tagnode = s.top();
        s.pop();

        if (tagnode.tag == Tag::left)
        {
            tagnode.tag = Tag::right;
            s.push(tagnode);
            p = tagnode.node->rchild;
        }
        else
        {
            cout << setw(4) << tagnode.node->data;
            p = NULL;
        }
    }
}
