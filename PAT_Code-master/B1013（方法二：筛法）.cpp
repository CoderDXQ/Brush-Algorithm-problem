#include <stdio.h>
const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};
void Find_Prime(int n) {
    for(int i = 2; i < maxn; i++) {
        if(p[i] == false) {
            prime[num++] = i;
            if(num >= n) break;
            for(int j = i + i; j < maxn; j += i) {
                p[j] = true;
            }
        }
    }
}
int main() {
    int m, n, count = 0;
    scanf("%d%d", &m, &n);
    Find_Prime(n);
    for(int i = m; i <= n; i++) {
        printf("%d",prime[i - 1]);
        count++;
        if(count % 10 != 0 && i < n) printf(" ");
        else printf("\n");
    }
    return 0;
}
