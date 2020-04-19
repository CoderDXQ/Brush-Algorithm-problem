#include<bits/stdc++.h>
using namespace std;

bool hasPath(char* matrix,int rows,int cols,char* str)
{
    if(matrix==nullptr||rows<1||cols<1||str==nullptr)
        return false;

    bool* visited=new bool[rows*cols];//定义一个标记数组，用指针引导使用
    memset(visited,0,rows*cols);//初始化

    int pathLength=0;
    for(int row=0;row<rows;row++)
    {
        for(int col=0;col<cols;col++)
        {
            if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
            {
                return true;
            }
        }
    }
    delete[] visited;//释放内存 防止内存泄漏

    return false;
}

bool hasPathCore(const char* matrix,int rows,int cols,int row,int col,const char* str,int& pathLength,bool* visited)
{//变量后加&代表引用
    if(str[pathLength]=='\0')
        return true;//找全了字符串

    bool hasPath=false;
    if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols+col]==str[pathLength] && !visited[row*cols+col])
    {//符合上述条件则可以走下一步
        ++pathLength;
        visited[row*cols+col]=true;//标记

        hasPath=hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited) 
                ||hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited)
                ||hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited)
                ||hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited);
    
        if(!hasPath)
        {//回溯
            --pathLength;
            visited[row*cols+col]=false;
        }
    }
    
    return hasPath;
}