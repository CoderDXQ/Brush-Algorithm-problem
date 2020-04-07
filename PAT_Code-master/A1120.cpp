#include <cstdio>
#include <set>
using namespace std;
set<int> st;
int getSum(int x) {
    int sum = 0;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        st.insert(getSum(x));
    }
    printf("%d\n", st.size());
    for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
        if(it != st.begin()) {
            printf(" ");
        }
        printf("%d", *it);
    }
    return 0;
}