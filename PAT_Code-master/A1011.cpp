#include <cstdio>

char S[3] = {'W', 'T', 'L'};
int main() {
    double ans = 1.0, tmp, a;
    int idx;
    for(int i = 0; i < 3; i++) {
        tmp = 0.0;
        for(int j = 0; j < 3; j++) {
            scanf("%lf", &a);
            if(a > tmp) {
                tmp = a;
                idx = j;
            }
        }
        ans *= tmp;
        printf("%c ", S[idx]);
    }
    printf("%.2f", (ans * 0.65 - 1) * 2);
    return 0;
}
