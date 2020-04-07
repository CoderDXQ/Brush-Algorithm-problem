#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXV = 510;  //最大顶点数
const int INF = 0x3fffffff;  //无穷大

// n为顶点数,m为边数,st和ed分别为起点和终点,G为距离矩阵,Time为时间矩阵
// d[]记录最短距离,t[]记录最少时间,minTime记录最短路径上的最小时间
// visD用于距离,visT用于时间,vis[i]==true表示顶点i已访问，初始均为false
int n, m, st, ed, G[MAXV][MAXV], Time[MAXV][MAXV];
int d[MAXV], t[MAXV], minTime = INF;
bool visD[MAXV] = {false}, visT[MAXV] = {false};
vector<int> preD[MAXV], preT[MAXV];          // 前驱,preD用于距离,preT用于时间
vector<int> tempPath, pathD, pathT;     // 临时路径、最优路径(pathD用于距离,pathT用于时间)

// s为源点,G为距离(或时间)矩阵,d为最短距离(或时间)
// pre为前驱(距离或时间),vis为是否访问(距离或时间)
void Dijkstra(int s, int G[][MAXV], int d[], vector<int> pre[], bool vis[]) {
    fill(d, d + MAXV, INF);     // fill函数将整个d数组赋为INF（慎用memset）
    d[s] = 0;                   // 起点s到达自身的距离为0
    for(int i = 0; i < n; i++) {        // 循环n次
        int u = -1, MIN = INF;          // u使d[u]最小，MIN存放该最小的d[u]
        for(int j = 0; j < n; j++) {    // 找到未访问的顶点中d[]最小的
            if(vis[j] == false && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return;     // 找不到小于INF的 d[u]，说明剩下的顶点和起点s不连通
        vis[u] = true;          // 标记u为已访问
        for(int v = 0; v < n; v++) {
            // 如果v未访问 && u能到达v
            if(vis[v] == false && G[u][v] != INF) {
                if(d[u] + G[u][v] < d[v]) {     // 以u为中介点使d[v]更小
                    d[v] = d[u] + G[u][v];      // 优化d[v]
                    pre[v].clear();             // 清空pre[v]
                    pre[v].push_back(u);        // u为v的前驱
                } else if(d[u] + G[u][v] == d[v]) {     // 找到相同长度的路径
                    pre[v].push_back(u);        // u为v的前驱之一
                }
            }
        }
    }
}
// DFS中计算最优路径(用于距离)
void getFirstPath() {
    int tempTime = 0;       // 记录当前路径的时间之和
    for(int i = tempPath.size() - 1; i > 0; i--) {          // 倒着访问
        int id = tempPath[i], idNext = tempPath[i - 1];     // 当前结点、下个结点
        tempTime += Time[id][idNext];       // 增加边id->idNext的边权
    }
    if(tempTime < minTime) {        // 如果当前路径的边权之和更小
        minTime = tempTime;         // 更新minTime
        pathD = tempPath;            // 更新pathD
    }
}
// DFS中计算最优路径(用于时间)
void getSecondPath() {
    if(pathT.size() == 0 || tempPath.size() < pathT.size()) {
        pathT = tempPath;   // 最优路径为空,或是找到了顶点个数更小的路径时,更新pathT
    }
}
// 求解最优路径,其中v为当前顶点,pre为前驱数组(距离或时间),isFirstPath表示第一次求解还是第二次求解
void DFS(int v, vector<int> pre[], bool isFirstPath) {
    if(v == st) {   // 递归边界，到达叶子结点（路径起点）
        tempPath.push_back(v);
        if(isFirstPath) getFirstPath();     // 第一次求解时为多条相同最短距离时找最少时间
        else getSecondPath();       // 第二次求解时为多条相同最少时间找顶点个数最小
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); i++) {
        DFS(pre[v][i], pre, isFirstPath);   // 递归
    }
    tempPath.pop_back();
}
// 打印路径
void printPath(vector<int> path) {
    printf("%d", path.back());
    for(int i = path.size() - 2; i >= 0; i--) {
        printf(" -> %d", path[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d%d", &n, &m);
    int u, v, oneWay;
    fill(G[0], G[0] + MAXV * MAXV, INF);    // 初始化距离矩阵G
    fill(Time[0], Time[0] + MAXV * MAXV, INF);      // 初始化时间矩阵Time
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &oneWay);   // 边u->v,oneWay表示单向或双向
        scanf("%d%d", &G[u][v], &Time[u][v]);   // 距离和时间
        if(!oneWay) {   // 双向
            G[v][u] = G[u][v];
            Time[v][u] = Time[u][v];
        }
    }
    scanf("%d%d", &st, &ed);    // 起点和终点
    Dijkstra(st, G, d, preD, visD);   // 第一次Dijkstra
    Dijkstra(st, Time, t, preT, visT);   // 第二次Dijkstra
    DFS(ed, preD, true);    // 第一次DFS
    DFS(ed, preT, false);   // 第二次DFS
    printf("Distance = %d", d[ed]);     // 输出最短距离
    if(pathD == pathT) {    // 两条路径相同,则不再输出距离的最优路径
        printf("; ");
    } else {    // 两条路径不相同
        printf(": ");   // 输出距离的最优路径
        printPath(pathD);
    }
    printf("Time = %d: ", t[ed]);   // 输出最少时间
    printPath(pathT);   // 输出时间的最优路径
    return 0;
}
