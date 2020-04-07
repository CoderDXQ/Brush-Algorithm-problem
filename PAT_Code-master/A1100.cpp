#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;
// [0,12]的火星文
string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                      "jly", "aug", "sep", "oct", "nov", "dec"};
// 13的[0,12]倍的火星文
string tenDigit[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes",
                     "hei", "elo", "syy", "lok", "mer", "jou"};
string numToStr[170];    // 数字->火星文
map<string, int> strToNum;    // 火星文->数字
void init() {
    for(int i = 0; i < 13; i++) {
        numToStr[i] = unitDigit[i];    // 个位为[0,12]，十位为0
        strToNum[unitDigit[i]] = i;
        numToStr[i * 13] = tenDigit[i];    // 十位为[0,12]，个位为0
        strToNum[tenDigit[i]] = i * 13;
    }
    for(int i = 1; i < 13; i++) {    // 十位
        for(int j = 1; j < 13; j++) {    // 个位
            string str = tenDigit[i] + " " + unitDigit[j];    // 火星文
            numToStr[i * 13 + j] = str;    // 数字->火星文
            strToNum[str] = i * 13 + j;    // 火星文->数字
        }
    }
}
int main() {
    init();    // 打表
    int T;
    scanf("%d%*c", &T);    // 查询个数
    while(T--) {
        string str;
        getline(cin, str);    // 查询的数
        if(str[0] >= '0' && str[0] <= '9') {    // 如果是数字
            int num = 0;    // 字符串转换成数字
            for(int i = 0; i < str.length(); i++) {
                num = num * 10 + (str[i] - '0');
            }
            cout << numToStr[num] << endl;    // 直接查表
        } else {    // 如果是火星文
            cout << strToNum[str] << endl;    // 直接查表
        }
    }
    return 0;
}
