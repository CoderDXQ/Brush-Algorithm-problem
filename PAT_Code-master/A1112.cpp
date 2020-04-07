#include <cstdio>
#include <cstring>
const int maxn = 1010;      // 字符串长度上限
const int maxm = 128;       // ASCII码上限
char str[maxn];     // 输入的字符串
// K为重复的次数,len为字符串长度,isStuck数组记录键位好坏(-1为已输出的坏键,0为坏,1为好)
int K, len, isStuck[maxm] = {0};
void judgeStuck() {     // judgeStuck函数判断每个键位是否可能是坏键
    int i = 0, j = 0;   // i为重复键位左端点,j为重复键位右端点
    while(i < len) {
        while(j < len && str[i] == str[j]) {
            j++;    // 只要依旧重复就不断右移右端点
        }
        if((j - i) % K != 0) {      //只要重复长度不为K的倍数
            isStuck[str[i]] = 1;    //那么该键位一定是好的
        }
        i = j;      // 左端点设置为当前右端点
    }
}
int main() {
    scanf("%d%s", &K, str);     // 输入重复次数和字符串本身
    len = strlen(str);      // 字符串长度
    judgeStuck();       // 判断每个键位是否可能是坏键
    for(int i = 0; i < len; i++) {
        if(isStuck[str[i]] == 0) {     // 如果该键位可能是坏的
            printf("%c", str[i]);       // 输出该键位
            isStuck[str[i]] = -1;       // 标记该键位为已输出的坏键
        }
    }
    printf("\n");   // 换行
    for(int i = 0; i < len;) {
        printf("%c", str[i]);   // 输出当前键位
        if(isStuck[str[i]] == -1) {      // 如果当前键位是之前输出的坏键
            i += K;     // 剩下的连续重复部分不重复输出
        } else {
            i++;    // 继续下一键位的输出
        }
    }
    return 0;
}