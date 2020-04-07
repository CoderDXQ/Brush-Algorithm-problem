#include <cstdio>
#include <cstring>
int main() {
    char str[10010];
    gets(str);
    int len = strlen(str);
    if(str[0] == '-') printf("-");

    int pos = 0;
    while(str[pos] != 'E') {
        pos++;
    }

    int exp = 0;
    for(int i = pos + 2; i < len; i++) {
        exp = exp * 10 + (str[i] - '0');
    }
    if(exp == 0) {
        for(int i = 1; i < pos; i++) {
            printf("%c", str[i]);
        }
    }

    if(str[pos + 1] == '-') {
        printf("0.");
        for(int i = 0; i < exp - 1; i++) {
            printf("0");
        }
        printf("%c", str[1]);
        for(int i = 3; i < pos; i++) {
            printf("%c", str[i]);
        }
    } else {
        for(int i = 1; i < pos; i++) {
            if(str[i] == '.') continue;
            printf("%c", str[i]);
            if(i == exp + 2 && pos - 3 != exp) {
                printf(".");
            }
        }
        for(int i = 0; i < exp - (pos - 3); i++) {
            printf("0");
        }
    }
    return 0;
}
