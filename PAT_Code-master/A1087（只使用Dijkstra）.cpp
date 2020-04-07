#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXV = 210;
const int INF = 1000000000;

int n, m, st, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], w[MAXV], num[MAXV], pt[MAXV], pre[MAXV];
bool vis[MAXV] = {false};
map<string, int> cityToIndex;
map<int, string> indexToCity;

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    memset(w, 0, sizeof(w));
    memset(num, 0, sizeof(num));
    memset(pt, 0, sizeof(pt));
    for(int i = 0; i < n; i++) pre[i] = i;
    d[s] = 0;
    w[s] = weight[st];
    num[s] = 1;
    for(int i = 0; i < n; i++) {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 0; v < n; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v];
                    num[v] = num[u];
                    pt[v] = pt[u] + 1;
                    pre[v] = u;
                } else if(d[u] + G[u][v] == d[v]) {
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pt[v] = pt[u] + 1;
                        pre[v] = u;
                    } else if(w[u] + weight[v] == w[v]) {
                        double uAvg = 1.0 * (w[u] + weight[v]) / (pt[u] + 1);
                        double vAvg = 1.0 * w[v] / pt[v];
                        if(uAvg > vAvg) {
                            pt[v] = pt[u] + 1;
                            pre[v] = u;
                        }
                    }
                }
            }
        }
    }
}
void printPath(int v) {
    if(v == 0) {
        cout << indexToCity[v];
        return;
    }
    printPath(pre[v]);
    cout << "->" << indexToCity[v];
}
int main() {
    string start, city1, city2;
    cin >> n >> m >> start;
    cityToIndex[start] = 0;
    indexToCity[0] = start;
    for(int i = 1; i <= n - 1; i++) {
        cin >> city1 >> weight[i];
        cityToIndex[city1] = i;
        indexToCity[i] = city1;
    }
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < m; i++) {
        cin >> city1 >> city2;
        int c1 = cityToIndex[city1], c2 = cityToIndex[city2];
        cin >> G[c1][c2];
        G[c2][c1] = G[c1][c2];
    }
    Dijkstra(0);
    int rom = cityToIndex["ROM"];
    printf("%d %d %d %d\n", num[rom], d[rom], w[rom], w[rom] / pt[rom]);
    printPath(rom);
    return 0;
}
