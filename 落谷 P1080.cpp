#include<bits/stdc++.h>
using namespace std;
int n, lens = 1, lenm = 1, lena = 1;//��Ҫ�ĳ�ʼ�� 
int sum[10010] = {0, 1}, maxn[10010] = {0, 1}, ans[10010];//��Ҫ�ĳ�ʼ�� 
//ans�Ǹ߾��ȳ����Ĵ洢���飬sum�Ǹ߾��ȳ˷��Ĵ洢���� 
struct tmp
{
    long long l, r;//����д�ڽṹ������� 
    bool operator < (const tmp x) const //��һ�������ط��ĸ�ʽ 
    {
            return l * r < x.l * x.r;
    }
}coin[1001];
void muti(long long x)//�߾��ȳ˷� ���ۻ� 
{
    int tmp = 0;
    for(int i = 1; i <= lens; i++) sum[i] *= x;
    for(int i = 1; i <= lens; i++)
    {
        tmp += sum[i];sum[i] = tmp %10;tmp /= 10;
    }//��λ���� 
    while(tmp != 0)
    {
        lens++;sum[lens] = tmp % 10;tmp /= 10;
    }//����λ�� 
}
void cut(long long x)//�߾��ȳ�����ÿ���󳼵Ľ��� 
{
    memset(ans, 0, sizeof(ans));//��ʼ�� 
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
    while(ans[lena] == 0)//ȥ�������0 
    {
        if(lena == 1)    break;//����0 
        lena--;
    }
}
void max()
{
    if(lena > lenm)
    {
        for(int i = 1; i <= lena; i++)    maxn[i] = ans[i];
        lenm = lena;//maxn����洢����ͣ�lenm����λ�� 
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
    cin >> coin[0].l >> coin[0].r;//���� 
    for(int i = 1; i <= n; i++) scanf("%d %d", &coin[i].l, & coin[i].r);
    sort(coin + 1, coin + n + 1);
    for(int i = 1; i <= n; i++)
    {
        muti(coin[i - 1].l);//���ۻ� 
        cut(coin[i].r);// ���� 
        max();//���αȽ����½���ֵ����ʷ�����ֵ 
    }
    for(int i = lenm; i >= 1; i--) cout << maxn[i];//�߾���Ҫ������� 
}
