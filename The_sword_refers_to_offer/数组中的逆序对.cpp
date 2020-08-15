//利用了归并排序的原理，在此基础上做了修改

int InversePairs(int* data,int length)
{
    if(data==nullptr||length<0)
        return 0;
    
    int* copy = new int[length];
    //这个过程可用memcpy(copy,data,sizeof(int)*length);memcpy是在内存中按位复制
    for(int i=0;i<length;i++)
        copy[i]=data[i];

    int count = InversePairsCore(data,copy,0,length-1);
    delete[] copy;//清理内存
    return count;
}

int InversePairsCore(int* data,int* copy,int start,int end)
{
    if(start == end)
    {//分组只有一个元素的情况
        copy[start]=data[start];
        return 0;
    }

    int length=(end-start)/2;//继续分组后的长度

//DFS
    int left=InversePairsCore(copy,data,start,start+length);
    int right=InversePairsCore(copy,data,start+length+1,end);

//i初始化为前半段最后一个数字的下标，j初始化为后半段最后一个数字的下标，从后往前进行merge
    int i=start+length;
    int j=end;

    int indexCopy=end;//辅助数组也是从后往前
    int count=0;

    while (i>=start && j>=start+end+1)
    {
        if(data[i]>data[j])
        {//存在逆序对的情况:左半部分下标为i的数大于右半部分下标为j的数
            copy[indexCopy--]=data[i--];
            count+=j-start-length;//增加的逆序对的数量等于右半部分的剩余长度
        }
        else//不存在逆序对：右半部分下标为j的数大于左半部分下标为i的数
        {
            copy[indexCopy--]=data[j--];
        }
    }

//合并两个进行merge的数组中的残余部分
    for(;i>=start;i--)
        copy[indexCopy--]=data[i];
    for(;j>=start+length+1;j--)
        copy[indexCopy--]=data[j];
//左半部分的逆序对数+右半部分的逆序对数+本轮归并的逆序对数
    return left+right+count;
}