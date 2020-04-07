#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 50;
struct Student {
    char name[11];
    char id[11];
    int grade;
}stu[maxn];
bool cmp(Student a, Student b) {
    return a.grade > b.grade;
}
int main() {
    int n, left, right;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    scanf("%d%d", &left, &right);
    sort(stu, stu + n, cmp);
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(stu[i].grade >= left && stu[i].grade <= right) {
            printf("%s %s\n", stu[i].name, stu[i].id);
            flag = true;
        }
    }
    if(flag == false) {
        printf("NONE\n");
    }
    return 0;
}
