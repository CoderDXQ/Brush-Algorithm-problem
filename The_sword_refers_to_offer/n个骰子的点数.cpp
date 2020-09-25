P295

？？？？？？这个是输出概率的，自己再写一个输出所有可能情况的


//方法一：递归
int g_maxValue=6;//单个骰子的最大数值就是6

void PrintProbability(int number)//number是骰子个数
{
    if(number<1)
        return;

    int maxSum=number*g_maxValue;//可能出现的最大的和s
    //maxSum-number+1是节省空间的写法，当然也可以阔气一点
    int* pProbabilities=new int[maxSum-number+1];//记录数组，在其他函数中直接用指针操作
    for(int i=number;i<=maxSum;i++)
        pProbabilities[i-number]=0;//初始化记录数组

    Probability(number,pProbabilities);//调用

    int total=pow((double)g_maxValue,number);//计算总的可能数
    for(int i=number;i<maxSum;i++)
    {//计算并输出概率
        double ratio=(double)pProbabilities[i-number]/total;
        printf("%d:%e\n",i,radio);
    }

    delete[] pProbabilities;//删除指针，防止内存溢出
}

void Probability(int number,int* pProbabilities)
{//第一层递归
    for(int i=1;i<=g_maxValue;i++)
        Probability(number,number,i,pProbabilities);
}

void Probability(int original,int current,int sum,int* pProbabilities)
{//original是总的骰子数，current是当前正在递归的骰子，从第number个骰子往第一个递归
    if(current==1)
    {//递归到最后一层计数
        pProbabilities[sum-original]++;//节省空间的写法，也可以阔气一点
    }
    else
    {
        for(int i=1;i<=g_maxValue;i++)//当前骰子的六个点数
        {
            Probability(original,current-1,i+sum,pProbabilities);//i+sum是当前的总点数
        }
    }
    
}
//方法二：循环 简单的数学过程模拟
void PrintProbability(int number)
{
    if(number<1)
        return;
    
    int* pProbabilities[2];
    pProbabilities[0]=new int[g_maxValue*number+1];
    pProbabilities[1]=new int[g_maxValue*number+1];
    for(int i=0;i<g_maxValue*number+1;i++)
    {//初始化
        pProbabilities[0][i]=0;
        pProbabilities[1][i]=0;
    }

    int flag=0;//用于实现滚动数组

    for(int i=1;i<=g_maxValue;i++)
        pProbabilities[flag][i]=1;//第一个骰子的情况初始化
    
    for(int k=2;k<=number;k++)
    {//一个骰子一个骰子的加
        for(int i=0;i<k;i++)
            pProbabilities[1-flag][i]=0;//另一行初始化

        for(int i=k;i<=g_maxValue*k;i++)
        {//当前骰子总个数下s的所有可能情况
            pProbabilities[1-flag][i]=0;
            for(int j=1;j<=i&&j<=g_maxValue;j++)
            {//当前骰子和s下，所有可能的情况
                pProbabilities[1-flag][i]+=pProbabilities[flag][i-j];
            }

        }
        flag=1-flag;//滚动
    }
    double total=pow((double)g_maxValue,number);//总的情况
    for(int i=number;i<=g_maxValue*number;i++)
    {//各种情况的输出概率
        double ratio=(double)pProbabilities[flag][i]/total;
        printf("%d:%e\n",i,ratio);
    }

    delete[] pProbabilities[0];
    delete[] pProbabilities[1];//清理指针，防止内存泄漏
}




































