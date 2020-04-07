#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 1010;
int father[N];    // 存放父亲结点
int isRoot[N] = {0};    // 记录每个结点是否作为某个集合的根结点
int course[N] = {0};
int findFather(int x) {    // 查找x所在集合的根结点
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    // 路径压缩
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {    // 合并a和b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}
void init(int n) {    // 初始化father[i]为i，且flag[i]为false
    for(int i = 1; i <= n; i++) {
        father[i] = i;
        isRoot[i] = false;
    }
}
bool cmp(int a, int b) {    // 将isRoot数组从大到小排序
    return a > b;
}
int main() {
    int n, k, h;
    scanf("%d", &n);    // 人数
    init(n);    // 要记得初始化
    for(int i = 1; i <= n; i++) {    // 对每个人
        scanf("%d:", &k);    // 活动个数
        for(int j = 0; j < k; j++) {    // 对每个活动
            scanf("%d", &h);    // 输入i号人喜欢的活动h
            if(course[h] == 0) {    // 如果活动h第一次有人喜欢
                course[h] = i;    // 令i喜欢活动h
            }
            Union(i, findFather(course[h]));    // 合并
        }
    }
    for(int i = 1; i <= n; i++) {
        isRoot[findFather(i)]++;    // i的根结点是findFather(i)，人数加1
    }
    int ans = 0;    // 记录集合数目
    for(int i = 1; i <= n; i++) {
        if(isRoot[i] != 0) {
            ans++;    // 只统计isRoot[i]不为0的
        }
    }
    printf("%d\n", ans);    // 输出集合个数
    sort(isRoot + 1, isRoot + n + 1, cmp);    // 从大到小排序
    for(int i = 1; i <= ans; i++) {    // 依次输出每个集合内的人数
        printf("%d", isRoot[i]);
        if(i < ans) printf(" ");
    }
    return 0;
}

