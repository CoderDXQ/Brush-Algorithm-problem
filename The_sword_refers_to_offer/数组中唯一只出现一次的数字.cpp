//位运算的思想

int FindNumberAppearingOnce(int numbers[],int length)
{
    if (numbers == nullptr || length<=0)
        throw new std::exception("invalid input.");

    int bitSum[32]={0};//初始化 int整型只占32位

    for (int i = 0; i < length; i++)
    {
        int bitMask=1;
        for (int j = 31; j >= 0 ; j--)
        {
            int bit =numbers[i] & bitMask;//计算二进制某一位的值
            if(bit!=0)
                bitSum[j]+=1;
            bitMask = bitMask << 1;
        }
    }

    int result = 0;
    for(int i=0;i<32;i++)
    {
        result=result<<1;
        result+=bitSum[i]%3;
    }   

    return result;
}