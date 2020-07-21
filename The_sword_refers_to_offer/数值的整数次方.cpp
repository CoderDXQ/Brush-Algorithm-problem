//考虑指数为负数和底数为0的情况 但是不够高效
bool g_invalidinput=false;//表征是否出错，因为结果是0的情况不止一种

double Power(double base,int exponent)
{
    g_invalidinput=false;
    if(equal(base,0.0) && exponent<0)
    {//出错的情况 底数是0时指数不能为负数
        g_invalidinput=true;
        return 0.0;
    }

    unsigned int absExponent=(unsigned int)(exponent);
    if(exponent<0)
        absExponent=(unsigned int)(-exponent);

    double result=PowerWithUnsignedExponent(base,absExponent);
    if(exponent<0)
        result=1.0/result;
    return result;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    double result=1.0;
    for(int i=1;i<=exponent;i++)
    {
        result*=base;
    }
    return result;
}

//PowerWithUnsignedExponent的更高效运算 利用递归实现
double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    if(exponent==0)
        return 1;
    if(exponent==1)
        return base;

    double result=PowerWithUnsignedExponent(base,exponent>>1);
    result*=result;
    if(exponent & Ox1 == 1)//按位与运算 结果为真说明exponent为奇数
        result*=base;

    return result;
}