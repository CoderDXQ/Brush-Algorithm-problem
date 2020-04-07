   #include<bits/stdc++.h>
   using namespace std;
   struct Tree { //存储一棵树
        char ty; //自己的类型
        Tree *left, *right; //左右子树
        Tree(): left(0), right(0) {} //构造函数，把左右子树都置为0（空指针），以防垃圾值
    } *root = new Tree(); //树根
    char typeof(const string& s) { //获得s的类型：F，B还是I
        int cnt0 = count(s.begin(), s.end(), '0'); //数0的个数，注意是字符'0'而不是数字0
        int cnt1 = s.size() - cnt0; //总字符数减去0的个数就是1的个数
        if (cnt0 != 0 && cnt1 != 0) return 'F'; //0，1都有，是F
        if (cnt0 == 0) return 'I'; //没有0，也就是只有1，是I
        if (cnt1 == 0) return 'B'; //没有1，也就是只有0，是B
    }
    void construct(Tree* f, string s) { //建树
        if (s.size() == 1) { //长度为1，按照题目要求应该返回
            f->ty = (s == "0" ? 'B' : 'I');
            return;
        }
        //记得要先new出来才能访问其中的字段
        f->left = new Tree(); f->right = new Tree();
        f->ty = typeof(s); //获取自身的类型
        construct(f->left, s.substr(0, s.size() / 2)); //递归建树
        construct(f->right, s.substr(s.size() / 2));
    }
    void post(Tree* f) { //输出后序遍历，左子树+右子树+根结点
        if (f->left) post(f->left);
        if (f->right) post(f->right);
        cout << f->ty;
    }
    int main() {
        int n; cin >> n; //其实这个没用
        string fbi; cin >> fbi;
        construct(root, fbi);
        post(root);
        return 0;
}
