#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int miles[maxn];
bool cmp(int a, int b) {
    return a > b;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &miles[i]);
    }
    sort(miles + 1, miles + n + 1, cmp);
    int E = 1;
    while(E <= n && miles[E] > E) {
        E++;
    }
    printf("%d\n", E - 1);
    return 0;
}
// 10 9 8 8 7 7 6 6 3 2

// n = 1, E = 0
// E = n