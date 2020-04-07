#include<bits/stdc++.h>
using namespace std;
int n, lens = 1, lenm = 1, lena = 1;//重要的初始化 
int sum[10010] = {0, 1}, maxn[10010] = {0, 1}, ans[10010];//重要的初始化 
//ans是高精度除法的存储数组，sum是高精度乘法的存储数组 
struct tmp
{
    long long l, r;//排序写在结构体里更快 
    bool operator < (const tmp x) const //这一行是重载符的格式 
    {
            return l * r < x.l * x.r;
    }
}coin[1001];
void muti(long long x)//高精度乘法 求累积 
{
    int tmp = 0;
    for(int i = 1; i <= lens; i++) sum[i] *= x;
    for(int i = 1; i <= lens; i++)
    {
        tmp += sum[i];sum[i] = tmp %10;tmp /= 10;
    }//进位过程 
    while(tmp != 0)
    {
        lens++;sum[lens] = tmp % 10;tmp /= 10;
    }//增加位数 
}
void cut(long long x)//高精度除法求每个大臣的奖赏 
{
    memset(ans, 0, sizeof(ans));//初始化 
    lena = lens;
    int tmp = 0;
    for(int i = lena; i >= 1; i--)
    {
        tmp *= 10;tmp += sum[i];
        if(tmp >= x)
        {
            ans[i] = tmp / x;    tmp %= x;
        }
    }
    while(ans[lena] == 0)//去掉多余的0 
    {
        if(lena == 1)    break;//保留0 
        lena--;
    }
}
void max()
{
    if(lena > lenm)
    {
        for(int i = 1; i <= lena; i++)    maxn[i] = ans[i];
        lenm = lena;//maxn数组存储最大奖赏，lenm是其位数 
    }
    else if(lena == lenm)
    {
        for(int i = lena; i >= 1; i--)
            if(maxn[i] < ans[i])
            {
                for(int j = 1; j <= lena; j++)    maxn[j] = ans[j];
                lenm = lena;
                break;
            }
    }
}
int main()
{
//  freopen("game.in", "r", stdin);freopen("game.out", "w", stdout);
    cin >> n;
    cin >> coin[0].l >> coin[0].r;//国王 
    for(int i = 1; i <= n; i++) scanf("%d %d", &coin[i].l, & coin[i].r);
    sort(coin + 1, coin + n + 1);
    for(int i = 1; i <= n; i++)
    {
        muti(coin[i - 1].l);//求累积 
        cut(coin[i].r);// 求奖赏 
        max();//依次比较最新奖赏值与历史最大奖赏值 
    }
    for(int i = lenm; i >= 1; i--) cout << maxn[i];//高精度要求倒着输出 
}
