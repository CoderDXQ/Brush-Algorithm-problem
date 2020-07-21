//pPush是压入序列
//pPop是弹出序列

bool IsPopOrder(const int* pPush,const int* pPop,int nLength)
{
    bool bPossible=false;
    if(pPush!=nullptr && pPop!=nullptr && nLength>0)
    {
        const int* pNextPush=pPush;
        const int* pNextPop=pPop;//这是两个移动的指针

        std::stack<int>stackData;

        while (pNextPop-pPop<nLength)//弹出序列没走完
        {
            while(stcakData.empty()||stackData.top()!=*pNextPop)
            {//需要压入 循环压入
                if(pNextPush-pPush==nLength)
                    break;

                stackData.push(*pNextPush);
                pNextPush++;
            }
            if(stackData.top()!=*pNextPop)
                break;//循环压入后仍然不匹配则退出 退出后返回false
            
            //走到这里说明匹配了 进行弹栈操作
            stackData.pop();
            pNextPop++;
        }
        if (stackData.empty() && pNextPop-pPop==nLength)
        {//唯一返回值为真的条件
            bPossible=true;
        }
    }
    return bPossible;
}