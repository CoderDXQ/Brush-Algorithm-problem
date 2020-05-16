//这个方法不适用于n为负数的情况 负数右移最高位是1 会陷入死循环
int NumberOf1(int n)
{
    int count=0;
    while(n)
    {
        if(n & 1)
//这个运算的实质是n的二进制的每一位与00000001进行与运算，每一位的结果连接起来又是一个八位数，因此只要有一次运算为1，则结果为真
            count++;
        n=n>>1;//右移一位（以符号位填充，负数填充1）
    }
    return count;
}


//常规解法
int NumberOf1(int n)
{
    int count=0;
    unsigned int flag=1;
    while (flag)
    {
        if(n & flag)
        {
            count++;
        }
        flag<<=1;
//当循环进行的次数足够多时，flag二进制表示中唯一的1会被左移运算搞的溢出从而丢失，此时flag=0，不能再进入循环体
    }
    return flag;
}

//优秀解法 减1操作
//原理：n每次和n-1进行一次与运算可以将n的二进制表示中最右边的一个1消去
int NumberOf1(int n)
{
    int count=0;
    while(n)
    {
        ++count;
        n=(n-1)& n;
    }
    return count;
}


