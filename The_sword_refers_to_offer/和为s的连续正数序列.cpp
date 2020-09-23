//连续正数序列就是自然数序列

//除了模拟的方法还可以直接计算

//方法一：模拟

void FindContinuousSequence(int sum)
{
    if(sum<3)
        return;
    
    int small=1;
    int big=2;
    int middle=(1+sum)/2;
    int curSum=small+big;

//sum是
    while (small<middle)//保证这个序列至少有两个数字
    {
        if(curSum==sum)
            PrintContinuousSequence(small,big);

        while (curSum>sum && small<middle)
        {
            curSum-=small;
            small++;

            if(curSum==sum)
                PrintContinuousSequence(small,big);
        }

        big++;
        curSum+=big;//右加左退   
    }
}

void PrintContinuousSequence(int small,int big)
{

    for(int i=small;i<=big;i++)
        printf("%d ",i);
    printf("\n");
}



//方法二：将s拆成n*m=s的形式，根据高斯公式进行计算



？？？？？？？？有时间写一下
