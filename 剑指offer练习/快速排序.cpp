void QuickSort(int* numbers,int left,int right)
{
    int i,j,base;
    i=left;j=right;
    base=numbers[(i+j)>>1];
    while (i<=j)
    {
        while (numbers[i]<base) i++;
        while (numbers[j]>base) j--;
        if(i<=j)
        {
            swap(numbers[i],numbers[j]);
            i++;
            j--;
        }
        
    }
    if(left<j) QuickSort(numbers,left,j);
    if(right>i) QuickSort(numbers,i,right);
}