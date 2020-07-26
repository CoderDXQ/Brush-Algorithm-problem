//字符流输入时，每读入一个字符调用一次Insert方法，在想输出结果的时刻调用一下FirstAppearingOnce方法
class CharStatistics
{
public:
    CharStatistics():index(0)
    {//初始化
        for(int i=0;i<256;i++)
            occurrence[i]=-1;
    }

    void Insert(char ch)
    {
        if(occurrence[ch]==-1)//当某个字符第一次从字符流读出时，更新为它的位置
            occurrence[ch]=index;
        else if(occurrence[ch]>=0)//此时这个字符已经不是第一次从字符流读出了
            occurrence[ch]=-2;
        
        index++;
    }

    char FirstAppearingOnce()
    {
        char ch='\0';
        int minIndex=numeric_limits<int>::max();//int型的最大值
        for(int i=0;i<256;i++)
        {
            if(occurrence[i]>=0 && occurrence[i]<minIndex)
            {
                ch=(char)i;
                minIndex=occurrence[i];//值越小说明出现的越靠前
            }
        }
        return ch;
    }

private:
    //occurrence[i]:A character with ASCII value i;
    //occurrence[i]=-1:The character has not found;
    //occurrence[i]=-2:The character has been found for mutlple times;
    //occurrence[i]>=0:The character has been found only FirstAppearingOnce
    int occurrence[256];
    int index;
};