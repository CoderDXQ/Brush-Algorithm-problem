#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree { 
    char data;
    tree * lson;
    tree * rson;
};
inline int find (char * begin, char c) { // ����ȷ��ĳһ���ַ������������е�����
    char * p; 
    int i = 0;
    for (p=begin;1;p++) {
        if (*p==c) return i;
        i++;
    }
}
tree * createtree(char * ldr, char * lrd, int len) {
    if (len<=0) return NULL; // ����Ϊ0ֱ�ӷ��� ���NULL�ᱻ��ֵ����һ���p->lson

    tree * p = new tree;
    p->data = lrd[len-1]; // �������е����һλ����������������
    int i = find(ldr, p->data); // �������������ҵ����� Ȼ���������ߺ��Ұ�߾ͷֱ�����������������
    p->lson = createtree(ldr, lrd, i);  // ���
    p->rson = createtree(ldr+i+1, lrd+i, len-i-1); // �ұ�
    return p;    
}
void dlr(tree * t) {
    printf("%c", t->data); // �������
    tree * p;
    if (p=t->lson) dlr(p); // ������
    if (p=t->rson) dlr(p); // ������
}
int main() {
    char a[10];
    char b[10];
    scanf("%s", a);
    scanf("%s", b);
    tree * t = createtree(a, b, strlen(a));
    dlr(t); 
    return 0;
    printf(":-)"); // �Ǻ�
}
