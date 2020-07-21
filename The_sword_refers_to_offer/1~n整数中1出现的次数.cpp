//数论问题一般不能用模拟的方法来做，如果能把时间复杂度优化到O(logn)一般就可以了
int NumberOf1Between1AndN(int n)
{//可以在读入的时候就读成字符串 
    if(n<=0)
        return 0;
    
    char strN[50];
    sprintf(strN,"%d",n);//转换成字符串
    return NUmberOf1(strN);
}

int NumberOf1(const char* strN)
{
    if(!strN||*strN<'0'||*strN>'9'||*strN=='\0')
        return 0;//健壮性
    
    int first=*strN-'0';
    unsigned int length=static_cast<unsigned int>(strlen(strN));//???这句是什么意思？？？
    
    if(length==1&&first==0)
        return 0;//数字0
    
    if(length==1&&first>0)
        return 1;//个位数

    int numFirstDigit=0;

    //计算头一位为1时贡献的的数字1个数
    if(first>1)//头一位大于1
        numFirstDigit=PowerBase10(length-1);
    else if(first==1)//头一位等于1
        numFirstDigit=atoi(strN+1)+1;//将字符串转换成整型

//计算其他位上数字1贡献的数字1个数
    int numOtherDigits=first*(length-1)*PowerBase10(length-2);

//按照数字的位数来进行分解问题并进行递归
//例如：12345会被氛围0-5，6-45，46-345，346-2345，2346-12345
    int numRecursive=NumberOf1(strN+1);//用递归的思想来分解问题

    return numFirstDigit+numOtherDigits+numRecursive;
}

int PowerBase10(unsigned int n)
{//计算10的次方
    int result=1;
    for(unsigned int i=0;i<n;i++)
        result*=10;

    return result;
}

























