#include <cstdio>
#include <cstring>
int main() {
    char str[90];
    gets(str);
    int len = strlen(str), r = 0, h = 0;
    char ans[90][90];
    for(int i = 0; i < len; i++) {
        if(str[i] != ' ') {
            ans[r][h++] = str[i];
        }else{
            r++;
            h = 0;
        }
    }
    for(int i = r; i >= 0; i--) {
        printf("%s", ans[i]);
        if(i > 0) printf(" ");
    }
    return 0;
}
