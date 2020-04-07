#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int maxn = 210;
bool G[maxn][maxn] = {false};
bool isInPath[maxn];
vector<int> nodes;
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u][v] = G[v][u] = true;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int num, tempNode;
        scanf("%d", &num);
        nodes.clear();
        for(int j = 0; j < num; j++) {
            scanf("%d", &tempNode);
            nodes.push_back(tempNode);
        }
        if(num != n + 1 || nodes[0] != nodes.back()) {
            printf("NO\n");
        } else {
            memset(isInPath, false, sizeof(isInPath));
            bool isHamiltonianCycle = true;
            for(int j = 1; j < nodes.size(); j++) {
                isHamiltonianCycle &= !isInPath[nodes[j]];
                isHamiltonianCycle &= G[nodes[j - 1]][nodes[j]];
                isInPath[nodes[j]] = true;
            }
            printf(isHamiltonianCycle ? "YES\n" : "NO\n");
        }
    }
    return 0;
}