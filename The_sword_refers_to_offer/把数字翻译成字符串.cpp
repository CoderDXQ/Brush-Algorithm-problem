//DFS或者数学计算

//没必要这么麻烦，不如直接读入一个字符串
int GetTranslationCount(int number)
{
    if(number<0)
        return;//健壮性

    string numberInString=to_string(number);
    return GetTranslationCount(numberInString);
}

int GetTranslationCount(const string& number)
{//从后往前计算
    int length=number.length();
    int* counts=new int[length];
    int count=0;

    for(int i=length-1;i>=0;i--)
    {
        count=0;
        if(i<length-1)
            count=counts[i+1];//继承之前的计算结果
        else//第一次进入循环
            count=1;

        if(i<length-1)
        {
            int digit1=number[i]-'0';
            int digit2=number[i+1]-'0';
            int converted=digit1*10+digit2;
            if(converted>=10 && converted<=25)
            {
                if(i<length-2)
                    count+=counts[i+2];
                else//此时不可能有两位数的情况
                    count+=1;
            }
        }
        counts[i]=count;
    }
    count=counts[0];
    delete[] counts;

    return count;
}