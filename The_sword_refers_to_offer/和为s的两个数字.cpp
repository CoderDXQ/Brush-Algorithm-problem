//前后双指针

bool FindNumbersWithSum(int data[],int length,int sum,int* num1,int* num2)
{
    bool found=false;
    if(length<1||num1==nullptr||num2==nullptr)
        return found;

    int ahead=length-1;
    int behind=0;

    while (ahead>behind)
    {
        long long curSum=data[ahead]+data[behind];

        if(curSum==sum)
        {
            *num1=data[behind];
            *num2=data[ahead];
            found=true;
            break;
        }
        else if(curSum>sum)
            ahead--;
        else
            behind++;
    }
    return found;
}