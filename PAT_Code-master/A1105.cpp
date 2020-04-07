#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxr = 10010;
const int maxc = 110;
// matrix为欲输出的矩阵，A为给定的序列
int matrix[maxr][maxc], A[maxr];
bool cmp(int a, int b) {
    return a > b;    // 从大到小排序
}
int main() {
    int N;
    scanf("%d", &N);    // 序列元素个数
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);    // 序列元素
    }
    if(N == 1) {    // 只有一个数时直接特判输出
        printf("%d", A[0]);
        return 0;
    }
    sort(A, A + N, cmp);    // 将序列从大到小排序
    int m = (int)ceil(sqrt(1.0 * N));    // 行数m初始为根号N
    while(N % m != 0) {
        m++;    // 寻找最小的能整除N的m
    }
    // n为列数，i、j为当前欲填的位置，now指向序列中当前待填的数的下标
    int n = N / m, i = 1, j = 1, now = 0;
    int U = 1, D = m, L = 1, R = n;    // 四个边界
    while(now < N) {    // 只要已经填充的数的个数没有达到N
        while(now < N && j < R) {    // 向右填充
            matrix[i][j] = A[now++];
            j++;
        }
        while(now < N && i < D) {    // 向下填充
            matrix[i][j] = A[now++];
            i++;
        }
        while(now < N && j > L) {    // 向左填充
            matrix[i][j] = A[now++];
            j--;
        }
        while(now < N && i > U) {    // 向上填充
            matrix[i][j] = A[now++];
            i--;
        }
        U++, D--, L++, R--;    // 缩小边界
        i++, j++;    // 位置移至内层左上角
        if(now == N - 1) {    // 最后一个数单独处理
            matrix[i][j] = A[now++];
        }
    }
    for(int i = 1; i <= m; i++) {    // 输出矩阵
        for(int j = 1; j <= n; j++) {
            printf("%d", matrix[i][j]);
            if(j < n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
