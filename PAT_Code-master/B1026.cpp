#include <cstdio>
int main() {
    int c1, c2;
    scanf("%d%d", &c1, &c2);
    int ans = c2 - c1;
    if(ans % 100 >= 50) {
        ans = ans / 100 + 1;
    } else {
        ans = ans / 100;
    }
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    return 0;
}
