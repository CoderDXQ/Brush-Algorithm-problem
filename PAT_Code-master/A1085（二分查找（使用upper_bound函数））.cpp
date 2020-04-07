#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int n, p, a[maxn];

int main() {
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        int j = upper_bound(a + i + 1, a + n, (long long)a[i] * p) - a;
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
    return 0;
}
