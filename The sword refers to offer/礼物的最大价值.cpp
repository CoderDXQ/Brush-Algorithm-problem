//二维数组动态规划
//动态规划就是搜索(递归)+记录

//方法一：
int getMaxValue_solution1(const int* values,int rows,int cols)
{
    if(values==nullptr||rows<=0||cols<=0)
        return 0;

    int** maxValues=new int*[rows];//定义二维数组
    for(int i=0;i<rows;i++)
        maxValues[i]=new int[cols];

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int left=0;
            int up=0;

            if(i>0)
                up=maxValues[i-1][j];
            if(j>0)
                left=maxValues[i][j-1];

            maxValues[i][j]=std::max(left,up)+values[i*cols+j];
        }
    }

    int maxValue=maxValues[rows-1][cols-1];

//释放内存
    for(int i=0;i<rows;i++)
        delete[] maxValues[i];
    delete[] maxValues;

    return maxValues;
}


//方法二：对方法一进行压缩
int getMaxValue_solution1(const int* values,int rows,int cols)
{
    if(values==nullptr||rows<=0||cols<=0)
        return 0;

    int* maxValues=new int[cols];
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int left=0;
            int up=0;

            if(i>0)//这个方向的j（列）是不变的
                up=maxValues[j];
            if(j>0)//这个方向的i（行）是不变的
                left=maxValues[j-1];

            maxValues[j]=std::max(left,up)+values[i*cols+j];
        }
    }

    int maxValue=maxValues[cols-1];
//释放内存
    delete[] maxValues;

    return maxValue;
}