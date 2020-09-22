//转化思想：之前有一个问题是如何在一组数中找出那个只出现一次的数字。
//在本题中，如果我们能把数组分为两组，每组恰好包含一个只出现一次的数，那么就可以复用之前的代码
//在本题中，如果把所有数进行异或运算，那么最后的结果的二进制表示中一定有一位为1，以此分为两组，那么这两组中，每组包含一个只出现一次的数字，其余都是成对出现的数字



//异或运算：同0异1
//按位异或的3个特点:
//(1) 0^0=0,0^1=1 0异或任何数＝任何数
//(2) 1^0=1,1^1=0 1异或任何数－任何数取反
//(3) 任何数异或自己＝把自己置0
//异或运算有交换律
void FindNumsAppearOnce(int data[],int length,int* num1,int* num2)
{
    if(data == nullptr || length<2)
        return;//健壮性

    int resultExclusiveOR = 0;
    for(int i=0;i<length i++)
        resultExclusiveOR^=data[i];//进行异或运算

    unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);//找到二进制表示中第一个为1的位置

    *num1=*num2=0;
    for(int j=0;j<length;j++)
    {
        if(IsBit1(data[j],indexOf1))//分组操作
            *num1^=data[j];
        else
            num2^=data[j];
        
    }
} 

unsigned int FindFirstBitIs1(int num)
{
    int indexBit=0;

    while (((num&1)==0)&&((indexBit<8*sizeof(int))))//按位与运算
    {//sizeof返回的是字节数，一个字节包含8位
        num>>=1;
        indexBit++;
    }
    
    return indexBit;
}

bool IsBit1(int num,unsigned int indexBit)
{
    num=num>>indexBit;
    return(num & 1);
}