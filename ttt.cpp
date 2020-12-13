

#include<bits/stdc++.h>

using namespace std;

int main() {
    string str = "google";
    int ss[10005];
    memset(ss, 0, sizeof(ss));
    for (int i = 0; i < str.length(); i++) {
        ss[str[i] - 'A']++;
    }
    for (int i = 0; i < str.length(); i++) {

        if (ss[str[i] - 'A'] == 1) {
            //    cout << i << endl;
            return i;
        }
    }
    return -1;
}
