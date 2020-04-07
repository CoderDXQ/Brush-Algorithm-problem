#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXV = 1020;
const int INF = 1000000000;

int n, m, k, DS, G[MAXV][MAXV];
int d[MAXV];
bool vis[MAXV] = {false};

void Dijkstra(int s) {
    memset(vis, false, sizeof(vis));
    fill(d, d + MAXV, INF);
    d[s] = 0;
    for(int i = 0; i < n + m; i++) {
        int u = -1, MIN = INF;
        for(int j = 1; j <= n + m; j++) {
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;
        vis[u] = true;
        for(int v = 1; v <= n + m; v++) {
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];
                }
            }
        }
    }
}

int getID(char str[]) {
    int i = 0, len = strlen(str), ID = 0;
    while(i < len) {
        if(str[i] != 'G') {
            ID = ID * 10 + (str[i] - '0');
        }
        i++;
    }
    if(str[0] == 'G') return n + ID;
    else return ID;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &k, &DS);
    int u, v, w;
    char city1[5], city2[5];
    fill(G[0], G[0] + MAXV * MAXV, INF);
    for(int i = 0; i < k; i++) {
        scanf("%s %s %d", city1, city2, &w);
        u = getID(city1);
        v = getID(city2);
        G[v][u] = G[u][v] = w;
    }
    double ansDis = -1, ansAvg = INF;
    int ansID = -1;
    for(int i = n + 1; i <= n + m; i++) {
        double minDis = INF, avg = 0;
        Dijkstra(i);
        for(int j = 1; j <= n; j++) {
            if(d[j] > DS) {
                minDis = -1;
                break;
            }
            if(d[j] < minDis) minDis = d[j];
            avg += 1.0 * d[j] / n;
        }
        if(minDis == -1) continue;
        if(minDis > ansDis) {
            ansID = i;
            ansDis = minDis;
            ansAvg = avg;
        } else if(minDis == ansDis && avg < ansAvg) {
            ansID = i;
            ansAvg = avg;
        }
    }
    if(ansID == -1) printf("No Solution\n");
    else {
        printf("G%d\n", ansID - n);
        printf("%.1f %.1f\n", ansDis, ansAvg);
    }
    return 0;
}
