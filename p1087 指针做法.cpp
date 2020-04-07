   #include<bits/stdc++.h>
   using namespace std;
   struct Tree { //�洢һ����
        char ty; //�Լ�������
        Tree *left, *right; //��������
        Tree(): left(0), right(0) {} //���캯������������������Ϊ0����ָ�룩���Է�����ֵ
    } *root = new Tree(); //����
    char typeof(const string& s) { //���s�����ͣ�F��B����I
        int cnt0 = count(s.begin(), s.end(), '0'); //��0�ĸ�����ע�����ַ�'0'����������0
        int cnt1 = s.size() - cnt0; //���ַ�����ȥ0�ĸ�������1�ĸ���
        if (cnt0 != 0 && cnt1 != 0) return 'F'; //0��1���У���F
        if (cnt0 == 0) return 'I'; //û��0��Ҳ����ֻ��1����I
        if (cnt1 == 0) return 'B'; //û��1��Ҳ����ֻ��0����B
    }
    void construct(Tree* f, string s) { //����
        if (s.size() == 1) { //����Ϊ1��������ĿҪ��Ӧ�÷���
            f->ty = (s == "0" ? 'B' : 'I');
            return;
        }
        //�ǵ�Ҫ��new�������ܷ������е��ֶ�
        f->left = new Tree(); f->right = new Tree();
        f->ty = typeof(s); //��ȡ���������
        construct(f->left, s.substr(0, s.size() / 2)); //�ݹ齨��
        construct(f->right, s.substr(s.size() / 2));
    }
    void post(Tree* f) { //������������������+������+�����
        if (f->left) post(f->left);
        if (f->right) post(f->right);
        cout << f->ty;
    }
    int main() {
        int n; cin >> n; //��ʵ���û��
        string fbi; cin >> fbi;
        construct(root, fbi);
        post(root);
        return 0;
}
