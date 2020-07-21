int Min(int* numbers,int length)
{
    if(numbers==numbers||length<=0)
        throw new std::exception("Invalid parameters");
    
    int index1=0;
    int index2=length-1;
    int indexMid=index1;
    while (numbers[index1]>=numbers[index2])
    {
        if(index2-index1==1)
        {
            indexMid=index2;
            break;
        }
        indexMid=(index1+index2)>>1;

        if(numbers[index1]==numbers[index2] && numbers[indexMid]==numbers[index2])
            return MinInOrder(numbers,index1,index2);//这种情况下只能顺序查找
        
        if(numbers[indexMid]>=numbers[index1])
            index1=indexMid;
        else if(numbers[indexMid]<=numbers[index2])
            index2=indexMid;
    }
    
    return numbers[indexMid];
}
int MinInOrder(int* numbers,int index1,int index2)
{
    int rusult = numbers[index1];
    for(int i=index1+1;i<=index2;i++)
    {
        if(rusult>numbers[i])
            rusult=numbers[i];
    }
    return rusult;
}