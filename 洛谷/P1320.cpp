// //这个题可以不存储直接输出
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main()
{
    char a;
    char pre;
    int sum,s;
    vector<int> sav;

    pre='0';//题目规定第一个数是0的个数，01轮换
    sum=0;
    s=0;

    while(cin>>a)
    {
        sum++;
        if(pre==a)
        {
            s++;
        }
        else
        {
            sav.push_back(s);
            s=1;
            pre=a;
        }
        
    }
    sav.push_back(s);

    cout<<sqrt(sum);
    for(vector<int>::iterator it=sav.begin();it!=sav.end();it++)
        printf(" %d",(int)(*it));//这里必须要进行强制类型转换  有些编译器无法识别这个指针
    
   // cout<<endl;
    return 0;
}

// #include<bits/stdc++.h>

// using namespace std;

// int main()
// {
//     char a,b='0';//题目规定第一个数是0的个数
//     int ans[1000000],n=0,zz=1;

//     memset(ans,0,sizeof(ans));

//     while(cin>>a)
//     {
//         if(a==b)
//         {
//             ans[zz]++;
//         }
//         else
//         {
//             ans[++zz]++;
//             b=a;
//         }
//         n++;
//     }
//     cout<<sqrt(n);

//     for(int i=1;i<=zz;i++)
//         cout<<" "<<ans[i];

//     return 0;
// }