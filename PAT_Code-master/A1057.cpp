#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int lim = 317;

stack<int> st;
int x, query;
int bucket[lim];
int table[100005];

void peekMedian() {
    int K = st.size();
    if(K % 2 == 1) K = (K + 1) / 2;
    else K = K / 2;
    int sum = 0;
    int idx = 0;
    for(idx = 0; idx < lim; idx++) {
        if (sum + bucket[idx] < K) {
            sum += bucket[idx];
        }
        else break;
    }
    int b = idx * lim;
    while(1) {
        sum += table[b];
        if(sum >= K) {
            printf("%d\n", b);
            break;
        }
        b++;
    }
}

int main() {
    memset(bucket, 0, sizeof(bucket));
    memset(table, 0, sizeof(table));
    char cmd[20];
    scanf("%d", &query);
    for(int i = 0; i < query; i++) {
        scanf("%s", cmd);
        if(strcmp(cmd, "Push") == 0) {
            scanf("%d", &x);
            st.push(x);
            bucket[x / lim]++;
            table[x]++;
        } else if(strcmp(cmd, "Pop") == 0) {
            if (st.empty() == true) {
                printf("Invalid\n");
            } else {
                x = st.top();
                st.pop();
                bucket[x/lim]--;
                table[x]--;
                printf("%d\n", x);
            }
        } else {
            if(st.empty() == true) {
                printf("Invalid\n");
            } else {
                peekMedian();
            }
        }
    }
    return 0;
}
