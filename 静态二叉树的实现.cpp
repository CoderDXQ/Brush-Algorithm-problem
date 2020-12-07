//二叉树的静态实现是指用普通栈来代替二叉树操作中用到的递归栈
//静态二叉树的实现是指用数组来存放二叉树节点 二叉树的操作可以借助递归
// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data, left, right;
//     Node()
//     {
//         left = right = -1;
//     }
// } node[10];

// void init()
// {
//     node[1].data = 1;
//     node[1].left = 2;
//     node[1].right = 3;
//     node[2].data = 7;
//     node[2].left = 4;
//     node[2].right = -1;
//     node[3].data = 4;
//     node[3].left = -1;
//     node[3].right = 5;
//     node[4].data = 5;
//     node[4].left = -1;
//     node[4].right = -1;
//     node[5].data = 2;
//     node[5].left = -1;
//     node[5].right = -1;
// }

// void preOrder(int root)
// {
//     if (root == -1)
//         return;

//     cout << node[root].data << " ";
//     preOrder(node[root].left);
//     preOrder(node[root].right);
// }

// void inOrder(int root)
// {
//     if (root == -1)
//         return;

//     inOrder(node[root].left);
//     cout << node[root].data << " ";
//     inOrder(node[root].right);
// }

// void postOrder(int root)
// {
//     if (root == -1)
//         return;

//     postOrder(node[root].left);
//     postOrder(node[root].right);
//     cout << node[root].data << " ";
// }

// int main()
// {
//     init();
//     int root = 1;
//     preOrder(root);
//     cout << endl;
//     inOrder(root);
//     cout << endl;
//     postOrder(root);
//     cout << endl;

//     return 0;
// }

// 下面这个增加了根据前中后序建树
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1005;
int id = 0;

struct Node
{
    int data, left, right;

    Node()
    {
        left = right = -1;
    }
} node[maxn];

int buildTree(vector<int> pre, vector<int> vin)
{
    if (pre.empty() || vin.empty())
        return -1;

    //先序遍历vector的第0个元素就是此时的根
    int val = pre[0], index = 0;
    //构造节点
    int root = ++id;
    node[root].data = val;

    // 在中序遍历vector中寻找先序遍历vector中确立的根节点 这里默认每个节点的值是互异的
    while (vin[index] != val)
        index++;

    vector<int> preLeft, preRight, vinLeft, vinRight;

    // 截取更小的左右子树
    for (int i = 0; i < index; i++)
    {
        //第0个是根节点 用掉了
        preLeft.push_back(pre[i + 1]);
        vinLeft.push_back(vin[i]);
    }
    for (int i = index + 1; i < pre.size(); i++)
    {
        preRight.push_back(pre[i]);
        vinRight.push_back(vin[i]);
    }

    //此时的节点的左右子节点是左子树和右子树的根节点
    node[root].left = buildTree(preLeft, vinLeft);
    node[root].right = buildTree(preRight, vinRight);
    return root;
}

void preOrder(int root)
{
    if (root == -1)
        return;
    cout << node[root].data << ' ';
    preOrder(node[root].left);
    preOrder(node[root].right);
}

void inOrder(int root)
{
    if (root == -1)
        return;

    inOrder(node[root].left);
    cout << node[root].data << ' ';
    inOrder(node[root].right);
}

void postOrder(int root)
{
    if (root == -1)
        return;
    postOrder(node[root].left);
    postOrder(node[root].right);
    cout << node[root].data << ' ';
}

void orderShow(int root)
{
    cout << "the root node's id is : " << root << endl
         << "前序遍历:" << endl;

    preOrder(root);

    cout << endl
         << "中序遍历:" << endl;
    inOrder(root);
    cout << endl
         << "后序遍历:" << endl;
    postOrder(root);
    cout << endl;
}

int main()
{
    // 输入：
    // 5
    // 1 7 5 4 2
    // 5 7 1 4 2
    int n, x;
    vector<int> pre, vin;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        pre.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vin.push_back(x);
    }
    // cout << "******" << endl;
    int root = buildTree(pre, vin);
    orderShow(root);

    return 0;
}