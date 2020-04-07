#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node {
    int v, height;    // v为结点权值，height为当前子树高度
    node *lchild, *rchild;    // 左右孩子结点地址
} *root;

// 生成一个新结点，v为结点权值
node* newNode(int v) {
    node* Node = new node;    // 申请一个node型变量的地址空间
    Node->v = v;    // 结点权值为v
    Node->height = 1;    // 结点高度初始为1
    Node->lchild = Node->rchild = NULL;    // 初始状态下没有左右孩子
    return Node;    // 返回新建结点的地址
}
// 获取以root为根结点的子树的当前height
int getHeight(node* root) {
    if(root == NULL) return 0;    // 空结点高度为0
    return root->height;
}
// 更新结点root的height
void updateHeight(node* root) {
    // max(左孩子的height, 右孩子的height) + 1
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
// 计算结点root的平衡因子
int getBalanceFactor(node* root) {
    // 左子树高度减右子树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}
// 左旋（Left Rotation）
void L(node* &root) {
    node* temp = root->rchild;    // root指向结点A，temp指向结点B
    root->rchild = temp->lchild;    // Step 1
    temp->lchild = root;    // Step 2
    updateHeight(root);    // 更新结点A的高度
    updateHeight(temp);    // 更新结点B的高度
    root = temp;    // Step 3
}
// 右旋（Right Rotation）
void R(node* &root) {
    node* temp = root->lchild;    // root指向结点B，temp指向结点A
    root->lchild = temp->rchild;    // Step 1
    temp->rchild = root;    // Step 2
    updateHeight(root);    // 更新结点B的高度
    updateHeight(temp);    // 更新结点A的高度
    root = temp;    // Step 3
}
// 插入权值为v的结点
void insert(node* &root, int v) {
    if(root == NULL) {    // 到达空结点
        root = newNode(v);
        return;
    }
    if(v < root->v) {    // v比根结点权值小
        insert(root->lchild, v);    // 往左子树插入
        updateHeight(root);    // 更新树高
        if(getBalanceFactor(root) == 2) {
            if(getBalanceFactor(root->lchild) == 1) {    // LL型
                R(root);
            } else if(getBalanceFactor(root->lchild) == -1) {    // LR型
                L(root->lchild);
                R(root);
            }
        }
    } else {    // v比根结点权值大
        insert(root->rchild, v);    // 往右子树插入
        updateHeight(root);    // 更新树高
        if(getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->rchild) == -1) {    // RR型
                L(root);
            } else if(getBalanceFactor(root->rchild) == 1) {    // RL型
                R(root->rchild);
                L(root);
            }
        }
    }
}
// 层序遍历,其中root为根结点地址,n为结点个数
void levelOrder(node* root, int n) {
    queue<node*> q;     // 定义队列
    q.push(root);       // 根结点入队
    while(!q.empty()) {     // 只要队列非空
        node* front = q.front();    // 队首结点front
        q.pop();        // 弹出队首结点
        printf("%d", front->v);     // 输出队首结点数据域
        n--;    // 未输出的结点个数减1
        printf(n ? " " : "\n");     // 未输出的结点个数不为0时输出空格,否则输出换行
        if(front->lchild) q.push(front->lchild);    // 左孩子非空,左孩子入队
        if(front->rchild) q.push(front->rchild);    // 右孩子非空,右孩子入队
    }
}
// judgeCompleteTree函数判断完全二叉树,其中root为根结点地址,n为结点个数
bool judgeCompleteTree(node* root, int n) {
    queue<node*> q;       // 定义队列
    q.push(root);       // 根结点入队
    while(n) {      // 只要n不为0,即还没有访问完全部非空结点
        node* front = q.front();      // 队首结点front
        q.pop();        // 弹出队首结点
        if(front == NULL) return false;   // 访问到空结点,一定是非完全二叉树
        n--;    // 已访问的非空结点减少1
        q.push(front->lchild);       // 左孩子入队(包括空结点)
        q.push(front->rchild);      // 右孩子入队(包括空结点)
    }
    return true;    // 已经访问完所有非空结点,还没有碰到空结点,一定是完全二叉树
}
int main() {
    int n, v;
    scanf("%d", &n);    // 结点个数
    for(int i = 0; i < n; i++) {
        scanf("%d", &v);    // 结点数据域
        insert(root, v);    // 插入结点
    }
    levelOrder(root, n);    // 层次遍历
    printf(judgeCompleteTree(root, n) ? "YES\n" : "NO\n");  // 判断完全二叉树
    return 0;
}
