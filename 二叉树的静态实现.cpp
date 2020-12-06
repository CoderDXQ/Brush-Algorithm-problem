#include <bits/stdc++.h>
using namespace std;

enum  Tag{left,right};

typedef


typedef struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
} BTNode;

void InOrderWithoutRecursion(BTNode *root);
void PreOrderWithoutRecursion(BTNode *root);
void PreOrderWithoutRecursion1(BTNode *root);
void PostOrderWithoutRecursion(BTNode *root);

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
            cout << setw(4) << p - data;
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
    while (!s.empty)
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
                s.push(pCur)
                    pCur = pCur->lchild;
            }
        }
    }
}
