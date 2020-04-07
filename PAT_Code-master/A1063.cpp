#include <cstdio>
#include <set>
using namespace std;
const int N = 51;
set<int> st[N];
void compare(int x, int y) {
    int totalNum = st[y].size(), sameNum = 0;
    for(set<int>::iterator it = st[x].begin(); it != st[x].end(); it++) {
        if(st[y].find(*it) != st[y].end()) sameNum++;
        else totalNum++;
    }
    printf("%.1f%\n", sameNum * 100.0 / totalNum);
}
int main() {
    int n, k, q, v, st1, st2;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &v);
            st[i].insert(v);
        }
    }
    scanf("%d", &q);
    for(int i = 0; i < q; i++) {
        scanf("%d%d", &st1, &st2);
        compare(st1, st2);
    }
    return 0;
}
