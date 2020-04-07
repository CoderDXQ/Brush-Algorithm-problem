#include <cstdio>
#include <cstring>
const int MAX_LEN = 10005;
char a[MAX_LEN], b[MAX_LEN];
bool HashTable[128];

int main() {
    gets(a);
    gets(b);
    int lenA = strlen(a);
    int lenB = strlen(b);
    for(int i = 0; i < lenB; i++) {
        HashTable[b[i]] = true;
    }
    for(int i = 0; i < lenA; i++) {
        if(HashTable[a[i]] == false) {
            printf("%c", a[i]);
        }
    }
    return 0;
}
