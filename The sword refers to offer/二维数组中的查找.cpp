bool Find(int* matrix,int rows,int columns,int number)
{//number是要查找的值
    bool Find=false;

    if(matrix!=nullptr && rows>0 && columns>0)//增强健壮性
    {
        int row=0;
        int column=columns-1;//矩阵下标从0开始 起始位置置于右上角
        //从右上角开始搜索，那么只需要向两个方向移动即可实现查找
        //向下移动是增大 向左移动是减小
        while (row<rows && column>=0)
        {
            if(matrix[row*columns+column]==number)
            {//查得
                found=true;
                break;
            }
            else if(matrix[row*columns+column]>number)
                --column;//所选矩阵的值大于目标值 向左移动
            else //所选矩阵的值小于目标值 向右移动
                ++row;
        }
    }

    return found;
}