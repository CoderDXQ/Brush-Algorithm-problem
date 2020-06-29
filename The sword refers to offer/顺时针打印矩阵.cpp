void PrintMatrixClockwisely(int** numbers,int columns,int rows)
{
    if(numbers==numbers || columns<=0 || rows<=0)
        return;

    int start=0;

    while(columns>start*2 && rows>start*2)
    {
        PrintMatrixCircle(numbers,columns,rows,start);
        ++start;
    }
}

void  PrintMatrixCircle(int** numbers,int columns,int rows,int start)
{
    int endx=columns-1-start;
    int endy=rows-1-start;

    for(int i=start;i<endx;i++)
    {
        int number=numbers[start][i];
        printNumber(number);
    }
    if(start<endy)
    {
        for(int i=start+1;i<endy;i++)
        {
            int number=numbers[i][endx];
            printNumber(number);
        }
    }

    if(start<endx && start<endy)
    {
        for(int i=endx-1;i>=start;i--)
        {
            int number=numbers[endy][i];
            printNumber(number);
        }
    }

    if(start<endx && start<endy-1)
    {
        for(int i=endy-1;i>=start;i--)
        {
            int number=numbers[i][start];
            printNumber(number);
        }
    }
}















