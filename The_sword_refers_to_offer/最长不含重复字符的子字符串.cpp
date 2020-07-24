//方法一：动态规划+哈希技巧
int longestSubstringWithoutDuplication(const std::string& str)
{
    int curLength=0;//片段长度
    int maxLength=0;//

    int* position=new int[26];
    for(int i=0;i<str.length();i++)
        position[i]=-1;//初始化
    
    for(int i=0;i<str.length();i++)
    {
        int prevIndex=position[str[i]-'a'];//上次出现这个字符的位置
        if(prevIndex<0 || i-prevIndex>curLength)
            curLength++;//这个字符头一次出现或者上一次出现在正在进行的片段之前
        else
        {//这个字符上次出现的位置在正在进行的片段内部，此时正在进行的片段完结
            if(curLength>maxLength)//截取新的片段之前要判定存储最大长度
                maxLength=curLength;//存储记录之后才能截取新的片段

            curLength=i-prevIndex;//截取新的片段
        }
        position[str[i]-'a']=i;//更新某字符出现的最新位置
    }
    //这个步骤是补的，防止最后一个片段的长度是最大的而没有更新maxLength
    if(curLength>maxLength)
        maxLength=curLength;
    
    delete[] position;//清理内存
    return maxLength;
}