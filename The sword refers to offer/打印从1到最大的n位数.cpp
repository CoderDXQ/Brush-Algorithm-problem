//long long是64位,所以如果不用数组来做的话n不会很大

//字符串解法
void PrintToMaxOfNDigits(int n)
{
    if(n<0)
        return;
    char* number=new char[n+1];//用指针来做方便很多
    memset(number,'0',n);
    number[n]='\0';

    while (!Increment(number))
    {//在数组自增的过程设置一个标记，当数组达到全9状态时触发标记变化，那么就不用每次都监测数组是否达到全9状态了
    //这样就把这一步的时间复杂度从O(n)优化为O(1)
        PrintNumber(number);
    }

    delete []number;//防止内存溢出
}

bool Increment(char* number)
{
    bool isOverflow=false;
    int nTakeOver=0;
    int nLength=strlen(number);
    for(int i=nLength-1;i>=0;i--)
    {//倒着来 符合数字正常的位数顺序 这个循环要处理数字的每一位
        int nSum=number[i]-'0'+nTakeOver;
        if(i==nLength-1)
            nSum++;//数字的最低位自增1
        if(nSum>=10)
        {
            if(i==0)
                isOverflow=true;//停止增长 最后会返回这个值
            else
            {
                nSum-=10;
                nTakeOver=1;//进位
                number[i]='0'+nSum;
            }
            
        }
        else
        {
            number[i]='0'+nSum;
            break;
        }
    }
    return isOverflow;
}
void PrintNumber(char* number)
{
    bool isBeginning0=true;
    int nLength=strlen(number);

    for(int i=0;i<nLength;i++)
    {
        if(isBeginning0 && number[i]!='0')
            isBeginning0=false;//过滤掉数组前面的0
        
        if(!isBeginning0)
        {
            printf("%c",number[i]);
        }
    }
    print("\t")
}

//数字数组解法
？？？？？？？？？
自己写一下
方法模仿上面的方法
跑一下试试


//全排列解法
void PrintToMaxOfNDigits(int n)
{
    if(n<0)
        return;
    char* number=new char[n+1];
    number[n]='\0';

    for(int i=0;i<10;i++)
    {
        number[0]=i+'0';
        PrintToMaxOfNDigitsRecursively(number,n,0);
    }
    delete[] number;
}

void PrintToMaxOfNDigitsRecursively(char* number,int length,in index)
{//用递归实现全排列 
    if(index==length-1)
    {
        PrintNumber(number);
        return;
    }
    for(int i=0;i<10;i++)
    {
        number[index+1]=i+'0';
        PrintToMaxOfNDigitsRecursively(number,length,index+1);
    }
}




















//全排列的函数实现
？？？？？？？
自己写一下
跑一下试试