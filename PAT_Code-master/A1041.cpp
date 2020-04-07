#include <cstdio>
int a[100001], HashTable[10001] = {0};
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        HashTable[a[i]]++;
    }
    int ans = -1;
    for(int i = 0; i < n; i++) {
        if(HashTable[a[i]] == 1) {
            ans = a[i];
            break;
        }
    }
    if(ans == -1) printf("None");
    else printf("%d\n", ans);
    return 0;
}
