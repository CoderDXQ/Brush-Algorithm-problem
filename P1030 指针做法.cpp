#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct tree { 
    char data;
    tree * lson;
    tree * rson;
};
inline int find (char * begin, char c) { // 用来确认某一个字符在中序排列中的哪里
    char * p; 
    int i = 0;
    for (p=begin;1;p++) {
        if (*p==c) return i;
        i++;
    }
}
tree * createtree(char * ldr, char * lrd, int len) {
    if (len<=0) return NULL; // 长度为0直接返回 这个NULL会被赋值到上一层的p->lson

    tree * p = new tree;
    p->data = lrd[len-1]; // 后序排列的最后一位就是整个树的树根
    int i = find(ldr, p->data); // 从中序排列中找到树根 然后它的左半边和右半边就分别是左子树和右子树
    p->lson = createtree(ldr, lrd, i);  // 左边
    p->rson = createtree(ldr+i+1, lrd+i, len-i-1); // 右边
    return p;    
}
void dlr(tree * t) {
    printf("%c", t->data); // 先序输出
    tree * p;
    if (p=t->lson) dlr(p); // 左子树
    if (p=t->rson) dlr(p); // 右子树
}
int main() {
    char a[10];
    char b[10];
    scanf("%s", a);
    scanf("%s", b);
    tree * t = createtree(a, b, strlen(a));
    dlr(t); 
    return 0;
    printf(":-)"); // 呵呵
}
