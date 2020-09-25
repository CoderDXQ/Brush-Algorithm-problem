enum Status {kValid=0,kInvalid};//记录是不是遇到了非法输入
int g_nStatus=kValid;

int StrToInt(const char* str)
{
    g_nStatus=kInvalid;
    long long num=0;

    if(str!=nullptr && *str!='\0')
    {
        bool minus=false;
        //判定正负
        if(*str=='+')
            str++;
        else if(*str=='-')
        {
            str++;
            minus=true;
        }

        if(*str!='\0')
        {
            num=StrToIntCore(str,minus);//进入转换函数
        }
    }

    return(int)num;
}

long long StrToIntCore(const char* digit,bool minus)
{
    long long num=0;

    while(*digit!='\0')
    {
        if(*digit>='0' && *digit<='9')
        {
            int flag=minus?-1:1;
            num=num*10+flag*(*digit-'0');

            if((!minus && num>Ox7FFFFFFF) || (minus && num<(signed int)Ox80000000))
            {//超限 提前结束   Ox7FFFFFFF=2147483648   Ox80000000=-2147483648 计算机中采用补码存数
                num=0;
                break;
            }
            digit++;
        }
        else
        {//不是十进制的数 提前结束
            num=0;
            break;
        }
    }

    if(*digit=="\0")//没遇到非法输入
    {
        g_nStatus=kValid;
    }

    return num;
}