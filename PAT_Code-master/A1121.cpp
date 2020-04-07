#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int maxm = 10010;
int couple[maxn], IDinParty[maxm];
bool isInParty[maxn] = {false};
int numSingleDog = 0, singleDog[maxm];
int main() {
    int n, m;
    scanf("%d", &n);
    memset(couple, -1, sizeof(couple));
    for(int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &IDinParty[i]);
        if(!isInParty[IDinParty[i]]) {
            isInParty[IDinParty[i]] = true;
        }
    }
    for(int i = 0; i < m; i++) {
        int ID = IDinParty[i];
        if(couple[ID] == -1 || !isInParty[couple[ID]]) {
            singleDog[numSingleDog++] = ID;
        }
    }
    sort(singleDog, singleDog + numSingleDog);
    printf("%d\n", numSingleDog);
    for(int i = 0; i < numSingleDog; i++) {
        printf("%05d", singleDog[i]);
        if(i < numSingleDog - 1) {
            printf(" ");
        }
    }
    return 0;
}