#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int Age[maxn] = {0};
struct Person {
    int age, worths;
    char name[10];
} ps[maxn], valid[maxn];

bool cmp(Person a, Person b) {
    if(a.worths != b.worths) return a.worths > b.worths;
    else if(a.age != b.age) return a.age < b.age;
    return strcmp(a.name, b.name) < 0;
}
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%s%d%d", ps[i].name, &ps[i].age, &ps[i].worths);
    }
    sort(ps, ps + n, cmp);
    int validNum = 0;
    for(int i = 0; i < n; i++) {
        if(Age[ps[i].age] < 100) {
            Age[ps[i].age]++;
            valid[validNum++] = ps[i];
        }
    }
    int m, ageL, ageR;
    for(int i = 1; i <= k; i++) {
        scanf("%d%d%d", &m, &ageL, &ageR);
        printf("Case #%d:\n", i);
        int printNum = 0;
        for(int j = 0; j < validNum && printNum < m; j++) {
            if(valid[j].age >= ageL && valid[j].age <= ageR) {
                printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worths);
                printNum++;
            }
        }
        if(printNum == 0) {
            printf("None\n");
        }
    }
    return 0;
}
