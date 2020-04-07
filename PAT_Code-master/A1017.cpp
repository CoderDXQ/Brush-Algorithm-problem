#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int K = 111;
const int INF = 1000000000;
struct Customer {
    int comeTime, serveTime;
} newCustomer;
vector<Customer> custom;
int convertTime(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}
bool cmp(Customer a, Customer b) {
    return a.comeTime < b.comeTime;
}
int endTime[K];
int main() {
    int c, w, totTime = 0;
    int stTime = convertTime(8, 0, 0);
    int edTime = convertTime(17, 0, 0);
    scanf("%d%d", &c, &w);
    for(int i = 0; i < w; i++) endTime[i] = stTime;
    for(int i = 0; i < c; i++) {
        int h, m, s, serveTime;
        scanf("%d:%d:%d %d", &h, &m, &s, &serveTime);
        int comeTime = convertTime(h, m, s);
        if(comeTime > edTime) continue;
        newCustomer.comeTime = comeTime;
        newCustomer.serveTime = serveTime <= 60 ? serveTime * 60 : 3600;
        custom.push_back(newCustomer);
    }
    sort(custom.begin(), custom.end(), cmp);
    for(int i = 0; i < custom.size(); i++) {
        int idx = -1, minEndTime = INF;
        for(int j = 0; j < w; j++) {
            if(endTime[j] < minEndTime) {
                minEndTime = endTime[j];
                idx = j;
            }
        }
        if(endTime[idx] <= custom[i].comeTime) {
            endTime[idx] = custom[i].comeTime + custom[i].serveTime;
        } else {
            totTime += (endTime[idx] - custom[i].comeTime);
            endTime[idx] += custom[i].serveTime;
        }
    }
    if(custom.size() == 0) printf("0.0");
    else printf("%.1f", totTime / 60.0 / custom.size());
    return 0;
}
