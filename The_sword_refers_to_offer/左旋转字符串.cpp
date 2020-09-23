//方法一：复用前面的反转代码
char* LeftRotateString(char* pStr,int n)
{
    if(pStr!=nullptr)
    {
        int nLength = static_cast<int>(strlen(pStr));//static_cast是一种类型转换
        if(nLength>0 && n>0 && n<nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr+n-1;
            char* pSecondStart = pStr+n;
            char* pSecondEnd = pStr+nLength-1;

            //反转字符串第一部分
            Reverse(pFirstStart,pFirstEnd);
            //反转字符串第二部分
            Reverse(pSecondStart,pSecondEnd);
            //整体反转
            Reverse(pFirstStart,pSecondEnd);
        }
    }
    return pStr;
}

void Reverse(char *pBegin,char *pEnd)
{
    if(pBegin==nullptr || pEnd==nullptr)
        return;
    
    while (pBegin<pEnd)
    {
        char temp=*pBegiin;
        *pBegin=*pEnd;
        *pEnd=temp;

        pBegin++;
        pEnd--;
    }
}

//方法二：使用string函数直接进行拼接

？？？？？？？？