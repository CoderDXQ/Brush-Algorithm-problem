//方法一：对每个自然数进行检查看是不是丑数，离线计算保存结果，变计算为查询
bool IsUgly(long number)
{
    while (number%2==0)
        number/=2;
    while (number%3==0)
        number/=3;
    while (number%5==0)
        number/=5;
    
    return (number==1)?true:false;
}

//在线处理方式
int GetUglyNumber(int index)
{
    if(index<=0)
        return 0;
    
    int number=0;
    int uglyFound=0;
    while (uglyFound<index)
    {
        ++number;

        if(IsUgly(number))
        {
            uglyFound++;
        }
    }
    return number;
}

//离线处理方式
long ugly[100000];
k=0;

void offline()
{
    for(register long i=1;i<LONG_MAX;i++)
    {//设置为寄存器变量可以提高运行速度
        if(IsUgly(i))
        {
            k++;
            ugly[k]=i;
        }
    }
}

long check(int index)
{
    return ugly[index];
}


//方法二：从因数个数的角度出发，按照因数个数递增的情况来构造丑数并保存
//这个方法也可以离线计算保存结果，变计算为查询
//这里有个2*2<5的问题
int GetUglyNumber_Solution2(int index)
{
    if(index<=0)
        return 0;
    
    int* pUglyNumber=new int[index];//存放所有的丑数
    pUglyNumber[0]=1;
    int nextUglyIndex=1;

    int* pMultiply2=pUglyNumber;
    int* pMultiply3=pUglyNumber;
    int* pMultiply5=pUglyNumber;

    while(nextUglyIndex<index)
    {
        int min=Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
        pUglyNumber[nextUglyIndex]=min;

//pMultiply2、pMultiply3、pMultiply5都是pUglyNumber上的指针
        while(*pMultiply2*2<=pUglyNumber[nextUglyIndex])
            pMultiply2++;//从pUglyNumber[nextUglyIndex]之前的数中找到一个*2刚好大于pUglyNumber[nextUglyIndex]的数
        while(*pMultiply3*3<=pUglyNumber[nextUglyIndex])
            pMultiply3++;//从pUglyNumber[nextUglyIndex]之前的数中找到一个*3刚好大于pUglyNumber[nextUglyIndex]的数
        while(*pMultiply5*5<=pUglyNumber[nextUglyIndex])
            pMultiply5++;//从pUglyNumber[nextUglyIndex]之前的数中找到一个*5刚好大于pUglyNumber[nextUglyIndex]的数

        nextUglyIndex++;
    }
    int ugly=pUglyNumber[nextUglyIndex-1];
    delete[] pUglyNumber;//清理内存
    return ugly;
}

int Min(int number1,int number2,int number3)
{//返回三个数的最小者
    int min=(number1<number2)>number1:number2;
    min=(min<number3)?min:number3;

    return min;
}












