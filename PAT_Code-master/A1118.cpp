#include <cstdio>
#include <cstring>
const int maxn = 10010;
int n, m;
int father[maxn];  //存放父亲结点
int findFather(int x) {  //查找x所在集合的根结点
    int a = x;
    while(x != father[x]) {
        x = father[x];
    }
    //路径压缩（可不写）
    while(a != father[a]) {
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a, int b) {  //合并a和b所在的集合
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB) {
        father[faA] = faB;
    }
}
void init(int ID) {
    if(father[ID] == -1) {
        father[ID] = ID;
    }
}
int main() {
    scanf("%d", &n);
    memset(father, -1, sizeof(father));
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        if(k) {
            int bird, tempBird;
            scanf("%d", &bird);
            init(bird);
            for(int j = 1; j < k; j++) {
                scanf("%d", &tempBird);
                init(tempBird);
                Union(bird, tempBird);
            }
        }
    }
    int numTree = 0, numBird = 0;
    for(int i = 0; i < maxn; i++) {
        if(father[i] != -1) {
            numBird++;
            if(father[i] == i) {
                numTree++;
            }
        }
    }
    printf("%d %d\n", numTree, numBird);
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        int birdA, birdB;
        scanf("%d%d", &birdA, &birdB);
        if(findFather(birdA) == findFather(birdB)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
