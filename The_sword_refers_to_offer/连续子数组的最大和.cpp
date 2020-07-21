//一般方法 数据量小可以用这种方法，数据量大（百万）必须用动态规划
bool g_InvalidInput=false;

int FindGreatestSumOfSubArray(int* pData,int nLength)
{
    if(pData==nullptr||nLength<=0)
    {
        g_InvalidInput=true;
        return 0;
    }
    g_InvalidInput=false;

    int nCurSum=0;
    int nGreatestSum=Ox80000000;

    for(int i=0;i<nLength;i++)
    {
        if(nCurSum<=0)//和为负，说明可以断开了
            nCurSum=pData[i];
        else
            nCurSum+=pData[i];
        
        if(nCurSum>nGreatestSum)
            nGreatestSum=nCurSum;
    }
    return nGreatestSum;
}


//动态规划：动态规划就是递归+记忆

int GetMax(int a, int b)   //得到两个数的最大值
{
    return (a) > (b) ? (a) : (b);
}

int GetMaxAddOfArray(int* arr, int sz)
{
    if (arr == NULL || sz <= 0)
        return 0;//健壮性

    int Sum = arr[0];   //临时最大值
    int MAX = arr[0];   //比较之后的最大值

    for (int i = 1; i < sz; i++)
    {//Sum可以计算每一段的和
        Sum = GetMax(Sum + arr[i], arr[i]);   //状态转移方程，只有两种情况，是否与之前的那一段相连接

//MAX记录最大的那一段的和
        if (Sum >= MAX)
            MAX = Sum;
    }
    return MAX;
}

int main()
{
    int array[] = { 2, 3, -6, 4, 6, 2, -2, 5, -9 };
    int sz = sizeof(array) / sizeof(array[0]);//数组长度
    int MAX = GetMaxAddOfArray(array, sz);
    cout << MAX << endl;
    return 0;
}







