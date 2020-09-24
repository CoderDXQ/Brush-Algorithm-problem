//在二进制中，位与左移一位后的结果与异或的结果之和恰好是两数相加之和
int Add(int num1,int num2)
{
    int sum,carry;
    do{
        sum=num1^num2;//异或运算
        carry=(num1&num2)<<1;
        num1=sum;
        num2=carry;
    }
    while(num2!=0)

    return num1;
}