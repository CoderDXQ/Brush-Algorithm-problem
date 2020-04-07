#include <cstdio>
#include <cstring>
const int MAXN = 100010;
const int MOD = 1000000007;
char str[MAXN];    // 字符串
int leftNumP[MAXN] = {0};    // 每一位左边（含）P的个数
int main() {
    gets(str);    // 读入字符串
    int len = strlen(str);    // 长度
    for(int i = 0; i < len; i++) {    // 从左到右遍历字符串
        if(i > 0) {    // 如果不是0号位
            leftNumP[i] = leftNumP[i - 1];    // 继承上一位的结果
        }
        if(str[i] == 'P') {    // 当前位是P
            leftNumP[i]++;    // 令leftNumP[i]加1
        }
    }
    // ans为答案，rightNumT记录右边T的个数
    int ans = 0, rightNumT = 0;
    for(int i = len - 1; i >= 0; i--) {    // 从右到左遍历字符串
        if(str[i] == 'T') {    // 当前位是T
            rightNumT++;    // 右边T的个数加1
        } else if(str[i] == 'A') {    // 当前位是A
            ans = (ans + leftNumP[i] * rightNumT) % MOD;    // 累计乘积
        }
    }
    printf("%d\n", ans);    // 输出结果
    return 0;
}
