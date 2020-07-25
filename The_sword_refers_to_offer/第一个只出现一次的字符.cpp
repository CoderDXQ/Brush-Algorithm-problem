//字符串中第一个只出现一次的字符
char FirstNotRepeatingChar(char* pString)
{
    if(pString==nullptr)
        return '\0';//健壮性
    const int tableSize=256;
    unsigned int hashTable[tableSize];
    for(unsigned int i=0;i<tableSize;i++)
        hashTable[i]=0;//初始化

    char* pHashKey=pString;
    while(*(pHashKey)!='\0')
        hashTable[*(pHashKey++)]++;//直接用ASCII码做下标

    pHashKey=pString;//复位
    while(*pHashKey!='\0')
    {
        if(hashTable[*pHashKey]==1)
            return *pHashKey;//返回的是ASCII码可以直接输出为字符

        pHashKey++;
    }

    return '\0';
}