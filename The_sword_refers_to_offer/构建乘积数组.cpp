//B[i]的值是A数组各元素的累积除以A[i] 题目要求不能使用除法
//B[i]=C[i]*D[i] C[i]=A[0]*A[1]*...*A[i-2]*A[i-1]  D[i]=A[i+1]*A[i+2]*...*A[n-2]*A[n-1]

void multiply(const vector<double>& array1,vector<double>& array2)
{//array1是数组A，array2是数组B
    int length1=array1.szie();
    int length2=array2.size();

    if(length1==length2 && length2>1)
    {
        array2[0]=1;
        for(int i=1;i<length1;i++)
        {//计算C[i]
            array2[i]=array2[i-1]*array1[i-1];
        }

        double temp=1;
        for(int i=length1-2;i>=0;i--)
        {//计算D[i],temp就是D[i]
            temp*=array1[i+1];
            array2[i]*=temp;//最终结果C[i]*D[i]
        }
    }
}
