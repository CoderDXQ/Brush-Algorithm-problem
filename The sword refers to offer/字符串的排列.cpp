//用递归的思想分解问题  类似于汉诺塔问题
//？？？本题的拓展题目也要看一下 在本书附带的代码中应该有 复习的时候看即可

 
 //需要调试一下看看结果

void Permutation(char* pStr)
{
    if(pStr==nullptr)
        return;
    Permutation(pStr,pStr);//直接传指针
}
void Permutation(char* pStr,char* pBegin)
{
    if(*pBegin=='\0')
    {
        printf("%s\n",pStr);
    }
    else
    {
        for(char* pCH=pBegin;*pCH!='\0';pCH++)
    //for(char* pCH=pBegin+1;*pCH!='\0';pCH++) 
    //换成这一句可能会更好 pBegin+1是指指针向后移动一位，可能不是这样的写法
        {//使用指针，每次都是在pStr上操作
            char temp=*pCH;
            *pCH=*pBegin;
            *pBegin=temp;//交换

            Permutation(pStr,pBegin+1);
        
            char temp=*pCH;
            *pCH=*pBegin;
            *pBegin=temp;//再换回去 相当于回溯
        }
    }
}

//？？？再看一下STL函数中全排列函数的实现代码next_permutation(arr, arr+size);

//输出顺序
/*
abc 
acb 
bac 
bca 
cba
cab 
*/



