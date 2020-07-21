//第一种方法：如果这个数字存在，那么排序后的中位数一定是这个数字
//这个算法就是坨屎，函数CheckMoreThanHalf的时间复杂度是O(n)

int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))
        return 0;//检查数组是否无效

    int middle=length>>1;
    int start=0;
    int end=length-1;
    int index=Partition(numbers,length,start,end);
//Partition函数可以使数组中index左边的数都小于numbers[index]，而右边都大于
    while(index!=middle)
    {//排序
        if(index>middle)
        {
            end=index-1;
            index=Partition(numbers,length,start,end);
        }
        else
        {
            start=index+1;
            index=Partiton(numbers,length,start,end);
        }
    }

    int result=numbers[middle];

    if(!CheckMoreThanHalf(numbers,length,result))
        result=0;//检查结果是否无效
    
    return result;
}

bool g_bInputInvalid=false;
bool CheckInvalidArray(int* numbers,int length)
{//无效数组
    g_bInputInvalid=false;
    if(numbers==nullptr || length<=0)
        g_bInputInvalid=true;

    return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers,int length,int number)
{//检查结果是否有效
    int times=0;
    for(int i=0;i<length;i++)
    {
        if(numbers[i]==number)
            times++;
    }
    bool isMoreThanHalf=true;
    if(times*2<length)
    {
        g_bInputInvalid=true;
        isMoreThanHalf=false;
    }
    return isMoreThanHalf;
}
int Partition(int data[],int length,int start,int end)
{
    if(data==nullptr||length<=0||start<0;||end>=length)
        throw new std::exception("Invalid Parameters");

//选举游标
    int index=RandomInRange(start,end);
    Swap(&data[index],&data[end]);

    int small=start-1;
    for(index=start;index<end;index++)
    {
        if(data[index]<data[end])
        {//此时data[end]里的值是选举出来的游标
            small++;
            if(small!=index)//这种时候的上一次for循环出现了一次data[index]>=data[end]的情况
            //此时data[small]里的数大于游标，交换之后data[small]里的数小于游标
                Swap(&data[index],&data[small]);
        }
    }
   // 游标归位，游标左侧全部小于游标，游标右侧全部大于游标
    small++;
    Swap(&data[small],&data[end]);
    return small;
}



//方法二：假设过半数的数为x，那么x和非x的数相互抵消后的数(result)，即为所求。
int MoreThanHalfNum(int* numbers,int length)
{
    if(CheckInvalidArray(numbers,length))
        return 0;

    int result=numbers[0];
    int times=1;
    for(int i=0;i<length;i++)
    {
        if(times==0)
        {
            result=numbers[i];
            times=1;
        }
        else if(numbers[i]==result)
            times++;
        else
            times--;
    }
    if(!CheckMoreThanHalf(numbers,length,result))
        result=0;

    return result;
}