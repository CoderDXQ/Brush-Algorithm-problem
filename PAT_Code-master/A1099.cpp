#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 110;
struct node {    // 二叉树的静态写法
    int data;
    int lchild, rchild;
} Node[maxn];
// n为结点个数，in为中序序列，num为已经填入/输出的结点个数
int n, in[maxn], num = 0;
// 中序遍历，将排序好的序列依次填入二叉树结点
void inOrder(int root) {
    if(root == -1) {
        return;
    }
    inOrder(Node[root].lchild);
    Node[root].data = in[num++];    // 填入序列中的整数
    inOrder(Node[root].rchild);
}
// 层序遍历
void BFS(int root) {
    queue<int> q;  //注意队列里是存地址
    q.push(root);  //将根结点地址入队
    num = 0;
    while(!q.empty()) {
        int now = q.front();  //取出队首元素
        q.pop();
        printf("%d", Node[now].data);  //访问队首元素
        num++;
        if(num < n) printf(" ");
        if(Node[now].lchild != -1) q.push(Node[now].lchild);  //左子树非空
        if(Node[now].rchild != -1) q.push(Node[now].rchild);  //右子树非空
    }
}
int main() {
    int lchild, rchild;
    scanf("%d", &n);    // 结点个数
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &lchild, &rchild);    // 左右孩子编号
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &in[i]);    // 输入排序前的序列
    }
    sort(in, in + n);    // 从小到大排序，作为中序序列
    inOrder(0);    // 以0号结点为根结点进行中序遍历，填入整数
    BFS(0);    // 输出层序遍历序列
    return 0;
}
