//https://www.nowcoder.com/questionTerminal/7cffea0c097c4337821ab3ba25447c1c
//贪心+二分
//^是异或操作 是位运算 一个非零数同0进行运算为原数 同自身运算为0 二进制的每一位上都是同0异1
//首先我们知道若[L,R]这段区间异或和为0，则prefix[R] - prefix[L-1]==0,即prefix[R] = prefix[L-1]
//即若在L,R两个下标处的前缀异或结果相同，那么[L,R]是一个所求区间
//所以我们将这些相等的位置都存下来，题目说了a_i不会超过100000,那么prefix[]最大也不会超过MAX_INT。
//当我们到达i位置后，我们需要往前面去找与该段前缀和相等的位置(但是不能够早于前一段划分的点)，0需要特判。
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int prefix[N],a[N];
vector<int> v[N];
int main(){
    int n;
    scanf("%d",&n);
    v[0].push_back(0);//初始化
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        prefix[i]=prefix[i-1]^a[i];//计算数组a的前缀异或结果并存储
        v[prefix[i]].push_back(i);//存储 前缀异或结果相同的下标存在同一个vector下
    }
    int pos=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0){
            pos=i;//标记位置 后续的查找不可以在这个位置之前
            ans++;//0可以拿出来单独作为一个区间
        }
        else{
            int num=prefix[i];//num取值为a[i]的前缀异或结果

            //寻找前缀异或结果相同的vector中第一个不小于i的数字的下标 i是数组a的下标
            int idx=lower_bound(v[num].begin(),v[num].end(),i)-v[num].begin();
          //idx是vector数组的下标 vector是从0开始的
          //  printf("%d %d\n",idx,pos);
            if(idx>0 && v[num][idx-1]>=pos){
    //idx=0 说明不存在区间且a[i]不为0
    //后续的查找不可以在pos位置之前且区间长度>0 v[num][idx-1]是对应区间[L,R]的L-1 见上面分析
                pos=i;//标记位置 后续的查找不可以在这个位置之前
                ans++;//又找到一个区间 结果加1
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}