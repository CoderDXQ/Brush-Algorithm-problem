#include <bits/stdc++.h>
using namespace std;

//动态规划：将大问题分解成性质相同的子问题
int maxProductAfterCutting_solution1(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int* products=new int[length+1];

//程序可以走进这里则length>3，products里的数字不能作为返回值，只是为计算进行的初始化
    products[0]=0;
    products[1]=1;
    products[2]=2;
    products[3]=3;

    int max=0;
    for(int i=4;i<=length;++i)
    {
        max=0;
        for(int j=1;j<=i/2;++j)
        {
            int product=products[j]*products[i-j];
            if(max<product)
                max=product;

            products[i]=max;//可以挪到这层循环的外面
        }
    }
    max=products[length];
    delete[] products;//清理内存

    return max;
}

//贪婪算法
//原理：当n足够大时（n>4），3越多越好，其次2越多越好.可以使用指数函数的图像来理解这个问题
int maxProductAfterCutting_solution2(int length)
{
    if(length<2)
        return 0;
    if(length==2)
        return 1;
    if(length==3)
        return 2;

    int timesOf3=length/3;//分出来的3的次数
    if(length-timesOf3*3==1)//这个时候退一个3组成2*2更好
        timesOf3-=1;

    int timesOf2=(length-timesOf3*3)/2;//分出来的2的次数
    return (int)(pow(3,timesOf3))*(int)(pow(2,timesOf2));
}


int main()
{
    int n;
    cin>>n;
    cout<<maxProductAfterCutting_solution1(n)<<endl;
    cout<<maxProductAfterCutting_solution2(n)<<endl;
}