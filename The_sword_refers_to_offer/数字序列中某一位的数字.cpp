//数论的问题要学会分解问题

int digitAtIndex(int index)
{//index是代表序列中的第几位
    if(index<0)
        return -1;
    int digits=1;//数字的位数
    while(true)
    {
        int numbers=countOfIntegers(digits);
        if(index<numbers*digits)//此时代表这个位数的数字命中了index
            return digitAtIndex(index,digits);
//若index>=numbers*digits，说明这个位数的数字全体不能凑够index长的序列       
        index-=digits*numbers;
        digits++;
    }
    return -1;//此时代表没找到
}

int countOfIntegers(int digits)
{//返回几位数的个数
    if(digits==1)
        return 10;
    
    int count=(int)std::pow(10,digits-1);
    return 9*count;
}

int digitAtIndex(int index,int digits)
{//此时index是在位数为digits的数字组成的序列中的下标
    int number=beginNumber(digits)+index/digits;//number就是目标数字

    //提取具体的那一位 这里认为index是从0开始
    int indexFromRight=digits-index%digits;
    for(int i=1;i<indexFromRight;i++)
        number/=10;
    return number%10;
}

int beginNumber(int digits)
{//计算10的次方
    if(digits==1)
        return 0;
    
    return (int)std::pow(10,digits-1);
}