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

char* ReverseSentence(char* pData)
{
    if(pData==nullptr)
        return nullptr;
    
    char *pBegin=pData;

    char *pEnd=pData;

    while (*pEnd!='\0')
        pEnd++;
    pEnd--;//找到最后一个有效字符

    Reverse(pBegin,pEnd);//反转整个句子

    //反转整个句子中的每个单词
    pBegin=pEnd=pData;
    while(*pBegin!='\0')
    {
        if(*pBegin==' ')
        {
            pBegin++;
            pEnd++;
        }
        else if(*pEnd==' '||pEnd=='\0')
        {
            Reverse(pBegin,--pEnd);
            pBegin=++pEnd;
        }
        else
        {
            pEnd++;
        }
    }    
    return pData;
}