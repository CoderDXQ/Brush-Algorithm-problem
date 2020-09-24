//方法一：递归
int g_maxValue=6;//单个骰子的最大数值就是6

void PrintProbability(int number)
{
    if(number<1)
        return;

    int maxSum=number* g_maxValue;
    int* pProbabilities=new int[maxSum-number+1];
    for(int i=number;i<=maxSum;i++)
        pProbabilities[i-number]=0;

    Probability(number,pProbabilities);

    int total=pow((double)g_maxValue,number);
    for(int i=number;i<maxSum;i++)
    {
        double ratio=(double)pProbabilities[i-number]/total;
        printf("%d:%e\n",i,radio);
    }

    delete[] pProbabilities;
}

void Probability(int number,int* pProbabilities)
{
    for(int i=1;i<=g_maxValue;i++)
        Probability(number,number,i,pProbabilities);
}

void Probability(int original,int current,int sum,int* pProbabilities)
{
    if(current==1)
    {
        pProbabilities[sum-original]++;
    }
    else
    {
        for(int i=1;i<=g_maxValue;i++)
        {
            Probability(original,current-1,i+sum,pProbabilities);
        }
    }
    
}
//方法二：循环
void PrintProbability(int number)
{
    if(number<1)
        return;
    
    int* pProbabilities[2];
    pProbabilities[0]=new int[g_maxValue*number+1];
    pProbabilities[1]=new int[g_maxValue*number+1];
    for(int i=0;i<g_maxValue*number+1;i++)
    {
        pProbabilities[0][i]=0;
        pProbabilities[1][i]=0;
    }

    int flag=0;

    for(int i=1;i<=g_maxValue;i++)
        pProbabilities[flag][i]=1;
    
    for(int k=2;k<=number;k++)
    {
        for(int i=0;i<k;i++)
            pProbabilities[1-flag][i]=0;

        for(int i=k;i<=g_maxValue*k;i++)
        {
            pProbabilities[1-flag][i]=0;
            for(int j=1;j<=i&&j<=g_maxValue;j++)
            {
                pProbabilities[1-flag][i]+=pProbabilities[flag][i-j];
            }

        }
        flag=1-flag;
    }
    double total=pow((double)g_maxValue,number);
    for(int i=number;i<=g_maxValue*number;i++)
    {
        double ratio=(double)pProbabilities[flag][i]/total;
        printf("%d:%e\n",i,ratio);
    }

    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}




































