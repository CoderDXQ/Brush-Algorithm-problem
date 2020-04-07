#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], tempOri[N], changed[N];    // 原始数组，原始数组备份，目标数组
int n;    // 元素个数
bool isSame(int A[], int B[]) {    // 判断数组A和数组B是否相同
	for (int i = 1; i <= n; i++) {
		if (A[i] != B[i]) return false;
	}
	return true;
}
bool showArray(int A[]) {    // 输出数组
	for (int i = 1; i <= n; i++) {
	    printf("%d", A[i]);
	    if(i < n) printf(" ");
	}
	printf("\n");
}
bool insertSort() {    // 插入排序
    bool flag = false;    // 记录是否存在数组中间步骤与changed数组相同
    for(int i = 2; i <= n; i++) {    // 进行n-1趟排序
        if(i != 2 && isSame(tempOri, changed)) {
            flag = true;    // 中间步骤与目标相同，且不是初始序列
        }
        // 插入部分直接用sort代替
        sort(tempOri, tempOri + i + 1);
        if(flag == true) {
            return true;    // 如果flag为true，则说明已达到目标数组，返回true
        }
    }
    return false;    // 无法达到目标数组，返回false
}
// 对heap数组在[low, high]范围进行调整
// 其中low为欲调整结点的数组下标，high一般为堆的最后一个元素的数组下标
void downAdjust(int low, int high) {
    int i = low, j = i * 2;    // i为欲调整结点，j为其左孩子
    while(j <= high) {    // 存在孩子结点
        // 如果右孩子存在，且右孩子的值大于左孩子
        if(j + 1 <= high && tempOri[j + 1] > tempOri[j]) {
            j = j + 1;    // 让j存储右孩子下标
        }
        // 如果孩子中最大的权值比父亲大
        if(tempOri[j] > tempOri[i]) {
            swap(tempOri[j], tempOri[i]);    // 交换最大权值的孩子与父亲
            i = j;    // 令i为j、令j为i的左孩子，进入下一层
            j = i * 2;
        } else {
            break;    // 孩子的权值均比父亲小，调整结束
        }
    }
}
void heapSort() {    // 堆排序
    bool flag = false;
    for(int i = n / 2; i >= 1; i--) {
        downAdjust(i, n);    // 建堆
    }
    for(int i = n; i > 1; i--) {
        if(i != n && isSame(tempOri, changed)) {
            flag = true;    // 中间步骤与目标相同，且不是初始序列
        }
        swap(tempOri[i], tempOri[1]);    // 交换heap[i]与堆顶
        downAdjust(1, i - 1);    // 调整堆顶
        if(flag == true) {
            showArray(tempOri);    // 已达到目标数组，返回true
            return;
        }
    }
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &origin[i]);    // 输入起始数组
		tempOri[i] = origin[i];    // tempOri数组为备份，排序在tempOri上进行
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &changed[i]);    // 目标数组
	}
	if (insertSort()) {    // 如果插入排序中找到目标数组
		printf("Insertion Sort\n");
		showArray(tempOri);
	} else {    // 到达此处时一定是堆排序
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++) {
		    tempOri[i] = origin[i];    // 还原tempOri数组
		}
		heapSort();    // 堆排序
	}
	return 0;
}
