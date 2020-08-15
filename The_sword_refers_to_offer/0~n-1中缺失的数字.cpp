//有序数组优先考虑二分法
//数字和下标都是严格单增且级差相同 因此数字和下标可以建立映射关系

int GetMissingNumber(const int* numbers,int length)
{
    if(numbers==nullptr||length<=0)
        return -1;
    
    int left=0;
    int right=length-1;

    while (left<=right)
    {
        int middle=(left+right)>>1;
        if(numbers[middle]!=middle){
            if(numbers[middle-1]=middle-1 ||middle==0)
                return middle;//边界情况的特判和刚好查到结果
            right=middle-1;
        }
        else
            left=middle+1;
    }

    if(left==length)//此时left指针已经超界
        return length;

//没有结果或者无效的输入
    return -1;
}