#include <cstdio>
#include <cstring>
const int maxn = 100010;
bool hashTable[256];
char str[maxn];
int main() {
    memset(hashTable, true, sizeof(hashTable));
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
        hashTable[str[i]] = false;
    }
    gets(str);
    len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            int low = str[i] - 'A' + 'a';
            if(hashTable[low] == true && hashTable['+'] == true) {
                printf("%c", str[i]);
            }
        } else if(hashTable[str[i]] == true) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
