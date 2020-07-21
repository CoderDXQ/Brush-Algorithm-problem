//方法一：利用快速排序中的分割思想Partition

void GetLeastNumbers(int* input,int n,int* output,int k)
{
    if(input==nullptr||output==nullptr||k>n||n<=0||k<=0)
        return;//健壮性

    int start=0;
    int end=n-1;
    int index=Partition(input,n,start,end);
//index是返回的游标的下标 游标左侧全部小于游标 游标右侧全部大于游标
    while(index!=k-1)
    {
        if(index>k-1)
        {//根据情况选取游标的左右两侧进行Partition
            end=index-1;
            index=Partition(index,n,start,end);
        }
        else
        {
            start=index+1;
            index=Partition(input,n,start,end);
        }
    }
    //此时index==k-1，正好数组前k个数是最小的k个数，但这k个数不一定是按顺序的
    for(int i=0;i<k;i++)
        output[i]=input[i];
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



//方法二：堆或红黑树

void GetLeastNumbers(const vector<int>& data,intSet& leastNumbers,int k)
{//intSet本身就是使用红黑树维护的
    leastNumbers.clear();//初始化

    if(k<1||data.size()<k)
        return;
//数字原来存在vector型的data中
    vector<int>::const_iterator iter=data.begin();
    for(;iter!=data.end();iter++)
    {
        if(leastNumbers.size()<k)
            leastNumbers.insert(*iter);
        else
        {//leastNumbers中始终不超过k个数
            setIterator iterGreatest=leastNumbers.begin();
            //leastNumbers中最大的数
            if(*iter<*(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);//插入后会自动排序，leastNumbers.begin()依然是最大的数
            }
        }
    }
}











