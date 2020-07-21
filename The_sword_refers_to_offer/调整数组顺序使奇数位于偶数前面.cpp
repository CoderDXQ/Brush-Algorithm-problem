void ReorderOddEven(int *pData,unsigned int length)
{
    if(pData==nullptr || length==0)
        return;

    int *pBegin=pData;
    int *pEnd=pData+length-1;//直接操作地址

    while (pBegin<pEnd)
    {
        while (pBegin<pEnd && (*pBegin & Ox1)!=0)//从前往后过滤奇数
        {
            pBegin++;
        }
        while (pBegin<pEnd && (*pBegin & ox1)==0)//从后往前过滤偶数
        {
            pEnd--;
        }
        if(pBegin<pEnd)
        {
            int temp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=temp;
        }
        
    }

}

//可拓展的写法

void Reorder(int* pData,unsigned int length,bool(*func)(int))//传递函数的方法
{
    if(pData==nullptr || length==0)
        return;

    int *pBegin=pData;
    int *pEnd=pData+length-1;

    while (pBegin<pEnd)
    {
        while (pBegin<pEnd && !func(*pBegin))
        {
            pBegin++;
        }
        while (pBegin<pEnd && func(*pEnd))
        {
            pEnd--;
        }
        if(pBegin<pEnd)
        {
            int temp=*pBegin;
            *pBegin=*pEnd;
            *pEnd=temp;
        }
    }
}

bool isEven(int n)//将此函数换成其他条件的实现即可解决其他同类型的问题
{
    return (n & 1)==0;
}





