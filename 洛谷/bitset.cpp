#include <bitset>
#include <iostream>
#include <ctime>

//#include<bits/stdc++.h>
using namespace std;

int main()
{
    const int N = 2000000;
    clock_t cstart = clock();

    //定义位集
    bitset<N + 1> b;

    int count = 0;
    int i;

    //往位集里放数
    for (int i = 2; i <= N; i++)
        b.set(i);

    i = 2;
    while (i * i <= N)
    {
        //查看某个数是否在位集里
        if (b.test(i))
        {
            count++;
            int k = i * 2;
            while (k <= N)
            {
                //从位集里删除某个数
                b.reset(k);
                k += i;
            }
        }
        i++;
    }

    //计算素数的个数
    while (i <= N)
    {
        if (b.test(i))
            count++;
        i++;
    }

    clock_t cend = clock();
    double millis = 1000.0 * (cend - cstart) / CLOCKS_PER_SEC;

    cout << count << "primes\n"
         << millis << " milliseconds\n";

    return 0;
}