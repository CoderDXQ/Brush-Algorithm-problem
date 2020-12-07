//二叉树的静态实现是指用普通栈来代替二叉树操作中用到的递归栈
//静态二叉树的实现是指用数组来存放二叉树节点 二叉树的操作可以借助递归
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data, left, right;
    Node()
    {
        left = right = -1;
    }
} node[10];

void init()
{
    node[1].data = 1;
    node[1].left = 2;
    node[1].right = 3;
    node[2].data = 7;
    node[2].left = 4;
    node[2].right = -1;
    node[3].data = 4;
    node[3].left = -1;
    node[3].right = 5;
    node[4].data = 5;
    node[4].left = -1;
    node[4].right = -1;
    node[5].data = 2;
    node[5].left = -1;
    node[5].right = -1;
}

void preOrder(int root)
{
    if (root == -1)
        return;

    cout << node[root].data << " ";
    preOrder(node[root].left);
    preOrder(node[root].right);
}

void inOrder(int root)
{
    if (root == -1)
        return;

    inOrder(node[root].left);
    cout << node[root].data << " ";
    inOrder(node[root].right);
}

void postOrder(int root)
{
    if (root == -1)
        return;

    postOrder(node[root].left);
    postOrder(node[root].right);
    cout << node[root].data << " ";
}

int main()
{
    init();
    int root = 1;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    return 0;
}