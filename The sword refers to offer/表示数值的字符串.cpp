bool isNumeric(const char* str)//判断是不是数字
{
    if(str==nullptr)
        return false;
    
    bool numeric=scanInteger(&str);//判断并过滤正负号和数字

    if(*str=='.')//小数部分的处理
    {
        ++str;
//小数点之前或者之后都可以没有数字但不能同时没有数字
        numeric=scanUnsignedInteger(&str) || numeric;
    }
    if(*str=='e' || *str=='E')//指数部分的处理
    {
        ++str;
//e或E前后必须全有数字才能判定为字符串是数字
        numeric=numeric && scanInteger(&str);
    }

    return numeric && *str=='\0';//检查完所有字符串后才能确定字符串是不是代表数字
}


bool scanUnsignedInteger(const char** str)//检查字符**str及其后面有没有数字
{
    const char* before=*str;
    while (**str!='\0' && **str>='0' && **str<='9')
    {
        ++(*str);
    }
    
    return *str>before;//有数字则为真 否则为假
}

bool scanInteger(const char** str)//过滤正负号并检查**str后面有没有数字
{
    if(**str=='+' || **str=='-')
        ++(*str);
    return scanUnsignedInteger(str);//检查字符**str及其后面有没有数字
}
