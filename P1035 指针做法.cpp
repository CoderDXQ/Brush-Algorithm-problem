#include<iostream>
#include<algorithm>
using namespace std;
//没加析构函数，可能是我写的不对，加了就会运行错误
struct Tree { //树的结构
    char me; //自己的字符
    Tree* left; //左子树
    Tree* right; //右子树
    Tree(char w =0): me(w), left(0), right(0) {} //构造函数
} tree; //最终建立的树
inline Tree* build(char w) { //建立一个新的结点，以w作为自己的字符
    if (w == '*') return 0; //如果是'*'，说明不应该创建子树（见下面代码）
    return new Tree(w);
}
Tree* find_tree(char w, Tree* start = &tree) { //在start这棵树中找到字符为w的节点
    if (start->me == w) return start; //自己就是，直接返回
    Tree* ans = 0;
    if (start->left) ans = find_tree(w, start->left); //递归查找，start->left就相当于start->left != 0，而0是build()返回表示没有子树的值
    if (ans) return ans;
    if (start->right) ans = find_tree(w, start->right);
    return ans;
}
void preorder(Tree* start) { //先序遍历： 根节点 + preorder(左子树) + preorder(右子树)
    cout << start->me;
    if (start->left) preorder(start->left); //注意检查有无子树
    if (start->right) preorder(start->right);
}
int main() {
    int n; cin >> n;
    char me, l, r; cin >> me >> l >> r; //me: 自己的字符， l: 左边的字符， r: 右边的字符
    tree.me = me; tree.left = build(l); tree.right = build(r); //各自创建子树
    for (int i = 1; i < n; ++i) {
        char me, l, r; cin >> me >> l >> r;
        Tree* node = find_tree(me); //找到根节点
        node->left = build(l); node->right = build(r); //建立子树
    }
    preorder(&tree); //输出先序遍历
    return 0;
}
