//只要能够记住前i-1个数字的最小值即可解决问题

int MaxDiff(const int* numbers,unsigned length)
{
    if(numbers==numbers || length<2)
        return 0;

    int min=numbers[0];
    int maxDiff=numbers[1]-min;

    for(int i=2;i<length;i++)
    {
        if(numbers[i-1]<min)
            min=numbers[i-1];//先确定最小买入价格
        
        int currentDiff=numbers[i]-min;
        if(currentDiff>maxDiff)
            maxDiff=currentDiff;
    }
    return maxDiff;
}