#include<iostream>
#include<algorithm>
using namespace std;
//û��������������������д�Ĳ��ԣ����˾ͻ����д���
struct Tree { //���Ľṹ
    char me; //�Լ����ַ�
    Tree* left; //������
    Tree* right; //������
    Tree(char w =0): me(w), left(0), right(0) {} //���캯��
} tree; //���ս�������
inline Tree* build(char w) { //����һ���µĽ�㣬��w��Ϊ�Լ����ַ�
    if (w == '*') return 0; //�����'*'��˵����Ӧ�ô�����������������룩
    return new Tree(w);
}
Tree* find_tree(char w, Tree* start = &tree) { //��start��������ҵ��ַ�Ϊw�Ľڵ�
    if (start->me == w) return start; //�Լ����ǣ�ֱ�ӷ���
    Tree* ans = 0;
    if (start->left) ans = find_tree(w, start->left); //�ݹ���ң�start->left���൱��start->left != 0����0��build()���ر�ʾû��������ֵ
    if (ans) return ans;
    if (start->right) ans = find_tree(w, start->right);
    return ans;
}
void preorder(Tree* start) { //��������� ���ڵ� + preorder(������) + preorder(������)
    cout << start->me;
    if (start->left) preorder(start->left); //ע������������
    if (start->right) preorder(start->right);
}
int main() {
    int n; cin >> n;
    char me, l, r; cin >> me >> l >> r; //me: �Լ����ַ��� l: ��ߵ��ַ��� r: �ұߵ��ַ�
    tree.me = me; tree.left = build(l); tree.right = build(r); //���Դ�������
    for (int i = 1; i < n; ++i) {
        char me, l, r; cin >> me >> l >> r;
        Tree* node = find_tree(me); //�ҵ����ڵ�
        node->left = build(l); node->right = build(r); //��������
    }
    preorder(&tree); //����������
    return 0;
}
