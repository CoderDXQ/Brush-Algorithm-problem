//这个问题一共有匹配形式三种形式 1字符相同 2'.' 3'*'
//其中第三种情况比较特别，要展开看看 
//这里除了使用递归方法还可以使用while
bool match(char* str,char* pattern)
{
    if(str==nullptr || pattern==nullptr)
    {
        return false;
    }//健壮性

    return matchCore(str,pattern);
}

bool matchCore(char* str,char* pattern)
{
    if(*str=='\0' && *pattern=='\0')
        return true;//模式串和匹配串同时走完 唯一的一种匹配的情况
    if(*str!='\0' && *pattern=='\0')
        return false; //模式串用完了但是匹配串还有剩余
    if(*(pattern+1)=='*')//‘*’的匹配形式
    {
        if(*pattern==*str || (*pattern=='.' && *str!='\0'))
        {//三种可能都往下走 又一个能走通就是true 三个都走不通就是false
            return matchCore(str+1,pattern+2)||matchCore(str+1,pattern)||matchCore(str,pattern+2);
        }//        只匹配到一个                  匹配到至少一个先走一个        匹配串可以不走(虽然匹配到了)    
        //这里是实际是dfs         
        else//匹配串中走到的位置有模式串的*之前的字符不同 即*匹配0个字符串的情况
            return matchCore(str,pattern+2);
    }
    if(*str==*pattern || ({*pattern=='.' && *str!='\0'}))//字符相同或者模式串中走到了'.'
        return matchCore(str+1,pattern+1);
    
    return false;
}

//？？？？？？？用非递归的方法写一个
//自己写几个测试用例试一下
//在牛客网找找测试集试一下 














