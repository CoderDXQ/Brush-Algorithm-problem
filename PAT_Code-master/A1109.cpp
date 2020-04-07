#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct Person {
    char name[10];      // 姓名
    int height;     // 身高
} person[maxn];
bool cmp(Person a, Person b) {      // 先按身高从高到低,再按姓名字典序从小到大
    if(a.height != b.height) return a.height > b.height;
    else return strcmp(a.name, b.name) < 0;
}
int main() {
    int n, k;       // n为人数,k为行数
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++) {    // 输入每个人的姓名和身高
        scanf("%s%d", person[i].name, &person[i].height);
    }
    sort(person, person + n, cmp);      // 排序
    // num为最后一排人数,leftPos为当前排的身高最高者的位置
    int num = n - (k - 1) * (n / k), leftPos = 0;
    while(leftPos < n) {    // 每次处理一排
        for(int i = (num % 2) ? (num - 2) : (num - 1); i >= 1; i -= 2) {
            printf("%s ", person[leftPos + i].name);    // 从最大奇数到最小奇数输出
        }
        for(int i = 0; i < num; i += 2) {
            printf("%s", person[leftPos + i].name);     // 从最小偶数到最大偶数
            if(num - i > 2) printf(" ");
            else printf("\n");      // 本题必须换行
        }
        leftPos += num;     // 前一排的身高最高者的位置
        num = n / k;    // 除最后一排外,前面所有排的人数都是n/k
    }
    return 0;
}

//#include <cstdio>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//using namespace std;
//const int maxn = 10010;
//struct Person {
//    char name[10];      // 姓名
//    int height;     // 身高
//} person[maxn];
//bool cmp(Person a, Person b) {      // 先按身高从高到低,再按姓名字典序从小到大
//    if(a.height != b.height) return a.height > b.height;
//    else return strcmp(a.name, b.name) < 0;
//}
//int main() {
//    int n, k;       // n为人数,k为行数
//    scanf("%d%d", &n, &k);
//    for(int i = 0; i < n; i++) {    // 输入每个人的姓名和身高
//        scanf("%s%d", person[i].name, &person[i].height);
//    }
//    sort(person, person + n, cmp);      // 排序
//    // num为最后一排人数,leftPos为当前排的最左端位置
//    int num = n - (k - 1) * (n / k), leftPos = 0;
//    while(leftPos < n) {    // 每次处理一排
//        deque<int> personInDeque;   // 定义双端队列
//        for(int i = leftPos; i <= leftPos + num - 1; i++) {     // 遍历该排所有人
//            if((i - leftPos) % 2 == 0) {
//                personInDeque.push_back(i);     // 偶号插入队尾
//            } else {
//                personInDeque.push_front(i);    // 奇号插入队首
//            }
//        }
//        while(!personInDeque.empty()) {     // 只要双端队列非空
//            printf("%s", person[personInDeque.front()].name);   // 输出队首姓名
//            personInDeque.pop_front();      // 弹出队首
//            if(!personInDeque.empty()) printf(" ");
//            else printf("\n");
//        }
//        leftPos += num;     // 前一排的身高最高者的位置
//        num = n / k;    // 除最后一排外,前面所有排的人数都是n/k
//    }
//    return 0;
//}