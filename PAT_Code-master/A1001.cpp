#include <cstdio>
int num[10];
int main() {
    int a, b, sum;
    scanf("%d%d",&a, &b);
    sum = a + b;
    if(sum < 0) {
        printf("-");
        sum = -sum;
    }
    int len = 0;
    if(sum == 0) num[len++] = 0;
    while(sum) {
        num[len++] = sum % 10;
        sum /= 10;
    }
    for(int k = len - 1; k >= 0; k--) {
        printf("%d", num[k]);
        if(k > 0 && k % 3 == 0) printf(",");
    }
    return 0;
}
