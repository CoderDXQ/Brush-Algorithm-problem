//在二进制中，位与左移一位后的结果与异或的结果之和恰好是两数相加之和

//手算的话确实是不用使用循环 不明白这里使用循环是为啥？？？
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