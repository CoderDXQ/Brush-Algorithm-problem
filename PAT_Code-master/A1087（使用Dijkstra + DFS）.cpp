#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
const int MAXV = 210;
const int INF = 1000000000;

int n, m, st, G[MAXV][MAXV], weight[MAXV];
int d[MAXV], numPath = 0, maxW = 0;
double maxAvg = 0;
bool vis[MAXV] = {false};
vector<int> pre[MAXV];
vector<int> tempPath, path;
map<string, int> cityToIndex;
map<int, string> indexToCity;

void Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    for(int i = 0; i < n; i++) {
        pre[i].push_back(i);
    }
    d[s] = 0;
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
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(d[u] + G[u][v] == d[v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v) {
    if(v == st) {
        tempPath.push_back(v);
        numPath++;
        int tempW = 0;
        for(int i = tempPath.size() - 2; i >= 0; i--) {
            int id = tempPath[i];
            tempW += weight[id];
        }
        double tempAvg = 1.0 * tempW / (tempPath.size() - 1);
        if(tempW > maxW) {
            maxW = tempW;
            maxAvg = tempAvg;
            path = tempPath;
        } else if(tempW == maxW && tempAvg > maxAvg) {
            maxAvg = tempAvg;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
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
    DFS(rom);
    printf("%d %d %d %d\n", numPath, d[rom], maxW, (int)maxAvg);
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << indexToCity[path[i]];
        if(i > 0) cout << "->";
    }
    return 0;
}
