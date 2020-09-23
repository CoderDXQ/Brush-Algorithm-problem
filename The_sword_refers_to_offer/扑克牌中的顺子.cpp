//如果大小王的个数大于等于gap的个数，那就可以组成顺子
//如果最大最小数的差大于4，那就不可能组成顺子
//非大小王的数字不能有重复




bool IsContinuous(int* numbers,int length)
{
    if(numbers==nullptr || length<1)
        return false;
    
    qsort(numbers,length,sizeof(int),compare));

    int numberOfZero=0;
    int numberOfGap=0;

    for(int i=0;i<length && numbers[i]==0;i++)
        ++numberOfZero;//统计大小王

    int small=numberOfZero;//0是大小王 small是第一个非0数排序后的下标
    int big=small+1;//
    while (big<length)
    {
        if(numbers[small]==numbers[big])//检查是否有对子存在
            return false;
        
        numberOfGap+=numbers[big]-numbers[small]-1;//统计总的gap数
        small=big;
        big++;
    }
    return (numberOfGap>numberOfZero)?false:true;//gap数大于大小王的总数就不能成为顺子
}

int compare(const void *arg1,const void *arg2)//定义qsort的比较规则
{
    return *(int*)arg1-*(int*)arg2;//指针类型的强制类型转换
}