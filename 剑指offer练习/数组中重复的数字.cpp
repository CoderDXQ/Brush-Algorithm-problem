//在不使用标记数组情况下的做法

//数理方法
bool duplicate(int numbers[],int length,int* duplication)
{
    if(numbers==nullptr||length<=0)
    {
        return false;
    }
    for(int i=0;i<length;++i)//i++还是++i要看具体的数组
    {
        if(numbers[i]<0||numbers[i]>length-1)
        {
            return false;
        }
    }//以上代码是为了增强代码的健壮性

    for(int i=0;i<length;++i)
    {
        while (numbers[i]!=i)
        {//略过下标与数字相同的情况
            if(numbers[i]==numbers[numbers[i]])
            {//找到重复数字
                *duplication=numbers[i];
                return true;
            }
            //下标与数字不同的情况  交换即可
            int temp=numbers[i];
            numbers[i]=numbers[temp];
            numbers[temp]=temp;
        }
    }

    return false;
}

//二分法
int getDuplication(const int* numbers,int length)
{//直接传入数组的地址
    if(numbers==nullptr||length<0)
    {
        return -1;//表示函数执行失败
    }//增加健壮性

    int start=1;
    int end=length-1;
    while (end>=start)
    {
        int middle=((end-start)>>1)+start;//正确计算公式
        int count=countRange(numbers,length,start,middle);
        //计算左半边数字在数组中的重复次数
        if(end==start)
        {
            if(count>1)
                return start;
            else 
                break;
        }
        if(count>(middle-start+1))
            end=middle;//左半边必有重复
        else//右半边必有重复
            start=middle+1;
    }
    return -1;
}

int countRange(const int* numbers,int length,int start,int end)
{
    if(numbers==nullptr)
        return 0;//增加健壮性

    int count=0;
    for(int i=0;i<length;i++)
        if(numbers[i]>=start&&numbers[i]<=end)
            ++count;

    return count;
}

