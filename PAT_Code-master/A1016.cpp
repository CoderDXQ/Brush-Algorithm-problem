#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int toll[25];
struct Record {
    char name[25];
    int month, dd, hh, mm;
    bool status;
} rec[maxn], temp;
bool cmp(Record a, Record b) {
    int s = strcmp(a.name, b.name);
    if(s != 0) return s < 0;
    else if(a.month != b.month) return a.month < b.month;
    else if(a.dd != b.dd) return a.dd < b.dd;
    else if(a.hh != b.hh) return a.hh < b.hh;
    else return a.mm < b.mm;
}
void get_ans(int on, int off, int& time, int& money) {
    temp = rec[on];
    while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm) {
        time++;
        money += toll[temp.hh];
        temp.mm++;
        if(temp.mm >= 60) {
            temp.mm = 0;
            temp.hh++;
        }
        if(temp.hh >= 24) {
            temp.hh = 0;
            temp.dd++;
        }
    }
}
int main() {
    for(int i = 0; i < 24; i++) {
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    char line[10];
    for(int i = 0; i < n; i++) {
        scanf("%s", rec[i].name);
        scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
        scanf("%s", line);
        if(strcmp(line, "on-line") == 0) {
            rec[i].status = true;
        } else {
            rec[i].status = false;
        }
    }
    sort(rec, rec + n, cmp);
    int on = 0, off, next;
    while(on < n) {
        int needPrint = 0;
        next = on;
        while(next < n && strcmp(rec[next].name, rec[on].name) == 0) {
            if(needPrint == 0 && rec[next].status == true) {
                needPrint = 1;
            } else if(needPrint == 1 && rec[next].status == false) {
                needPrint = 2;
            }
            next++;
        }
        if(needPrint < 2) {
            on = next;
            continue;
        }
        int AllMoney = 0;
        printf("%s %02d\n", rec[on].name, rec[on].month);
        while(on < next) {
            while(on < next - 1
                  && !(rec[on].status == true && rec[on + 1].status == false)) {
                on++;
            }
            off = on + 1;
            if(off == next) {
                on = next;
                break;
            }
            printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
            printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            AllMoney += money;
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1;
        }
        printf("Total amount: $%.2f\n", AllMoney / 100.0);
    }
    return 0;
}
