//方法一：暴力模拟
// #include<stdio.h>
// #include<iostream>

// using namespace std;

// int main()
// {
//     long long i,k,sum,day;

//     cin>>k;

//     i=1;sum=0;day=1;
//     while(day<=k)
//     {
//         for(int j=1;j<=i;j++)
//             if(day<=k)
//             {
//                 sum+=i;
//                 day++;
//             }
//         i++;
//     }
//     cout<<sum<<endl;
//     return 0;
// }

//方法二：数学模型优化

#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    long long k,n,coin;

    cin>>k;
    coin=0;//使用一个变量之前必须要进行初始化操作 防止在不同编译环境中的初始默认值差异
    for(n=1;k-n>=0;k-=n++)
        coin+=n*n;//计算前面够n天的情况

    coin=coin+k*n;//把不足n天的情况算上

    cout<<coin;

    return 0;
}