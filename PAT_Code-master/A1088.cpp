#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}
struct Fraction {
    ll up, down;
}a, b;
Fraction reduction(Fraction result) {
    if(result.down < 0) {
        result.up = -result.up;
        result.down = - result.down;
    }
    if (result.up == 0) {
        result.down = 1;
    } else {
        int d = gcd(abs(result.up), abs(result.down));
        result.up /= d;
        result.down /= d;
    }
    return result;
}
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction multi(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}
Fraction divide(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}
void showResult(Fraction r) {
    r = reduction(r);
    if(r.up < 0) printf("(");
    if(r.down == 1) printf("%lld", r.up);
    else if(abs(r.up) > r.down) {
        printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
    } else {
        printf("%lld/%lld", r.up , r.down);
    }
    if(r.up < 0) printf(")");
}
int main() {
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    //加法
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");
    //减法
    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minu(a, b));
    printf("\n");
    //乘法
    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(multi(a, b));
    printf("\n");
    //除法
    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up == 0) printf("Inf");
    else showResult(divide(a, b));
    return 0;
}
