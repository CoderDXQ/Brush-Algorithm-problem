void ReplaceBlank(char string[],int length)
{//length是string数组的容量
    if (string==nullptr||length<=0)
    {
        return;//增强健壮性
    }

    int originalLength=0;
    int numberOfBlank=0;
    int i=0;
    while(string[i]!='\0')//字符串的结束符
    {
        ++originalLength;
        if(string[i]==' ')
            ++numberOfBlank;
        
        ++i;
    }

    int newLength=originalLength+numberOfBlank*2;
    if(newLength>length)
        return;//增强健壮性

    int indexOfOriginal=originalLength;
    int indexOfNew=newLength;//从后往前来可以避免移动

    //indexOfNew<indexOfOriginal 出错
    //indexOfNew=indexOfOriginal 没有空格 不需要填充
    while (indexOfOriginal>=0 && indexOfNew>indexOfOriginal)
    {
        if(string[indexOfOriginal]==' ')
        {
            string[indexOfNew--]='0';
            string[indexOfNew--]='2';
            string[indexOfNew--]='%';
        }
        else
        {//结束符的赋值在这一步完成
            string[indexOfNew--]=string[indexOfOriginal];
        }
        --indexOfOriginal;
    }
}